class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        stack<char> st;

        for(auto ch : s){
            if(ch == '['){
                st.push(ch);
            }
            else {
                if(!st.empty() && ch == ']'){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        return st.size()/2;
    }
};