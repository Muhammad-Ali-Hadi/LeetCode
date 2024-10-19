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
    bool isValidBST(TreeNode* root) {
        if(root==nullptr || (root->left==nullptr && root->right==nullptr))
        return true;

        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{INT_MIN,INT_MAX}});
        while(!q.empty())
        {
            auto nodePair=q.front();
            q.pop();

            TreeNode* node=nodePair.first;

            int minValue=nodePair.second.first;
            int maxValue=nodePair.second.second;

            if(node->val<=minValue || node->val>=maxValue)
            return false;

            if(node->left)
            q.push({node->left,{minValue,node->val}});
            if(node->right)
            q.push({node->right,{node->val,maxValue}});
        }
        return true;
    }
};