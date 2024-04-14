// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;

        const int rootVal = root->val;
        const int pVal = p->val;
        const int qVal = q->val;
        if(rootVal == pVal || rootVal == qVal) return root;
        if(pVal < rootVal && qVal > rootVal) return root;
        if(pVal > rootVal && qVal < rootVal) return root;
        if(pVal < rootVal && qVal < rootVal) return lowestCommonAncestor(root->left, p, q);
        else return lowestCommonAncestor(root->right, p, q);
    }
};
// @leet end
