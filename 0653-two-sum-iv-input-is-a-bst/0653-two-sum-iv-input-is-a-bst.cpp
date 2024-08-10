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
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> q;
        unordered_set<int> seen;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();

            if(seen.count(k-node->val))
            return true;

            seen.insert(node->val);

            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
        }
        return false;
    }
};