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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        vector<vector<int>> ans;

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
            double sum = 0.0;
            int k = ans[i].size();
            for(int j=0 ; j<k ; j++){
                sum += ans[i][j];
            }
            res.push_back(sum/k);
        }
        return res;
    }
};