/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = m-1;

        vector<vector<int>> res(m, vector<int>(n, -1));

        while(top <= bottom && left <= right){
            for(int i=left ; i<=right ; i++){
                if(!head){
                    break;
                }
                else{
                    res[top][i] = head->val;
                    head = head->next;
                }
            }
            top++;
            for(int i=top ; i<=bottom ; i++){
                if(!head){
                    break;
                }
                else{
                    res[i][right] = head->val;
                    head = head->next;
                }
            }
            right--;
            if(top <= bottom){
                for(int i=right ; i>=left ; i--){
                    if(!head){
                        break;
                    }
                    else{
                        res[bottom][i] = head->val;
                        head = head->next;
                    }
                }
                bottom--;
            }
            if(left <= right){
                for(int i=bottom ; i>=top ; i--){
                    if(!head){
                        break;
                    }
                    else{
                        res[i][left] = head->val;
                        head = head->next;
                    }
                }
                left++;
            }
        }
        return res;
    }
};