class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' 
            || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
            return true;
        }
        else{
            return false;
        }
    }
    bool isValid(string word) {
        if(word.size() < 3){
            return false;
        }

        int num = 0, vowel = 0, consonant = 0;

        for(int i=0 ; i<word.size() ; i++){
            if(word[i] >= '0' && word[i] <= '9'){
                num++;
            }
            if((word[i] >= 'a' && word[i] <= 'z') || word[i] >= 'A' && word[i] <= 'Z'){
                if(isVowel(word[i])){
                    vowel++;
                }
                else{
                    consonant++;
                }
            }
        }

        if(num + vowel +consonant == word.size() && vowel > 0 && consonant > 0){
            return true;
        }
        return false;
    }
};