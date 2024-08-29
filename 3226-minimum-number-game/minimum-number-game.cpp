class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> arr;
        bool alice = 0;
        bool bob = 0;
        int a ;
        int b;
        int idx_a, idx_b;


        while(nums.size()){
            int mini_a = 101;
            for(int i=0 ; i<nums.size() ; i++){
                if(mini_a > nums[i]){
                    mini_a = nums[i];
                    idx_a = i;
                }
            }
            nums.erase(nums.begin()+idx_a);
            int mini_b = 101;
            for(int i=0 ; i<nums.size() ; i++){
                if(mini_b > nums[i]){
                    mini_b = nums[i];
                    idx_b = i;
                }
            }
            nums.erase(nums.begin()+idx_b);

            if(!alice){
                alice = 1;
                bob = 0;
                a = mini_a;
            }
            if(!bob){
                bob = 1;
                alice = 0;
                b = mini_b;
            }
            arr.push_back(b);
            arr.push_back(a);
        }
        return arr;
    }
};