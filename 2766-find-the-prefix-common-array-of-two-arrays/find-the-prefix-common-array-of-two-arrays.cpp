class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n+1, 0);
        vector<int> res;

        int count = 0;

        for(int i=0 ; i<n ; i++){
            freq[A[i]]++;
            freq[B[i]]++;

            if(A[i] == B[i] && freq[A[i]] == 2){
                count++;
            }
            else{
                if(freq[A[i]] == 2){
                    count++;
                }
                if(freq[B[i]] == 2){
                    count++;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};