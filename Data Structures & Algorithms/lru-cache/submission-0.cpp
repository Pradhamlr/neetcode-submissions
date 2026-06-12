class Node
{
public:
    int key;
    int value;

    Node* prev;
    Node* next;

    Node(int k, int v)
    {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:

    int cap;
    unordered_map<int, Node*> mpp;
    
    Node* left;
    Node* right;

    LRUCache(int capacity) {
        cap = capacity;

        left = new Node(0, 0);
        right = new Node(0, 0);

        left -> next = right;
        right -> prev = left;
    }
    
    int get(int key) {
        if(!mpp.count(key)) {
            return -1;
        }
        Node* temp = mpp[key];
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;

        Node* last = right -> prev;

        last -> next = temp;
        temp -> prev = last;

        right -> prev = temp;
        temp -> next = right;

        return temp -> value;
        
    }
    
    void put(int key, int value) {
        if(mpp.count(key)) {
            Node* temp = mpp[key];
            temp -> value = value;
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;

            Node* last = right -> prev;

            last -> next = temp;
            temp -> prev = last;

            right -> prev = temp;
            temp -> next = right;
            return;
        }
        
        Node* newNode = new Node(key, value);
        if(mpp.size() < cap) {
            mpp[key] = newNode;
            Node* last = right -> prev;

            last -> next = newNode;
            newNode -> prev = last;

            newNode -> next = right;
            right -> prev = newNode;
        }
        
        else {
            Node* first = left -> next;
            first -> prev -> next = first -> next;
            first -> next -> prev = first -> prev;
            mpp.erase(first -> key);

            mpp[key] = newNode;
            Node* last = right -> prev;

            last -> next = newNode;
            newNode -> prev = last;

            newNode -> next = right;
            right -> prev = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */