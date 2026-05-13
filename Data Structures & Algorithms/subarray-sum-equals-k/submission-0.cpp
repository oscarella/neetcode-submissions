class Solution {
private:
    unordered_map<int,int> m;
public:
    int subarraySum(vector<int>& nums, int k) {
        int retval = 0;
        int prefix_sum = 0;
        for (auto &n: nums) {
            prefix_sum += n;
            if (prefix_sum == k) ++retval;
            if (m.count(prefix_sum - k)) retval += m[prefix_sum - k];

            if (m.count(prefix_sum)) ++(m[prefix_sum]);
            else m[prefix_sum] = 1;
        }
        return retval;
    }
};