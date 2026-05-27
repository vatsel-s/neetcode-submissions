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
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root == NULL)
        {
            vector<int> val; 
            return val; 
        }
        vector<int> answer; 
        vector<TreeNode*> queue; 
        queue.push_back(root); 
        while(queue.size() != 0)
        {
            answer.push_back(queue[queue.size() -1]->val);
            vector<TreeNode*> newQueue; 
            for(int i = 0; i < queue.size(); i++)
            {
                if(queue[i]->left != NULL)
                {
                    newQueue.push_back(queue[i]->left);
                }
                if(queue[i]->right != NULL)
                {
                    newQueue.push_back(queue[i]->right); 
                }
            }
            queue = newQueue; 
        }
        return answer; 
    }
};
