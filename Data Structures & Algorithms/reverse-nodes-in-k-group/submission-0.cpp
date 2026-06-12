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

    ListNode* getKthElement(ListNode* prevGroup, int k) {
        while(prevGroup != NULL && k > 0) {
            prevGroup = prevGroup -> next;
            k--;
        }

        return prevGroup;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* prevGroupTail = dummy;

        while(true) {
            ListNode* kth = getKthElement(prevGroupTail, k);

            if(kth == NULL) {
                break;
            }

            ListNode* temp = prevGroupTail;
            ListNode* nextGroup = kth -> next;

            ListNode* curr = prevGroupTail -> next;
            ListNode* prev = nextGroup;

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