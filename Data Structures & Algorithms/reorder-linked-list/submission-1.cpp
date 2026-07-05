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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* second = slow -> next;
        slow -> next = NULL;
        ListNode* prev = NULL;

        while(second != NULL) {
            ListNode* temp = second -> next;
            second -> next = prev;
            prev = second;
            second = temp;
        }

        ListNode* front = head;

        while(prev != NULL) {
            ListNode* temp1 = front -> next;
            front -> next = prev;
            front = temp1;
            ListNode* temp2 = prev -> next;
            prev -> next = front;
            prev = temp2;
        }
    }
};
