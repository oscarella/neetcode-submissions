class NumArray {
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        int lastSum = 0;
        for (auto &n: nums) {
            lastSum += n;
            prefixSum.push_back(lastSum);
        }
    }
    
    int sumRange(int left, int right) {
        int prefixRight = prefixSum[right];
        int prefixLeft = left > 0 ? prefixSum[left - 1] : 0;
        return prefixRight - prefixLeft;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */