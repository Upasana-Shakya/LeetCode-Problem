class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        // Process first k-size window
        for(int i=0 ; i<k ; i++){
            //chhote element remove karo
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            // inserting index so that we can check out of window element
            dq.push_back(i);
        }

        //store answer of fist window
        ans.push_back(nums[dq.front()]);

        //process remaining windows
        for(int i=k ; i<nums.size() ; i++){
            //remove out of window element
            if(!dq.empty() && i-dq.front() >= k){
                dq.pop_front();
            }

            // Ab firse curr element ke liye chhote element ko remove krna hai
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            // inserting index so that we can check out of window element
            dq.push_back(i);

            // Current window ka ans store karna hai
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};