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
    int dfs(TreeNode* node, int maxSeen) {
        
        if (node == nullptr) {
            return 0;
        }

        int count = 0;

        if (node->val >= maxSeen) {
            count = 1;
        }

        maxSeen = max(maxSeen, node->val);

        count += dfs(node->left, maxSeen);
        count += dfs(node->right, maxSeen);

        return count;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};