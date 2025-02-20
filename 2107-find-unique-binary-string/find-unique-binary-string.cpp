class Solution {
public:
    int n;
    string generate(string curr, unordered_set<string>& numsSet){
        if(curr.size() == n){
            if(numsSet.find(curr) == numsSet.end()){
                return curr;
            }
            return "";
        }

        string addZero = generate(curr+"0", numsSet);
        if(addZero.size() > 0){
            return addZero;
        }
        return generate(curr+"1", numsSet);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        unordered_set<string> numsSet;

        for(auto s : nums){
            numsSet.insert(s);
        }
        return generate("", numsSet);
    }
};