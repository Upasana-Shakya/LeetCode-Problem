class Solution {
public:
    int passThePillow(int n, int time) {
        int direction=1;
        int i=1;
        
        for(int j=1 ; j<=time ; j++){
            i += direction;

            if(i == 1 || i == n){
                direction = - direction;
            }
        }
        return i;
    }
};