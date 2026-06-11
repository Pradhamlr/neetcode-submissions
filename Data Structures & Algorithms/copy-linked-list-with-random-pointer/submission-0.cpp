/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mpp;

        Node* curr = head;

        while(curr != NULL) {
            mpp[curr] = new Node(curr -> val);
            curr = curr -> next;
        }

        Node* curr1 = head;
        while(curr1 != NULL) {
            mpp[curr1] -> next = mpp[curr1 -> next];

            mpp[curr1] -> random = mpp[curr1 -> random];

            curr1 = curr1 -> next;
        }

        Node* curr2 = head;

        return mpp[head];
    }
};
