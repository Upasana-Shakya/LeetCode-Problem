class Solution {
public:
    bool check(string &num, string &pattern){
        int n = pattern.size();

        for(int i=0 ; i<n ; i++){
            if(pattern[i] == 'I'){
                if(num[i] > num[i+1]){
                    return false;
                }
            }
            else{
                if(num[i] < num[i+1]){
                    return false;
                }
            }
        }
        return true;
    }
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string num = "";

        for(int i=1 ; i <= n+1 ; i++){
            num.push_back(i + '0');
        }

        while(!check(num, pattern)){
            next_permutation(num.begin(), num.end());
        }
        return num;
    }
};