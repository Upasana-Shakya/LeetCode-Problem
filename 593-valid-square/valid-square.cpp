class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int, int> mp;
        if(p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4){
            return false;
        }
        int d1 = (pow(p1[0]-p2[0], 2) + pow(p1[1]-p2[1], 2));
        int d2 = (pow(p1[0]-p3[0], 2) + pow(p1[1]-p3[1], 2));
        int d3 = (pow(p1[0]-p4[0], 2) + pow(p1[1]-p4[1], 2));
        int d4 = (pow(p2[0]-p3[0], 2) + pow(p2[1]-p3[1], 2));
        int d5 = (pow(p2[0]-p4[0], 2) + pow(p2[1]-p4[1], 2));
        int d6 = (pow(p3[0]-p4[0], 2) + pow(p3[1]-p4[1], 2));
        mp[d1]++;
        mp[d2]++;
        mp[d3]++;
        mp[d4]++;
        mp[d5]++;
        mp[d6]++;

        if(mp.size() > 2){
            return false;
        }
        return true;
    }
};