class Solution {
public:
    string invert(string s){
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == '0'){
                s[i] = '1';
            }
            else{
                s[i] = '0';
            }
        }
        return s;
    }
    char findKthBit(int n, int k) {
        vector<string> vs(n);
        vs[0] = "0";

        for(int i=1 ; i<n ; i++){
            string s = invert(vs[i-1]);
            reverse(s.begin(), s.end());
            vs[i] = vs[i-1] + "1" + s;
        }

        return vs[n-1][k-1];
    }
};