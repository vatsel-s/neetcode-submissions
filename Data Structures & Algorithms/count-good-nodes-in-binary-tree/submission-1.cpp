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
    int goodNodes(TreeNode* root) {
        return getNodes(root, -1000); 
    }

    int getNodes(TreeNode* root, int highest)
    {
        if(root == NULL)
        {
            return 0; 
        } 
        else 
        {
            if(root->val >= highest)
            {
                return 1 + getNodes(root->left, root->val) + getNodes(root->right, root->val); 
            }
            else 
            {
                return getNodes(root->left, highest) + getNodes(root->right, highest); 
            }
        }
    }
};
