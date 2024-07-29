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
    void helper(TreeNode* root,vector<int>& nums)
    {
        if(root==nullptr)
        return;
        nums.push_back(root->val);
        helper(root->left,nums);
        helper(root->right,nums);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nums;
        helper(root1,nums);
        helper(root2,nums);
        sort(nums.begin(),nums.end());
        return nums;
    }
};