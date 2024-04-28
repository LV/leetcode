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
    bool isEquivalentTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        return p->val == q->val && isEquivalentTree(p->left, q->left) && isEquivalentTree(p->right, q->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        if(!root) return;
        TreeNode* copy = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(copy);
        return root;
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        invertTree(root->right);
        return isEquivalentTree(root->left, root->right);
    }
};
// @leet end
