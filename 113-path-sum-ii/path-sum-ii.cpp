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
    void solve(TreeNode* root , int target, vector<vector<int>> &res, vector<int> temp){
        if(!root) return;
        if(!root->left && !root->right){
            temp.push_back(root->val);
            target -= root->val;
            if(target == 0){
                res.push_back(temp);
            }
            return;
        }
        temp.push_back(root->val);

        solve(root->left, target-root->val, res, temp);
        solve(root->right, target-root->val, res, temp);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(root, targetSum, res, temp);

        return res;
    }
};