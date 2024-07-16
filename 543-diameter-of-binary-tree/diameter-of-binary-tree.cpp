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
    int height(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        return max(height(node->left), height(node->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftHeight = diameterOfBinaryTree(root->left);
        int rightHeight = diameterOfBinaryTree(root->right);
        int includingRoot = height(root->left)+height(root->right);

        return max(includingRoot, max(leftHeight, rightHeight));
    }
};