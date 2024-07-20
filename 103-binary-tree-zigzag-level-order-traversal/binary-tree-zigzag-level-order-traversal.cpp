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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if(root == NULL){
            return ans;
        }

        q.push(root);

        bool flag = 0;

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
            if(flag == 0){
                ans.push_back(tempp);
                flag = 1;
            }
            else{
                reverse(tempp.begin(), tempp.end());
                ans.push_back(tempp);
                flag = 0;
            }
        }
        return ans;
    }
};