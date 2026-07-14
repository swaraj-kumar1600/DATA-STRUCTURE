#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& grid, int sr, int sc) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<pair<int, int>> q;

    q.push({sr, sc});
    visited[sr][sc] = true;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        cout << "(" << row << "," << col << ") ";

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                !visited[nr][nc]) {

                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    bfs(grid, 0, 0);

    return 0;
}