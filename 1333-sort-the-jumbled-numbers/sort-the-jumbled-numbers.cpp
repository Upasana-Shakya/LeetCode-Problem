class Solution {
public:
    int getNumber(int num, vector<int>& mapping){
        if(num == 0){
            return mapping[0];
        }
        int n = 0;
        int fact = 1;

        while(num){
            n += mapping[num % 10] * fact;
            fact *= 10;
            num /= 10;
        }
        return n;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            int mapped_a = getNumber(a, mapping);
            int mapped_b = getNumber(b, mapping);
            if (mapped_a == mapped_b)
                return false;
            return mapped_a < mapped_b;
        });
        return nums;
    }
};