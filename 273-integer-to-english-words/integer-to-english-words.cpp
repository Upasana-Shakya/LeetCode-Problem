class Solution {
public:
    string Number(int num){
        string ones[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", 
                            "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                            "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string temp="";
        if(num >= 100){
            temp += ones[num/100]+" ";
            num = num%100;
            temp += "Hundred ";
            if(num==0) return temp;
        }
        if(num >= 20){
                temp += tens[num/10]+" ";
                num %= 10;
                if(num>0) temp += (ones[num]+" ");
            }
        else{
             temp += (ones[num]+" ");
         }
        return temp;
    }
    string numberToWords(int num) {
        string ans = "";
        if(num/1000000000){
            ans += (Number(num/1000000000)+"Billion ");
            num %= 1000000000;
        }
        if(num/1000000){
            ans += (Number(num/1000000)+"Million ");
            num %= 1000000;
        }
        if(num/1000){
            ans += (Number(num/1000)+"Thousand ");
            num %= 1000;
        }
        if(num/100){
            ans += (Number(num/100)+"Hundred ");
            num %= 100;
        }
        if(num!=0 || ans.size()==0){
            ans += (Number(num));
        }
        ans.pop_back();
        return ans;
    }
};