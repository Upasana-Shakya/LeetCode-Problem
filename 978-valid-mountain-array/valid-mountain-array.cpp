class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3){
            return false;
        }
        
        int idx=0;
        int maxi = INT_MIN;
        for(int i=0 ; i<n ; i++){
            if(arr[i] > maxi){
                maxi = arr[i];
                idx = i;
            }
        }
        if(idx == 0 || idx == n-1){
            return false;
        }
        
        for(int i=0 ; i<idx ; i++){
            if(arr[i] < arr[i+1]){
                continue;
            }
            else{
                return false;
            }
        }
        for(int i=idx ; i<n-1 ; i++){
            if(arr[i] > arr[i+1]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};