class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss;
        stack<char> st;

        for(auto ch : s){
            if(ss.empty() && ch == '#'){
                continue;
            }
            else if(!ss.empty() && ch == '#'){
                ss.pop();
            }
            else{
                ss.push(ch);
            }
        }
        for(auto ch : t){
            if(st.empty() && ch == '#'){
                continue;
            }
            else if(!st.empty() && ch == '#'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        if(ss.size() != st.size()){
            return false;
        }
        else{
            while(!ss.empty() && !st.empty()){
                if(ss.top() != st.top()){
                    return false;
                }
                ss.pop();
                st.pop();
            }
        }
        return true;
    }
};