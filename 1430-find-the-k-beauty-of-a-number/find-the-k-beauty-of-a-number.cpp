class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.size();
        int count = 0;

        for(int i=0 ; i<n-k+1 ; i++){
            string str = s.substr(i, k);
            int m = stoi(str);
            if(m != 0 && num % m == 0){
                count++;
            }
        }
        return count;
    }
};