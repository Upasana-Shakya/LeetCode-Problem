class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> ans;

        for(int asteroid : asteroids){
            if(s.empty() || asteroid > 0){
                s.push(asteroid);
            }
            else{
                while(!s.empty() && s.top() > 0 && s.top() < -asteroid){
                    s.pop();
                }
                if(s.empty() || s.top() < 0){
                    s.push(asteroid);
                }
                else if(s.top() == -asteroid){
                    s.pop();
                }
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};