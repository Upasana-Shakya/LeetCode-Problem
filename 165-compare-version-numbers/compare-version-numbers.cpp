class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1;
        vector<int> ver2;

        for(int i=0 ; i<version1.size() ; i++){
            string temp = "";
            while(version1[i] != '.' && i < version1.size()){
                temp += version1[i];
                i++;
            }
            ver1.push_back(stoi(temp));
        }

        for(int i=0 ; i<version2.size() ; i++){
            string temp = "";
            while(version2[i] != '.' && i < version2.size()){
                temp += version2[i];
                i++;
            }
            ver2.push_back(stoi(temp));
        }

        int n = max(ver1.size(), ver2.size());

        for(int i=0 ; i<n ; i++){
            int v1 = (i < ver1.size()) ? ver1[i] : 0;
            int v2 = (i < ver2.size()) ? ver2[i] : 0;

            if( v1 < v2){
                return -1;
            }
            if(v1 > v2){
                return 1;
            }
        }
        return 0;
    }
};