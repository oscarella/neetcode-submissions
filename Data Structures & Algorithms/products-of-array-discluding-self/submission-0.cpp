class Solution {
    vector<int> leftProduct;
    vector<int> rightProduct;
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        leftProduct = vector<int>(n, 1);
        rightProduct = vector<int>(n, 1);
        for (int i = 1; i < n; ++i) {
            leftProduct[i] = leftProduct[i-1] * nums[i-1];
            rightProduct[n-i-1] = rightProduct[n-i] * nums[n-i];
        }
        vector<int> retv;
        for (int i = 0; i < n; ++i) {
            retv.push_back(leftProduct[i] * rightProduct[i]);
        }
        return retv;
    }
};
