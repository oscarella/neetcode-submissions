class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m = 0, curr = 0;
        for (int n: nums) {
            curr = n ? (curr + 1): 0;
            m = std::max(m, curr);
        }
        return m;
    }
};