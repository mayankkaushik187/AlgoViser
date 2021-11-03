//leetcode 51
class Solution {
    public:
        bool isValid(vector < string > & queenRow, int n, int col, int row) {
            for (int i = 0; i < row; i++) {
                if (queenRow[i][col] == 'Q') return false;
            }
            for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--) {
                if (queenRow[i][j] == 'Q') return false;
            }
            for (int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++) {
                if (queenRow[i][j] == 'Q') return false;
            }
            return true;
        }
    void backtrack(vector < vector < string >> & res, vector < string > & queenRow, int row, int n) {
        if (row == n) {
            res.push_back(queenRow);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(queenRow, n, i, row)) {
                queenRow[row][i] = 'Q';
                backtrack(res, queenRow, row + 1, n);
                queenRow[row][i] = '.';
            }
        }
    }
    vector < vector < string >> solveNQueens(int n) {
        vector < vector < string >> res;
        vector < string > queenRow(n, string(n, '.'));
        backtrack(res, queenRow, 0, n);
        return res;
    }
};
