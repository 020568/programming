#include <stdio.h>

// 定义一个点结构体
typedef struct {
    int x, y;
} Point;

void floodFillBFS(int img[3][4], int rows, int cols, int sr, int sc, int newColor) {
    int oldColor = img[sr][sc];
    if (oldColor == newColor) return;

    // 方向数组
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    // 模拟队列 (数组大小设为 rows * cols 保证够用)
    Point queue[12]; 
    int head = 0, tail = 0;

    // 起点入队并变色
    queue[tail++] = (Point){sr, sc};
    img[sr][sc] = newColor;

    while (head < tail) {
        Point curr = queue[head++]; // 出队
        
        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            // 检查边界和颜色
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && img[nx][ny] == oldColor) 
			{
                img[nx][ny] = newColor; // 染色
                queue[tail++] = (Point){nx, ny}; // 邻居入队
            }
        }
    }
}

int main() {
    int img[3][4] = {
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1}
    };

    floodFillBFS(img, 3, 4, 1, 2, 2);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }
    return 0;
}