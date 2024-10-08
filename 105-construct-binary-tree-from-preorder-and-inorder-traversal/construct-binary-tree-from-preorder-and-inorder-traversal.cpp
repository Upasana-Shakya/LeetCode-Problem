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
    int position(vector<int>& arr, int target){
        for(int i=0 ; i<arr.size() ; i++){
            if(arr[i] == target){
                return i;
            }
        }
        return -1;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int n, int &preIndex, int inStart, int inEnd){
        if(preIndex >= n || inStart > inEnd){
            return NULL;
        }

        int ele = preorder[preIndex++];
        TreeNode* root = new TreeNode(ele);
        int pos = position(inorder, ele);

        root->left = buildTree(preorder, inorder, n, preIndex, inStart, pos-1);
        root->right = buildTree(preorder, inorder, n, preIndex, pos+1, inEnd);

        return root;
    } 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        int n = inorder.size();
        
        return buildTree(preorder, inorder, n, preIndex, 0, n-1);
    }
};