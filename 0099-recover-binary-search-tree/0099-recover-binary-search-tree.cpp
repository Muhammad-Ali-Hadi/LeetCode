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
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        function<void(TreeNode*)>dfs=[&](TreeNode* root)->void
        {
            if(!root)
            return;

            dfs(root->left);
            nums.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);

        vector<int> sortedNums=nums;
        int index=0;
        sort(sortedNums.begin(),sortedNums.end());

        function<void(TreeNode*)>recover=[&](TreeNode* root)->void
        {
            if(!root)
            return;

            recover(root->left);
            if(root->val!=sortedNums[index])
            {
                root->val=sortedNums[index];
            }
            ++index;
            recover(root->right);
        };
        recover(root);
    }
};