class Solution {
public:
    void round2Decimal(string &s){
        int i=0 ;
        while(s[i++] != '.');
        s = s.substr(0, i+2);
        return;
    }
    bool isPrice(string word){
        int n = word.size();
        if(n < 2 || word[0] != '$'){
            return false;
        }
        else{
            for(int i=1 ; i<n ; i++){
                if(!isdigit(word[i])){
                    return false;
                }
            }
        }
        return true;
    }
    string discountPrices(string sentence, int discount) {
        vector<string> v;
        string ans = "";
        int i=0;

        while(i < sentence.size()){
            string s = "";
            while(i < sentence.size() && sentence[i] != ' '){
                s += sentence[i];
                i++;
            }
            v.push_back(s);
            i++;
        }

        for(int i=0 ; i<v.size() ; i++){
            if(isPrice(v[i])){
                long double price = (long double)stoll(v[i].substr(1));
                price -= price*discount/100;
                price = round(price*100)/100;
                string temp = to_string(price);
                round2Decimal(temp);
                v[i] = "$" + temp;
            }
            ans += v[i] +" ";
        }
        ans.pop_back();
        return ans;
    }
};