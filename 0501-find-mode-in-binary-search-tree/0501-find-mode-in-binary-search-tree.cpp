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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        function<void(TreeNode*)>dfs=[&](TreeNode* root)->void
        {
            if(root==nullptr)
            return;

            dfs(root->left);
            mp[root->val]++;
            dfs(root->right);
        };
        dfs(root);
        int maxFreq=-1;
        for(auto& num : mp)
        {
            maxFreq=(num.second>maxFreq) ? num.first : maxFreq;
        }
        return {maxFreq};
    }
};