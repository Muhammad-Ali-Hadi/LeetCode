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
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr)

class Solution {
public:
    int maxProduct(TreeNode* root) {
        fast;

        long long ans=0,tot=0;

        const int MOD=1e9+7;
        function<long long(TreeNode*)>sum=[&sum](TreeNode* root)->long long{
            return !root ? 0 : root->val+sum(root->left)+sum(root->right);
        };

        function<long long(TreeNode*)>dfs=[&](TreeNode* root)->long long{
            if(!root)
            return 0;

            long long s=root->val+dfs(root->left)+dfs(root->right);
            ans=max(ans,s*(tot-s));
            return s;
        };

        tot=sum(root);
        dfs(root);
        return ans%MOD;
    }
};