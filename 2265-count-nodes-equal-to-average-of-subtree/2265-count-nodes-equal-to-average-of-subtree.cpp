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
    pair<int,int> dfs(TreeNode* root,int& result)
    {
        if(!root)
        return {0,0};

        auto left=dfs(root->left,result);
        auto right=dfs(root->right,result);

        int sum=root->val+left.first+right.first;
        int count=1+left.second+right.second;

        if(root->val==sum/count)
        ++result;

        return {sum,count};
    }

    int averageOfSubtree(TreeNode* root) {
        int result=0;
        dfs(root,result);
        return result;
    }
};