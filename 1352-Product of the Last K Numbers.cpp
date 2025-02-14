class ProductOfNumbers {
public:
    vector<int> nums;
    int n;
    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }
    
    void add(int num) { //O(1)
        if(num == 0){
            nums.clear();
            n=0;
        }
        else if(!nums.empty()){
            nums.push_back(nums[n-1]*num);
            n++;
        }
        else{
            nums.push_back(num);
            n++;
        }
    }
    
    int getProduct(int k) { //O(1)
        if(n < k) return 0;
        if(n == k) return nums[n-1];

        return (nums[n-1]/nums[n-k-1]);

    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
