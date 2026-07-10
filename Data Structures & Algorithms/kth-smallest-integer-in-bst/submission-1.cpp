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

class Solution {
public:

    int answer;
    int count = 0;

    void inorder(TreeNode* node, int k) {
        if(node == NULL) {
            return;
        }

        inorder(node -> left, k);
        count++;
        if(count == k) {
            answer = node -> val;
            return;
        }
        inorder(node -> right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);

        return answer;
    }
};
