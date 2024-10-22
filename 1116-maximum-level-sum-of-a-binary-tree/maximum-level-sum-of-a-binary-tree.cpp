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
        int maxi = INT_MIN;
        int index;

        q.push(root);
        int i=1;

        while(!q.empty()){
            int sum = 0;
            int size = q.size();
    
            while(size){
                //Step A
                TreeNode* temp = q.front();

                //Step B
                q.pop();
                
                //Step C
                sum += temp->val;

                //Step D
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                size--;
            }
            if(maxi < sum){
                maxi = sum;
                index = i;
            }
            i++;
        }
        return index;
    }
};