class Solution {
public:

    void buildParentMap(
        TreeNode* root,
        unordered_map<TreeNode*, TreeNode*>& parent
    ) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* current = q.front();
            q.pop();

            if (current->left) {
                parent[current->left] = current;
                q.push(current->left);
            }

            if (current->right) {
                parent[current->right] = current;
                q.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parent;

        // Step 1: Build parent mapping
        buildParentMap(root, parent);

        // Step 2: BFS from target
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int distance = 0;

        while (!q.empty()) {

            int size = q.size();

            if (distance == k) {
                break;
            }

            for (int i = 0; i < size; i++) {

                TreeNode* current = q.front();
                q.pop();

                if (current->left && !visited.count(current->left)) {
                    q.push(current->left);
                    visited.insert(current->left);
                }

                if (current->right && !visited.count(current->right)) {
                    q.push(current->right);
                    visited.insert(current->right);
                }

                if (parent.count(current) && !visited.count(parent[current])) {
                    q.push(parent[current]);
                    visited.insert(parent[current]);
                }
            }

            distance++;
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};