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
    struct NodeInfo {
        int height;
        int diameter;
    };

    NodeInfo getNodeInfo(TreeNode* root) {
        if(!root) return {-1, -1};
        NodeInfo left = getNodeInfo(root->left);
        NodeInfo right = getNodeInfo(root->right);
        int height = max(left.height, right.height) + 1;
        int diameter = max({left.height + right.height, left.diameter, right.diameter, 0});
        return {height, diameter};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        NodeInfo info = getNodeInfo(root);
        return info.diameter;
    }
};
// @leet end
