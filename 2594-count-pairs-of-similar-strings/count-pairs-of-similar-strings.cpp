class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n = words.size();
        int count=0;

        for(int i=0 ; i<n-1 ; i++){
            string s1 = words[i];
            set<int, greater<int>> st1;

            for(int j=0 ; j<s1.size() ; j++){
                st1.insert(s1[j] - 'a');
            }
            
            for(int k = i+1 ; k<n ; k++){
                string s2 = words[k];
                set<int, greater<int>> st2;

                for(int j=0 ; j< s2.size() ; j++){
                    st2.insert(s2[j] - 'a');
                }

                if(st1 == st2){
                    count++;
                }
            }
        }
        return count;
    }
};