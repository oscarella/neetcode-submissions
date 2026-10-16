using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stack{};
        for (const string &op: operations) {
            if (op == "+") {
                if (stack.size() < 2) throw;
                int prevScore = stack[stack.size() - 1];
                int secondPrevScore = stack[stack.size() - 2];
                stack.push_back(prevScore + secondPrevScore);
            } else if (op == "D") {
                if (!stack.size()) throw;
                int top = stack.back();
                stack.push_back(top * 2);
            } else if (op == "C") {
                if (!stack.size()) throw;
                stack.pop_back();
            } else {
                stack.push_back(stoi(op));
            }
        }
        int totalScore = 0;
        for (auto i: stack) totalScore += i;
        return totalScore;
    }
};