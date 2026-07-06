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
        ListNode* dummy = new ListNode();
        ListNode* node = dummy;

        int carry = 0;
        int digit = 0;

        while(l1 != NULL || l2 != NULL || carry != 0) {
            int val1;
            int val2;
            if(l1) {
                val1 = l1 -> val;
            }
            else {
                val1 = 0;
            }
            if(l2) {
                val2 = l2 -> val;
            }
            else {
                val2 = 0;
            }
            int sum = val1 + val2 + carry;

            digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            node -> next = newNode;
            node = newNode;

            if(l1) {
                l1 = l1 -> next;
            }

            if(l2) {
                l2 = l2 -> next;
            }
        }

        return dummy -> next;
    }
};
