#include <iostream>
#include <vector>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    int n = grid.size();
    int m = grid[0].size();

    visited[row][col] = true;

    cout << "(" << row << "," << col << ") ";

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr >= 0 && nr < n &&
            nc >= 0 && nc < m &&
            !visited[nr][nc]) {

            dfs(nr, nc, grid, visited);
        }
    }
}

int main() {
    vector<vector<int>> grid = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    dfs(0, 0, grid, visited);

    return 0;
}