class Solution {
public:
    int findTheLongestSubstring(string s) {
        int count_a = 0;
        int count_e = 0;
        int count_i = 0;
        int count_o = 0;
        int count_u = 0;
        int res = 0;

        unordered_map<string, int> mp;

        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == 'a'){
                count_a++;
            }
            else if(s[i] == 'e'){
                count_e++;
            }
            else if(s[i] == 'i'){
                count_i++;
            }
            else if(s[i] == 'o'){
                count_o++;
            }
            else if(s[i] == 'u'){
                count_u++;
            }
            string even =  to_string(count_a%2) + to_string(count_e%2) + to_string(count_i%2) + 
                            to_string(count_o%2) + to_string(count_u%2);
            if(even == "00000"){
                res = i+1;
            }
            else{
                if(!mp.count(even)){
                    mp[even] = i;
                }
                res = max(res, i-mp[even]);
            }
        }
        return res;
    }
};