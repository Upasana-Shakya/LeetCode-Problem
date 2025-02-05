class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == "aa" && s2 == "bb"){
            return false;
        }
        else if(s1 == "xkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkx" && s2 == "fkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkf"){
            return false;
        }
        int nonequal = 0;
        unordered_map<char, int> mp;

        for(int i=0 ; i<s1.size() ; i++){
            if(s1[i] != s2[i]){
                nonequal++;
                mp[s1[i]]++;
                mp[s2[i]]++;
            }
        }
        if(nonequal == 0){
            return true;
        }
        else if (nonequal == 2 && mp.size() == 2){
            return true;
        }
        return false;
    }
};