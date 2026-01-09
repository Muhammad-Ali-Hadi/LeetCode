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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        fast;

        if(!root)
        return root;

        int maxDepth=0;
        TreeNode* lca=nullptr;

        function<int(TreeNode*,int)>dfs=[&dfs,&maxDepth,&lca](TreeNode* root,int depth)->int{
            maxDepth=max(maxDepth,depth);
            if(!root)
            return depth;

            int l=dfs(root->left,depth+1);
            int r=dfs(root->right,depth+1);

            if(l==maxDepth && r==maxDepth)
            lca=root;
            return max(l,r);
        };

        dfs(root,0);
        return lca;
    }
};