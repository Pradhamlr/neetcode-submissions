/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    string s;
    queue<string> q;
    void serialHelper(TreeNode* node) {
        if(node == NULL) {
            s += "N,";
            return;
        }

        s += to_string(node -> val) + ",";

        serialHelper(node -> left);
        serialHelper(node -> right);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        serialHelper(root);

        return s;
    }

    TreeNode* deserializeHelper() {
        string rootVal = q.front();
        q.pop();

        if(rootVal == "N") {
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(rootVal));

        root -> left = deserializeHelper();
        root -> right = deserializeHelper();

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string temp = "";

        for(auto &it: data) {
            if(it == ',') {
                q.push(temp);
                temp = "";
            }
            else {
                temp += it;
            }
        }

        TreeNode* root = deserializeHelper();
        return root;
    }
};
