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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> res;

        if(root == NULL){
            return res;
        }

        q.push(root);

        while(!q.empty()){
            vector<int> tempp;
            int size = q.size();
    
            while(size){
                //Step A
                TreeNode* temp = q.front();

                //Step B
                q.pop();
                
                //Step C
                tempp.push_back(temp->val);

                //Step D
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                size--;
            }
            ans.push_back(tempp);
        }
        for(int i=0 ; i<ans.size() ; i++){
            int n = ans[i].size();
            res.push_back(ans[i][n-1]);
        }
        return res;
    }
};