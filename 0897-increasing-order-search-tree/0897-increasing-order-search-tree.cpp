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
    void helper(TreeNode* root,TreeNode* &order)
    {
        if(root==nullptr)
        return;
        helper(root->left,order);
        if(order==nullptr)
        order=new TreeNode(root->val);
        else
        {
            TreeNode* ptr=order;
            while(ptr->right!=nullptr)
            {
                ptr=ptr->right;
            }
            ptr->right=new TreeNode(root->val);
        }
        helper(root->right,order);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* order=nullptr;
        helper(root,order);
        return order;
    }
};