class Solution {
public:
    string intToRoman(int num) {
        
        string ans = "";
        vector<pair<string, int>> mp = {{"M",1000},{"CM",900},{"D",500},{"CD",400},{"C",100},{"XC",90},{"L",50},{"XL",40},{"X",10},{"IX",9},{"V",5},{"IV",4},{"I",1}};

        for(int i=0 ; i<mp.size() ; i++){
            while(num >= mp[i].second){
                ans += mp[i].first;
                num -= mp[i].second;
            }
        }
        return ans;
    }
};