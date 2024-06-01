class Solution {
public:
    string categorizeBox(int l, int w, int h, int m) {
        long long vol = (long long)l*w*h;

        bool Bulky = vol >= 1e9 || l >= 1e4 || w >= 1e4 || h >= 1e4;
        bool Heavy = m >= 100;

        if(Bulky && Heavy){
            return "Both";
        }
        else if(!Bulky && !Heavy){
            return "Neither";
        }
        else if(Bulky && !Heavy){
            return "Bulky";
        }
        else if(!Bulky && Heavy){
            return "Heavy";
        }
        return "";
    }
};