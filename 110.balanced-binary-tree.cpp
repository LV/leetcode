// @leet start
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
    // returns the height of the tree
    int treeHeight(TreeNode* tree) {
        if(!tree) return 0;
        return 1+max(treeHeight(tree->left), treeHeight(tree->right));
    }


    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(treeHeight(root->left)-treeHeight(root->right))<=1) {
        return false;
    }
};
// @leet end
