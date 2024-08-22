class Solution {
public:
    int findComplement(int num) {
        string binary = "";

        while(num != 0){
            int temp = num % 2;
            if(temp == 1){
                binary += '1';
            }
            else{
                binary += '0';
            }
            num /= 2;
        }

        for(int i=0 ; i<binary.size() ; i++){
            if(binary[i] == '0'){
                binary[i] = '1';
            }
            else{
                binary[i] = '0';
            }
        }
        int res = 0;

        for(int i=0 ; i<binary.size() ; i++){
            if(binary[i] == '1'){
                res += pow(2, i);
            }
        }
        return res;
    }
};