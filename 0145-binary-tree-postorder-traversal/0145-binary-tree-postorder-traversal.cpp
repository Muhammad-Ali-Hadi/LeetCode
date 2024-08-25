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

        stack<TreeNode*> st1;
        st1.push(root);
        stack<TreeNode*> st2;
        while(!st1.empty())
        {
            TreeNode* node=st1.top();
            st1.pop();

            st2.push(node);
            if(node->left)
            st1.push(node->left);
            if(node->right)
            st1.push(node->right);
        }

        vector<int> nums;
        while(!st2.empty())
        {
            nums.push_back(st2.top()->val);
            st2.pop();
        }
        return nums;
    }
};