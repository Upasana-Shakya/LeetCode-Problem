class Solution {
public:
    vector<int> diffWaysToCompute(string e) {
        vector<int> ans;

        for(int i=0 ; i<e.size() ; i++){
            char op = e[i];
            if(op == '+' || op == '-' || op == '*'){
                vector<int> v1 = diffWaysToCompute(e.substr(0, i));
                vector<int> v2 = diffWaysToCompute(e.substr(i+1, e.size()-1));

                for(auto a : v1){
                    for(auto b : v2){
                        if(op == '+'){
                            ans.push_back(a+b);
                        }
                        else if(op == '-'){
                            ans.push_back(a-b);
                        }
                        else if(op == '*'){
                            ans.push_back(a*b);
                        }
                    }
                }
            }
        }
        if(ans.empty()){
            ans.push_back(stoi(e));
        }
        return ans;
    }
};