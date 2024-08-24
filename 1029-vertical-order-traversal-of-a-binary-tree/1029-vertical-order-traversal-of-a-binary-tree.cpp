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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to hold nodes based on horizontal and vertical distances
        map<int, map<int, multiset<int>>> nodes;
        // Queue to hold nodes and their positions
        queue<pair<TreeNode*, pair<int, int>>> todo;

        // Initialize with the root node
        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* temp = p.first;
            int x = p.second.first;  // Horizontal distance
            int y = p.second.second; // Vertical distance

            nodes[x][y].insert(temp->val);

            // Move to the left child
            if (temp->left) {
                todo.push({temp->left, {x - 1, y + 1}});
            }

            // Move to the right child
            if (temp->right) {
                todo.push({temp->right, {x + 1, y + 1}});
            }
        }

        // Prepare the final result vector
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};
