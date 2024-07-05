class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int, greater<int> > s;

        for(int i=0 ; i<nums.size() ; i++){
            s.insert(nums[i]);
        }

        vector<int> arr;
        for(auto i : s){
            arr.push_back(i);
        }

        if(arr.size() < 3){
            return arr[0];
        }
        return arr[2];
        
    }
};