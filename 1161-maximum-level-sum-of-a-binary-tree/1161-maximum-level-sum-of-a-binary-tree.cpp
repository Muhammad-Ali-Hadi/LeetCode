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
    int maxLevelSum(TreeNode* root) {
        fast;

        int level=1;
        int maxSum=root->val;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            bool invalid=false;
            for(int i=0;i<size;++i)
            {
                TreeNode* node=q.front();
                q.pop();

                if(node->left && node->left->val+maxSum>=maxSum)
                {
                    maxSum+=node->left->val;
                }
                else if(node->left)
                {
                    invalid=true;
                }

                if(node->right && node->right->val+maxSum>=maxSum)
                {
                    maxSum+=node->right->val;
                }
                else if(node->right)
                {
                    invalid=true;
                }

                if(invalid)
                break;
                else
                level++;

                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            if(invalid)
            break;
        }
        return level;
    }
};