#include <stdio.h>
#include <stdbool.h>

typedef struct { int r, c; } Point;

int dRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void bfs(char grid[5][5], bool visited[5][5], int startR, int startC) {
    Point queue[25]; // 最大 25 个格子
    int head = 0, tail = 0;

    // 入队并标记
    queue[tail++] = (Point){startR, startC};
    visited[startR][startC] = true;

    while (head < tail) {
        Point curr = queue[head++];

        for (int k = 0; k < 8; k++) {
            int nr = curr.r + dRow[k];
            int nc = curr.c + dCol[k];

            // 越界检查 + 陆地检查 + 访问检查
            if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5 && grid[nr][nc] == 'L' && !visited[nr][nc]) 
			{
                visited[nr][nc] = true; // 进队前必须标记！
                queue[tail++] = (Point){nr, nc};
            }
        }
    }
}

int countIslands(char grid[5][5]) {
    bool visited[5][5] = {0};
    int count = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (grid[i][j] == 'L' && !visited[i][j]) {
                bfs(grid, visited, i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    char grid[5][5] = {
        {'L', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'W', 'L', 'L', 'W'}
    };
    printf("%d\n", countIslands(grid)); // 输出 3
    return 0;
}