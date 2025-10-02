class Solution {
public:
    int maxBottlesDrunk(int numB, int numE) {
        int res = numB;

        int emp = numB;
        numB = 0;
        while(emp+numB >= numE){
            numB++;
            emp -= numE;
            numE++;
        }
        res += numB;
        return res;
    }
};