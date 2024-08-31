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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> v;

        ListNode* temp = head;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> res ;
        int i=0;
        while(i < v.size()){
            res.push_back(v[i]);
            i += 2;
        }
        int j=1;
        while(j < v.size()){
            res.push_back(v[j]);
            j += 2;
        }

        temp = head;
        i=0;
        while(i < res.size()){
            temp->val = res[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};