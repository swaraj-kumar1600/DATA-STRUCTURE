#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    bool isSafe(int row, int col, int n, vector<vector<int>>& board) {
        return (row >= 0 &&
                row < n &&
                col >= 0 &&
                col < n &&
                board[row][col] == -1);
    }

    bool solve(int row, int col, int move, int n, vector<vector<int>>& board) {

        if (move == n * n)
            return true;

        for (int i = 0; i < 8; i++) {

            int nr = row + dr[i];
            int nc = col + dc[i];

            if (isSafe(nr, nc, n, board)) {

                board[nr][nc] = move;

                if (solve(nr, nc, move + 1, n, board))
                    return true;

                board[nr][nc] = -1;
            }
        }

        return false;
    }

    void knightTour(int n) {

        vector<vector<int>> board(n, vector<int>(n, -1));

        board[0][0] = 0;

        if (solve(0, 0, 1, n, board)) {

            for (auto row : board) {
                for (auto cell : row) {
                    cout << cell << "\t";
                }
                cout << endl;
            }

        } else {
            cout << "No Solution Exists\n";
        }
    }
};

int main() {

    int n = 8;

    Solution obj;
    obj.knightTour(n);

    return 0;
} 