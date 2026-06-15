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

    void find(TreeNode* root, int maxSeen) {
        if(root == NULL) {
            return;
        }

        if(root -> val >= maxSeen) {
            count++;
        }

        maxSeen = max(maxSeen, root -> val);

        find(root -> left, maxSeen);
        find(root -> right, maxSeen);
        
    }

    int goodNodes(TreeNode* root) {
        int maxSeen = root -> val;
        find(root, maxSeen);

        return count;
    }
};