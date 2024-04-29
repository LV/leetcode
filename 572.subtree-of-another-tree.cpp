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
    bool isEquivalent(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        return p->val == q->val && isEquivalent(p->left, q->left) && isEquivalent(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;

        TreeNode* root_copy = root;
        TreeNode* subroot_copy = subRoot;
        return isEquivalent(root_copy, subroot_copy) ? true : isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    // TODO: Improve 14% percentile in speed
};
// @leet end
