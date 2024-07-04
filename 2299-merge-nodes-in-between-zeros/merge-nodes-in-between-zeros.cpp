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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* Head = NULL;
        ListNode* Tail = NULL;
        ListNode* temp = head->next;
        int sum = 0;

        while(temp != NULL){
            if((sum == 0 && temp->val != 0) || (sum != 0 && temp->val != 0)){
                sum += temp->val;
            }
            else if(sum != 0 && temp->val == 0){
                ListNode* newNode = new ListNode(sum);
                if(Head == NULL){
                    Head = newNode;
                    Tail = newNode; 
                }
                else{
                    Tail->next = newNode;
                    Tail = newNode;
                }
                sum = 0;
            }
            temp = temp->next;
        }
        return Head;
    }
};