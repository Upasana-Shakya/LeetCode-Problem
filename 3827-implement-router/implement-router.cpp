class Router {
public:
    queue<vector<int>> q;
    set<vector<int>> st;
    int limit;
    map<int,vector<int>> mpp;
    map<int,int> rem;

    Router(int memoryLimit) {
        limit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        vector<int> temp = {source, destination, timestamp};
        if (st.find(temp) == st.end()){
            if ((int)q.size() >= limit){
                vector<int> extra = q.front(); q.pop();
                st.erase(extra);
                rem[extra[1]]++;
            }
            st.insert(temp);
            q.push(temp);
            mpp[temp[1]].push_back(temp[2]);
            return true;
        }
        return false;
    }

    vector<int> forwardPacket() {
        vector<int> temp;
        if (!q.empty()) {
            temp = q.front(); q.pop();
            st.erase(temp);
            rem[temp[1]]++;
        }
        return temp;
    }

    int getCount(int destination, int startTime, int endTime) {
        int x = rem[destination];
        auto st = lower_bound(mpp[destination].begin()+x,mpp[destination].end(),startTime) - mpp[destination].begin()-x;
        auto end  = upper_bound(mpp[destination].begin()+x,mpp[destination].end(),endTime) - mpp[destination].begin()-x;
        return int(end-st);
    }
};