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

    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder, int n, int &postIndex, int inStart, int inEnd){
        if(postIndex < 0 || inStart > inEnd){
            return NULL;
        }

        int ele = postorder[postIndex--];
        TreeNode* root = new TreeNode(ele);
        int pos = position(inorder, ele);

        root->right = buildTree(postorder, inorder, n, postIndex, pos+1, inEnd);
        root->left = buildTree(postorder, inorder, n, postIndex, inStart, pos-1);

        return root;
    } 
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
         int postIndex = n-1;
        
        return buildTree(postorder, inorder, n, postIndex, 0, n-1);
    }
};