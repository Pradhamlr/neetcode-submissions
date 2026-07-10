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

    int answer = INT_MIN;

    int maxPath(TreeNode* node) {
        if(node == NULL) {
            return 0;
        }
        int left = maxPath(node -> left);
        if(left < 0) {
            left = 0;
        }

        int right = maxPath(node -> right);
        if(right < 0) {
            right = 0;
        }

        answer = max(answer, left + node -> val + right);

        return node -> val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maxPath(root);

        return answer;
    }
};
