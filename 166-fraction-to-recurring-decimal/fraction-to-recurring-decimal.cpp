class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if(num == 0){
            return "0";
        }

        string res;

        if((num < 0 && den > 0) || (num > 0  && den < 0)){
            res += '-';
        }

        long n = abs((long)num);
        long d = abs((long)den);

        long quo = n/d;
        long rem = n % d;

        res += to_string(quo);

        if(rem == 0){
            return res;
        }
        res += '.';

        unordered_map<long, int> mp;
        while(rem != 0){
            if(mp.count(rem)){
                res.insert(mp[rem], "(");
                res += ')';
                return res;
            }
            mp[rem] = res.size();
            rem *= 10;
            res += to_string(rem/d);
            rem %= d;
        }
        return res;
    }
};