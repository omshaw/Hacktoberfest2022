#include<bits/stdc++.h>
using namespace std;

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
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return -1;
        int l=kthSmallest(root->left,k);
        if(l!=-1)
            return l;
        if(k==1)
            return root->val;
        k--;
        int r=kthSmallest(root->right,k);
        if(r!=-1)
            return r;
        return -1;        
    }
};
int main()
{
    Solution s=Solution();
    TreeNode* root=new TreeNode();
    root->val=20;
    root->left=new TreeNode();
    root->right=new TreeNode();
    root->left->val=10;
    root->right->val=30;
    root->left->left=new TreeNode();
    root->left->left->val=5;
    root->left->right=new TreeNode();
    root->left->right->val=12;
    cout<<"2nd smallest element is:"<<s.kthSmallest(root,2);
    return 0;
}