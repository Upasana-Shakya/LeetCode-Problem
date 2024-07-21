class Solution {
public:
    string losingPlayer(int x, int y) {
        bool flag = 1;

        while(x > 0 && y > 3){
            x--;
            y -= 4;
            flag = !flag;
        }
        if(flag){
            return "Bob";
        }
        else{
            return "Alice";
        }
    }
};