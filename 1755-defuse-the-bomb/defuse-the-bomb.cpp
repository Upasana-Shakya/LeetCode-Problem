class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n,0);
        if(k == 0){
            return res;
        }
        else if(k > 0){
            for(int i=0 ; i<n ; i++){
                int sum = 0;
                int j = i+1;
                if(i == n-1){
                    j = 0;
                }
                int t = k;
                while(t != 0 && j <n){
                    sum += code[j];
                    j++;
                    t--;
                    if(t > 0 && j == n){
                        j=0;
                    }
                }
                res[i] = sum;
            }
    
        }
        else{
            for(int i=0 ; i<n ; i++){
                int sum = 0;
                int j = i-1;
                if(i == 0){
                    j = n-1;
                }
                int t = k;
                while(t != 0 && j >= 0 && j < n){
                    sum += code[j];
                    j--;
                    t++;
                    if(j == -1){
                        j = n-1;
                    }
                }
                res[i] = sum;
            }
        }
        return res;
    }
};