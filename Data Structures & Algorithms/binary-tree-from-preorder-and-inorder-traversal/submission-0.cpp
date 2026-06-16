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

    unordered_map<int ,int> mpp;
    vector<int> preorderInput;

    TreeNode* build(int preStart, int preEnd, int inStart, int inEnd) {
        if(preStart > preEnd) {
            return NULL;
        }

        int rootVal = preorderInput[preStart];

        TreeNode* root = new TreeNode(rootVal);

        int mid = mpp[rootVal];
        int leftSize = mid - inStart;

        root -> left = build(preStart + 1, preStart + leftSize, inStart, mid - 1);

        root -> right = build(preStart + leftSize + 1, preEnd, mid + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderInput = preorder;

        for(int i = 0; i < inorder.size(); i++)  {
            mpp[inorder[i]] = i;
        }

        TreeNode* root = build(0, preorder.size() - 1, 0, inorder.size() - 1);

        return root;
    }
};