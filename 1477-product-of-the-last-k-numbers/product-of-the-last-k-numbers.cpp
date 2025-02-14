class ProductOfNumbers {
public:
    vector<int> nums;
    int n = 0;

    ProductOfNumbers() {
        nums.push_back(1);
        n = 0;
    }
    
    void add(int num) {
        if(num == 0){
            nums = {1};
            n = 0;
        }
        else{
            nums.push_back(nums[n]*num);
            n++;
        }
    }
    
    int getProduct(int k) {
        if(k > n){
            return 0;
        }
        return nums[n] / nums[n-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */