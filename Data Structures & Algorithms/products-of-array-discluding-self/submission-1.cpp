class Solution {
    vector<int> leftProduct;
    vector<int> rightProduct;
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> retv(n);
        // prefix
        int product = 1;
        for (int i = 0; i < n; ++i) {
            retv[i] = product;
            product *= nums[i];
        }
        // postfix
        product = 1;
        for (int i = n-1; i >= 0; --i) {
            retv[i] *= product;
            product *= nums[i];
        }
        return retv;
    }
};
