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

    bool flag = true;

    void dfs(TreeNode* node, long long lower, long long upper) {
        if(node == NULL) {
            return;
        }

        if(lower < node -> val && node -> val < upper) {
            dfs(node -> left, lower, node -> val);
            dfs(node -> right, node -> val, upper);
        }
        else {
            flag = false;
        }
    }

    bool isValidBST(TreeNode* root) {
        long long lower = LLONG_MIN;
        long long upper = LLONG_MAX;
        dfs(root, lower, upper);

        return flag;
    }
};
