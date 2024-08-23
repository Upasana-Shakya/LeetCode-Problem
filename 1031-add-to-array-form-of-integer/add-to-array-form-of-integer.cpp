class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int i = n-1;
        int carry = 0;

        while(i >= 0){
            int digit = k % 10;
            int sum = (num[i] + digit + carry) % 10;
            carry = (num[i] + digit + carry) / 10;
            num[i] = sum;
            k = k/10;
            i--;
        }
        while(k || carry){
            int digit = k % 10;
            int val = (digit + carry) % 10;
            num.insert(num.begin(), val);
            carry = (digit + carry) / 10;
            k /= 10;
        }
        return num;
    }
};