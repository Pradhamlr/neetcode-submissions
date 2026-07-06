/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    ListNode* getKth(ListNode* node, int k) {
        while(node != NULL && k > 0) {
            node = node -> next;
            k--;
        }

        return node;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* prevGroupTail = dummy;

        while(true) {
            ListNode* kth = getKth(prevGroupTail, k);
            if(kth == NULL) {
                break;
            }
            ListNode* nextGroup = kth -> next;
            ListNode* prev = nextGroup;

            ListNode* curr = prevGroupTail -> next;
            while(curr != nextGroup) {
                ListNode* temp = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* oldHead = prevGroupTail -> next;
            prevGroupTail -> next = kth;
            prevGroupTail = oldHead;
        }

        return dummy -> next;
    }
};
