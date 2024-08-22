class Cashier {
public:
    unordered_map<int, int> map;
    int m ;
    int dis ; 
    int index = 0;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        m = n;
        dis = discount;
        for(int i=0 ; i<products.size() ; i++){
            map[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double ans = 0;
        index++;
        for(int i=0 ; i<product.size(); i++){
            ans += map[product[i]] * amount[i];
        }
        if(index % m == 0){
            return (ans * (100 - dis))/100;
        }
        return ans;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */