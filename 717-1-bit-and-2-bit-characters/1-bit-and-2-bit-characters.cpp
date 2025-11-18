class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i;
        
        for(i=0 ; i<bits.size()-1 ; i++){
            if(bits[i] == 1){
                i++;
            }
            else{
                continue;
            }
        }
        if(i == n-1){
            return true;
        }
        return false;
    }
};