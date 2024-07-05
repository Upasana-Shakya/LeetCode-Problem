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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        vector<int> res;
        int i=2;

        while(curr->next != NULL){
            if((curr->val > curr->next->val && curr->val > prev->val) ||
                 (curr->val < curr->next->val && curr->val < prev->val)){
                res.push_back(i);
            }
            prev = curr;
            curr = curr->next;
            i++;
        }
        int n = res.size();
        int minDis = -1;
        int maxDis = -1;
        if(n > 1){
            minDis = INT_MAX;
            maxDis = res.back() - res.front();

            for(int i=1 ; i<n ; i++){
                minDis = min(minDis, res[i]-res[i-1]);
            }
        }
        return {minDis, maxDis};
    }
};