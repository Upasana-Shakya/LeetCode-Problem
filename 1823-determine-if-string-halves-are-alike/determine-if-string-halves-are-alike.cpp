class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int count1 = 0, count2 = 0;

        int i = n/2-1;
        int j = i+1;

        while(i >= 0 && j < n){
            if(isVowel(s[i])){
                count1++;
            }
            if(isVowel(s[j])){
                count2++;
            }
            i--;
            j++;
        }
        if(count1 == count2){
            return true;
        }
        return false;
    }
};