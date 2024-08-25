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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr)
        return {};

        if(root->left==nullptr && root->right==nullptr)
        return {root->val};

        queue<TreeNode*> q;
        q.push(root);
        stack<TreeNode*> st;
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();

            st.push(node);
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
        }

        vector<int> nums;
        while(!st.empty())
        {
            nums.push_back(st.top()->val);
            st.pop();
        }
        return nums;
    }
};