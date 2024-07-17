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
    TreeNode* deleteNodes(TreeNode* node,unordered_set<int>& set,vector<TreeNode*>& trees)
    {
        if(!node)
        return nullptr;

        node->left=deleteNodes(node->left,set,trees);
        node->right=deleteNodes(node->right,set,trees);

        if(set.count(node->val))
        {
            if(node->left)
            trees.push_back(node->left);
            if(node->right)
            trees.push_back(node->right);
            delete node;
            return nullptr;
        }
        return node;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> trees;
        unordered_set<int> set(to_delete.begin(),to_delete.end());
        if(!set.count(root->val))
        {
            trees.push_back(root);
        }
        deleteNodes(root,set,trees);
        return trees;
    }
};