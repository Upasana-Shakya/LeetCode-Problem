class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;

        for(int i=0 ; i<operations.size() ; i++){
            int n = record.size();
            if(operations[i] == "+"){
                int sum = record[n-1]+record[n-2];
                record.push_back(sum);
            }
            else if(operations[i] == "D"){
                int doubl = record.back() * 2;
                record.push_back(doubl);
            }
            else if(operations[i] == "C"){
                record.pop_back();
            }
            else{
                int temp = stoi(operations[i]);
                record.push_back(temp);
            }
        }
        int sum = 0;
        for(auto score : record){
            sum += score;
        }
        return sum;
    }
};