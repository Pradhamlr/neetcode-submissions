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

        Node* temp = head;

        while(temp != NULL) {
            mpp[temp] = new Node(temp -> val);
            temp = temp -> next;
        }

        Node* node = head;

        while(node != NULL) {
            mpp[node] -> next = mpp[node -> next];
            mpp[node] -> random = mpp[node -> random];
            node = node -> next;
        }

        return mpp[head];
    }
};
