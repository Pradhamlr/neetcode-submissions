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

    int count = 0;

    void dfs(TreeNode* node, int maxSeen) {
        if(node == NULL) {
            return;
        }

        if(node -> val >= maxSeen) {
            count++;
        }

        maxSeen = max(maxSeen, node -> val);

        dfs(node -> left, maxSeen);
        dfs(node -> right, maxSeen);
    }

    int goodNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int maxSeen = root -> val;
        dfs(root, maxSeen);

        return count;
    }
};
