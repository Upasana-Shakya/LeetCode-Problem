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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int len = 0;

        while(temp != NULL){
            len++;
            temp = temp->next;
        }

        // find kth node from starting
        temp = head;
        int t = k-1;
        while(t--){
            temp = temp->next;
        }
        
        // Find kth node from end
        t = len-k;
        ListNode* temp1 = head;
        while(t--){
            temp1 = temp1->next;
        }

        // Swap
        int temp2 = temp->val;
        temp->val = temp1->val;
        temp1->val = temp2;

        return head;
    }
};