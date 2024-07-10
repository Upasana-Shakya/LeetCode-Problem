class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;

        for(auto i : logs){
            if(i == "../"){
                count--;
            }
            else if(i == "./"){
                continue;
            }
            else{
                count++;
            }
            if(count < 0){
                count = 0;
            }
        }
        return count;
    }
};