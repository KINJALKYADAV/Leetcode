/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
 #include<bits/stdc++.h>
class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int instart,
                    int inend, int prestart, int preend, unordered_map<int, int>& mpp) {
                        if(instart>inend || prestart>preend)
                            return NULL;
                        
                        TreeNode* temp = new TreeNode(preorder[prestart]);
                        int inroot = mpp[temp->val];
                        int left = inroot-instart;
                        
                        temp->left = build(preorder, inorder, instart, inroot-1, prestart+1, prestart+left, mpp);
                        temp ->right = build(preorder, inorder, inroot+1, inend, prestart+left+1, preend, mpp);
                        
                        return temp;

                    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!= inorder.size())
            return NULL;
        unordered_map <int, int> mpp;
        int n = inorder.size();
        for(int i=0;i<n;i++)
        {
            mpp[inorder[i]]=i;
        }
        return build(preorder, inorder, 0,n-1,0,n-1, mpp );
    }
};