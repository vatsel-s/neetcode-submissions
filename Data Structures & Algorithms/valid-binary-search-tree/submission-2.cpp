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
//can't go just value by value, have to set a min and a max
//can put the min arbritraily low to start and put the max arbritrarily high
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        return validBST(root, -1000, 1000); 
    }
    bool validBST(TreeNode* root, int min, int max)
    {
        if(root == NULL)
        {
            return true; 
        }
        else
        {
            if(root->val <= min || root->val >= max)
            {
                return false; 
            }
            else 
            {
                bool left = validBST(root->left, min, root->val); 
                bool right = validBST(root->right, root->val, max); 
                return left && right; 
            }
        }
    }
};
