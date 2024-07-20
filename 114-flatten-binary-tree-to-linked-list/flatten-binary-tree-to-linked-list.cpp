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
    void solve(TreeNode* temp, vector<TreeNode*>& arr){
        if(!temp){
            return;
        }
        arr.push_back(temp);
        solve(temp->left, arr);
        solve(temp->right, arr);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> arr;
        if(root == NULL){
            return;
        }
        solve(root, arr);
        root = arr[0];
        

        for(int i=1 ; i<arr.size() ; i++){
            TreeNode* temp = arr[i];
            root->right = arr[i];
            root->left = NULL;
            root = root->right;
        }

    }
};