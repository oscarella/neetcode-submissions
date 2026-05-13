class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (auto &n: nums) {
            if (m.count(n)) ++m[n];
            else m[n] = 1;
        }
        // hashmap computed
        int n = nums.size();
        vector<vector<int>> vec(n, vector<int>{});
        for (auto &p: m) {
            vec[p.second-1].push_back(p.first);
        }
        // vector computed: index - frequency, [index] - numbers
        vector<int> retvec;
        int retvecSize = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (vec[i].size()) { // vec[i] is non-empty
                for (auto &num: vec[i]) {
                    if (retvecSize == k) return retvec;
                    else {
                        retvec.push_back(num);
                        ++retvecSize;
                    }
                }
            }
        }
        return retvec;
    }
};
