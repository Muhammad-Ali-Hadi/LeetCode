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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        vector<int> nums;
        function<void(TreeNode*)>dfs=[&](TreeNode* root)->void
        {
            if(root==nullptr)
            return;

            nums.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);

        TreeNode* newRoot=nullptr;
        function<TreeNode*(TreeNode*,int)>insert=[&](TreeNode* root,int val)->TreeNode*
        {
            if(root==nullptr)
            {
                TreeNode* n=new TreeNode(val);
                root=n;
                return root;
            }

            if(val<root->val)
            root->left=insert(root->left,val);
            else if(val>root->val)
            root->right=insert(root->right,val);

            return root;
        };

        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]>=low && nums[i]<=high)
            newRoot=insert(newRoot,nums[i]);
        }
        return newRoot;
    }
};