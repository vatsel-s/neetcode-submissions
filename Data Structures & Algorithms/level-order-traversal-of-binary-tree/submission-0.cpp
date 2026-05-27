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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; 
        if(root == NULL)
        {
            return result; 
        }
        vector<TreeNode*> queue; 
        queue.push_back(root); 
        while(queue.size() != 0)
        {
            vector<int> nums; 
            vector<TreeNode*> temp;  
            for(int i = 0; i < queue.size(); i++)
            {
                TreeNode* curr = queue[i]; 
                nums.push_back(curr->val); 
                if(curr->left != NULL)
                {
                    temp.push_back(curr->left); 
                }
                if(curr->right != NULL)
                {
                    temp.push_back(curr->right); 
                }
            }
            result.push_back(nums); 
            queue = temp; 
        }
        return result; 
    }
};
