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
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty())
        {
            TreeNode* node=qu.front();
            qu.pop();

            if((node->left==p && node->right==q) || (node->left==q && node->right==p))
            return node;
            if((node==p && node->right==q) || (node==q && node->left==p) || (node==p && node->left==q) || (node==q && node->right==p))
            return node;
            if(node->left)
            qu.push(node->left);
            if(node->right)
            qu.push(node->right);
        }
        return nullptr;
    }
};