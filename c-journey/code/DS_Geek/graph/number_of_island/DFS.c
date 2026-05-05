#include <stdio.h>
#include <stdbool.h>

// 8方向增量数组
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(char grid[5][5], bool visited[5][5], int r, int c) {
    visited[r][c] = true; // 踏上这块地，标记一下

    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        // 检查：不出界 + 是陆地 + 没去过
        if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5 && 
            grid[nr][nc] == 'L' && !visited[nr][nc]) {
            dfs(grid, visited, nr, nc);
        }
    }
}

int countIslands(char grid[5][5]) {
    bool visited[5][5] = {false};
    int count = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // 发现新大陆！
            if (grid[i][j] == 'L' && !visited[i][j]) {
                count++;
                dfs(grid, visited, i, j); // 抹除整座岛
            }
        }
    }
    return count;
}

int main() {
    char grid[5][5] = {
        {'L', 'W', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'W', 'L', 'L', 'W'}
    };

    printf("Number of Islands: %d\n", countIslands(grid));
    return 0;
}