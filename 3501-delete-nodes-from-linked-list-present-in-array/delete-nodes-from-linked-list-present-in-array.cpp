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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* curr = prev;
        
        while(curr->next != NULL){
            if(numsSet.count(curr->next->val) > 0){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else{
                curr = curr->next;
            }
        }
        
        return prev->next;
    }
};