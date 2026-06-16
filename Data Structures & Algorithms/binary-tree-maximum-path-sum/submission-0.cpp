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

    int maxPath = INT_MIN;

    int calculate(TreeNode* node) {
        if(node == NULL) {
            return 0;
        }

        int left = calculate(node -> left);
        if(left < 0) {
            left = 0;
        }
        int right = calculate(node -> right);
        if(right < 0) {
            right = 0;
        }

        maxPath = max(maxPath, left + node -> val + right);

        return node -> val + max(left, right);

    }

    int maxPathSum(TreeNode* root) {
        calculate(root);

        return maxPath;
    }
};