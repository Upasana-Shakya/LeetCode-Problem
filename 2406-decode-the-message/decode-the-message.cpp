class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        char i = 'a';

        for(auto ch : key){
            if(ch != ' ' && mp.find(ch) == mp.end()){
                mp[ch] = i++; 
            }
        }

        for(int i=0 ; i<message.size() ; i++){
            if(message[i] != ' '){
                message[i] = mp[message[i]];
            }
        }

        return message;
    }
};