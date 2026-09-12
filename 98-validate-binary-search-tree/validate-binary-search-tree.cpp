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
    int check(TreeNode* node,long long minValue, long long maxValue){
        if(node==NULL){
            return true;
        }
        if(node->val <= minValue || node->val >= maxValue){
            return false;
        }
        return check(node->left,minValue,node->val) && check(node->right,node->val,maxValue);
    }
    bool isValidBST(TreeNode* root) {
       
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};