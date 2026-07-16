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
    int kthSmallest(TreeNode* root, int k) {
     vector<int>temp(2);
     temp[0]=k;
     dfs(root,temp);
     return temp[1];   
    }

    void dfs(TreeNode* node, vector<int>&temp){
        if(!node)return;
        dfs(node->left,temp);
        temp[0]--;
        if(temp[0]==0){
            temp[1]=node->val;
            return;
        }
        dfs(node->right,temp);
    }
};
