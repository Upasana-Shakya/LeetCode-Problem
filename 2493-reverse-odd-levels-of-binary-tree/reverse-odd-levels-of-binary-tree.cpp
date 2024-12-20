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
    void dfs(TreeNode* rleft, TreeNode* rright, int l){
        if(!rleft || !rright){
            return;
        }

        if(l % 2 == 0){
            int temp = rleft->val;
            rleft->val = rright->val;
            rright->val = temp;
        }

        dfs(rleft->left, rright->right, l+1);
        dfs(rright->left, rleft->right, l+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 0);
        return root;
    }
};