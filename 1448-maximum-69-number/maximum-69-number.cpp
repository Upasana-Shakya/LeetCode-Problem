class Solution {
public:
    int maximum69Number (int num) {
        vector<int> temp;

        while(num){
            temp.push_back(num%10);
            num /= 10;
        }

        reverse(temp.begin(), temp.end());

        for(int i=0 ; i<temp.size() ; i++){
            if(temp[i] == 6){
                temp[i] = 9;
                break;
            }
        }

        int ans = 0;

        for(auto i : temp){
            ans = ans * 10 + i;
        }
        return ans;
    }
};