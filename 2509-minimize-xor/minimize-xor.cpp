class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // Count the number of set bits in num2
        int num2SetBits = __builtin_popcount(num2);
        int result = 0;

        // Set the bits in num1 to match num2SetBits
        for (int i = 31; i >= 0 && num2SetBits > 0; --i) {
            if (num1 & (1 << i)) {
                result |= (1 << i);
                --num2SetBits;
            }
        }

        // If there are still bits left to set, set them from the least significant bit
        for (int i = 0; i < 32 && num2SetBits > 0; ++i) {
            if (!(result & (1 << i))) {
                result |= (1 << i);
                --num2SetBits;
            }
        }

        return result;
    }
};