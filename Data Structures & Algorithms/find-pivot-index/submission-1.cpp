class Solution {
    vector<int> prefix_sum;
public:
    int pivotIndex(vector<int>& nums) {
        int total = nums[0];
        prefix_sum = vector<int>(nums.size(), nums[0]);
        for (int i = 1, n = nums.size(); i < n; ++i) {
            prefix_sum[i] = prefix_sum[i-1] + nums[i];
            total += nums[i];
        }
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int leftTotal = prefix_sum[i] - nums[i];
            int rightTotal = total - prefix_sum[i];
            if (leftTotal == rightTotal) return i;
        }
        return -1;
    }
};