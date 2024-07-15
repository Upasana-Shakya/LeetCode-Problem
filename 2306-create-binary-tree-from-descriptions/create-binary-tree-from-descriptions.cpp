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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, bool> child;

        for(auto des : descriptions){
            int x = des[0], y = des[1];
            if(mp.find(x) == mp.end()){
                TreeNode* root = new TreeNode(x);
                mp[x] = root;
            }
            if(mp.find(y) == mp.end()){
                TreeNode* newNode = new TreeNode(y);
                mp[y] = newNode;
            }
            if(des[2] == 1){
                mp[x]->left = mp[y]; 
            }
            else{
                mp[x]->right = mp[y];
            }
            child[y] = true;
        }

        TreeNode* ans = NULL;
        for(auto x : mp){
            if(!child[x.first]){
                ans = mp[x.first];
            }
        }
        return ans;
    }
};