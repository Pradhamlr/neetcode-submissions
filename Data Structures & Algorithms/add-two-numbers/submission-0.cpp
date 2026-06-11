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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = l1;
        ListNode* second = l2;
        int carry = 0;

        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        while(first || second || carry) {
            int val1 = first? first -> val: 0;
            int val2 = second? second -> val: 0;

            int sum = val1 + val2 + carry;
            carry = sum/10;

            ListNode* newNode = new ListNode(sum%10);
            tail -> next = newNode;
            tail = newNode;

            if(first) {
                first = first -> next;
            }
            if(second) {
                second = second -> next;
            }
        }

        return dummy -> next;
    }
};
