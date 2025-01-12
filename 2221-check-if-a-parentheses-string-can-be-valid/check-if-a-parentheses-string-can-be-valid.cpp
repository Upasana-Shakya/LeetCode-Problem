class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        int minOpen = 0, maxOpen = 0;

        if(n % 2 == 1){
            return false;
        }

        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                // If unlocked, it can be either '(' or ')'.
                maxOpen++; // Assume it as '(' for maximum open parentheses.
                minOpen = max(0, minOpen - 1); // Assume it as ')' for minimum open parentheses.
            } else {
                // If locked, take the character as is.
                if (s[i] == '(') {
                    minOpen++;
                    maxOpen++;
                } else { // s[i] == ')'
                    minOpen = max(0, minOpen - 1);
                    maxOpen--;
                }
            }

            // If at any point maxOpen becomes negative, we cannot balance the string.
            if (maxOpen < 0){
                return false;
            }
        }

        // For the string to be valid, minOpen must be 0 at the end.
        return minOpen == 0;
    }
};