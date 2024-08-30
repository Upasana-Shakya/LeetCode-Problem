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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* temp = head;

        while(temp){
            s.push(temp);
            temp = temp->next;
        }

        int n = (s.size()-1)/2;

        temp = head;

        while(n--){
            ListNode* t = temp->next;
            temp->next = s.top();
            s.pop();
            temp->next->next = t;
            temp = temp->next->next;
            s.top()->next = NULL;
        }
    }
};