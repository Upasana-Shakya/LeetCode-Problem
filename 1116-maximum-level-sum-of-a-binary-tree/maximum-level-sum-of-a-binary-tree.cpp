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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        int res;

        if(root == NULL){
            return 0;
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
            int sum = 0;
            for(int i=0 ; i<tempp.size() ; i++){
                sum += tempp[i];
            }
            ans.push_back(sum);
        }
        int maxi = INT_MIN;
        for(int i=0 ; i<ans.size() ; i++){
            if(ans[i] > maxi){
                maxi = ans[i];
                res = i+1;
            }
        }
        return res;
    }
};