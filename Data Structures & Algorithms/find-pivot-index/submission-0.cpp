class Solution {
    vector<int> prefix_sum, postfix_sum;
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        prefix_sum = vector<int>(n, 0);
        postfix_sum = vector<int>(n, 0);
        for (int i = 1; i < n; ++i) {
            prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
            postfix_sum[n-1-i] = postfix_sum[n-i] + nums[n-i];
        }
        for (int i = 0; i < n; ++i) {
            if (prefix_sum[i] == postfix_sum[i]) {
                return i;
            }
        }
        return -1;
    }
};