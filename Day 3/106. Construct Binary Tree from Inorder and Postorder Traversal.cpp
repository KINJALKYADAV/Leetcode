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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int> & mpp, int instart, int inend, int postin, int postend)
    {
        if(instart>inend || postin>postend)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postend]);
        int inroot = mpp[root->val];
        int right = inroot-instart;
        root->left = build(inorder, postorder, mpp, instart, inroot-1, postin, postin+right-1);
        root->right = build(inorder, postorder, mpp, inroot+1, inend, postin+right, postend-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())
            return NULL;
        int n = inorder.size();
        unordered_map<int, int>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[inorder[i]]=i;
        }
        return build(inorder, postorder, mpp, 0, n-1, 0, postorder.size()-1);
    }
};