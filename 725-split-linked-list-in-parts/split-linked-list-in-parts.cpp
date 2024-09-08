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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        vector<ListNode*> res(k, NULL);

        int n = len/k ;
        int m = len%k ;

        temp = head;
        for(int i=0 ; i<k && temp ; i++){
            res[i] = temp;
            int currLen = n + (m > 0 ? 1 : 0);
            m--;

            for(int j=1 ; j<currLen ; j++){
                temp = temp->next;
            }

            ListNode* next = temp->next;
            temp->next = NULL;
            temp = next;
        }
        return res;
    }
};