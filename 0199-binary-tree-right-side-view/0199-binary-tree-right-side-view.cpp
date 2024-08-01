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
    void helper(TreeNode* root,vector<int>& nums,int level)
    {
        if(root==nullptr)
        return;
        if(level==nums.size())
        nums.push_back(root->val);
        helper(root->right,nums,level+1);
        helper(root->left,nums,level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> nums;
        if(root==nullptr)
        return nums;
        helper(root,nums,0);
        return  nums;
    }
};