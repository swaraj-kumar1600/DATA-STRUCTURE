#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {

        int r = row;
        int c = col;

        while (c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            c--;
        }

        r = row;
        c = col;

        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;
            c--;
        }

        r = row;
        c = col;

        while (r < n && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r++;
            c--;
        }

        return true;
    }

    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {

        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {

            if (isSafe(row, col, board, n)) {

                board[row][col] = 'Q';

                solve(col + 1, board, ans, n);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        solve(0, board, ans, n);

        return ans;
    }
};

int main() {

    int n = 4;

    Solution obj;

    vector<vector<string>> ans = obj.solveNQueens(n);

    for (auto board : ans) {

        for (auto row : board) {
            cout << row << endl;
        }

        cout << endl;
    }

    return 0;
}