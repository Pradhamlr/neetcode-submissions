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

    bool isEquals(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) {
            return true;
        }
        if(p == NULL || q == NULL) {
            return false;
        }
        if(p -> val != q -> val) {
            return false;
        }

        bool left = isEquals(p -> left, q -> left);
        bool right = isEquals(p -> right, q -> right);

        return left && right;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) {
            return false;
        }

        if(isEquals(root, subRoot)) {
            return true;
        }

        bool left = isSubtree(root -> left, subRoot);
        bool right = isSubtree(root -> right, subRoot);

        return left || right;
    }
};
