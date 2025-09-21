class MovieRentingSystem {
public:
    map<int, set<pair<int, int>>> avail;
    set<tuple<int, int, int>> rented;
    map<pair<int, int>, int> price;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &n : entries){
            int shop = n[0];
            int movie = n[1];
            int pri = n[2];
            avail[movie].insert({pri, shop});
            price[{shop, movie}] = pri;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        if(avail.count(movie)){
            for(auto &p : avail[movie]){
                res.push_back(p.second);
                if(res.size() == 5){
                    break;
                }
            }
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int pri = price[{shop, movie}];
        avail[movie].erase({pri, shop});
        rented.insert({pri, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int pri = price[{shop, movie}];
        rented.erase({pri, shop, movie});
        avail[movie].insert({pri, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for(auto &t : rented){
            res.push_back({get<1>(t), get<2>(t)});
            if(res.size() == 5){
                break;
            }
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */