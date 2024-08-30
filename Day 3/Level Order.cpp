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
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()!=0)
        {
            int size = q.size();
            vector<int> arr;
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                arr.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
            }
            ans.push_back(arr);
        }
        return ans;

    }
};