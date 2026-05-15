class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> seen;
        const int LEN = 9;
        // Check row
        for (int i = 0; i < LEN; ++i) {
            seen.clear();
            for (int j = 0; j < LEN; j++) { // board[i][j]
                if (seen.count(board[i][j])) return false;
                if (board[i][j] != '.') seen.insert(board[i][j]);
            }
        }
        // Check col
        for (int i = 0; i < LEN; ++i) {
            seen.clear();
            for (int j = 0; j < LEN; j++) { // board[j][i]
                if (seen.count(board[j][i])) return false;
                if (board[j][i] != '.') seen.insert(board[j][i]);
            }
        }
        // Check sub-boxes
        for (int i = 0; i < LEN; i += 3) {
            for (int j = 0; j < LEN; j += 3) {
                seen.clear();
                for (int k = i; k < i + 3; ++k) {
                    for (int l = j; l < j + 3; ++l) {
                        if (seen.count(board[k][l])) return false;
                        if (board[k][l] != '.') seen.insert(board[k][l]);
                    }
                }
            }
        }
        return true;
    }
};
