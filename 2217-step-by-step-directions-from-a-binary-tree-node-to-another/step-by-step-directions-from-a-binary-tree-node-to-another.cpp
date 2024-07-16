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
    TreeNode* lowestCommonAncenster(TreeNode* root, int src,int dest){
        if(!root){
            return NULL;
        }
        if(root->val==src || root->val==dest){
            return root;
        }

        TreeNode* l=lowestCommonAncenster(root->left,src,dest);
        TreeNode* r=lowestCommonAncenster(root->right,src,dest);

        if(l && r){
            return root;
        }
        return l ? l : r;
    }

    bool findPath(TreeNode* LCA, int target, string& path){
        if(LCA==NULL) return false;

        if(LCA->val==target) return true;

        // explore in left
        path.push_back('L');
        if(findPath(LCA->left,target,path)==true) return true;
        path.pop_back(); // backtrack

        // explore in right:
        path.push_back('R');
        if(findPath(LCA->right,target,path)==true) return true;
        path.pop_back(); // backtrack

        return false;


    }
    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode* LCA= lowestCommonAncenster(root,startValue,destValue);

        string lcaTosrc="";
        string lcaTodest="";

        findPath(LCA,startValue,lcaTosrc);
        findPath(LCA,destValue,lcaTodest);

        string ans="";
        for(int i=0;i<lcaTosrc.length();i++) ans.push_back('U');

        ans+=lcaTodest;

        return ans;
        
    }
};