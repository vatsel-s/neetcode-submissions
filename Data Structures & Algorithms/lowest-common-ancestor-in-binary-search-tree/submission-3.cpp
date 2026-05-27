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
#include <unordered_set>
#include <iostream>
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::unordered_set<int> pSet;  
        std::unordered_set<int> qSet; 
        find(root, p, pSet); 
        find(root, q, qSet); 
        return findLCA(pSet, qSet, root); 
    }

    TreeNode* findLCA(unordered_set<int>pSet, unordered_set<int>qSet, TreeNode* root)
    {
        if(root->left == NULL && root->right == NULL)
        {
            return root; 
        }
        else if(root->left == NULL)
        {
            bool bothRight = (pSet.find(root->right->val) != pSet.end() && qSet.find(root->right->val) != qSet.end());
            if(bothRight)
            {
                return findLCA(pSet, qSet, root->right);
            } 
            else 
            {
                return root; 
            }
        }
        else if(root->right == NULL)
        {
            bool bothLeft = (pSet.find(root->left->val) != pSet.end() && qSet.find(root->left->val) != qSet.end());
            if(bothLeft)
            {
                return findLCA(pSet, qSet, root->left); 
            }
            else 
            {
                return root;
            }

        }
        else 
        {
            bool bothLeft = (pSet.find(root->left->val) != pSet.end() && qSet.find(root->left->val) != qSet.end());
            bool bothRight = (pSet.find(root->right->val) != pSet.end() && qSet.find(root->right->val) != qSet.end());
            if(bothLeft == false && bothRight == false)
            {
                return root; 
            }
            else if(bothLeft)
            {
                return findLCA(pSet, qSet, root->left); 
            }
            else 
            {
                return findLCA(pSet, qSet, root->right); 
            }
        }
    }

    void find(TreeNode* root, TreeNode* found, std::unordered_set<int>& set)
    {
        set.insert(root->val); 
        if(root->val == found->val)
        {
            return; 
        }
        else if(root->val > found->val)
        {
            find(root->left, found, set); 
        }
        else 
        {
            find(root->right, found, set); 
        }
    }
};
