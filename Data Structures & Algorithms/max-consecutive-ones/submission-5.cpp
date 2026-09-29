class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, curr = 0;
        for (int n: nums) {
            if (n == 1) {
                curr = n ? (curr + 1): 0;
                max = max(max, curr);
            }
        }
        return max;
    }
};