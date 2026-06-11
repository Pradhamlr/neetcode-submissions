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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;

        ListNode* temp = head;

        while(temp != NULL) {
            temp = temp -> next;
            length++;
        }

        int position = length - n;

        ListNode* curr = head;
        ListNode* prev = NULL;

        int i = 0;
        if(position == 0) {
            return head -> next;
        }
        while(i < position) {
            prev = curr;
            curr = curr -> next;
            i++;
        }

        ListNode* temp1 = curr -> next;
        prev -> next = temp1;

        return head;
    }
};
