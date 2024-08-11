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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        function<void(TreeNode*)>dfs=[&](TreeNode* root)->void
        {
            if(root==nullptr)
            return;

            dfs(root->left);
            nums.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);
        return nums[k-1];
    }
};