#include <stdio.h>

/**
 * DFS 填充函数
 */
void dfs(int img[3][4], int rows, int cols, int x, int y, int oldColor, int newColor) {
    // 边界检查 & 颜色检查
    if (x < 0 || x >= rows || y < 0 || y >= cols || img[x][y] != oldColor) {
        return;
    }

    // 更新颜色
    img[x][y] = newColor;

    // 递归上下左右
    dfs(img, rows, cols, x + 1, y, oldColor, newColor);
    dfs(img, rows, cols, x - 1, y, oldColor, newColor);
    dfs(img, rows, cols, x, y + 1, oldColor, newColor);
    dfs(img, rows, cols, x, y - 1, oldColor, newColor);
}

void floodFill(int img[3][4], int rows, int cols, int sr, int sc, int newColor) {
    int oldColor = img[sr][sc];
    
    // 如果颜色已经是一样的，防止死循环
    if (oldColor != newColor) {
        dfs(img, rows, cols, sr, sc, oldColor, newColor);
    }
}

int main() {
    // 定义一个 3x4 的图像
    int img[3][4] = {
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1}
    };

    int sr = 1, sc = 2; // 起点 (1, 2)
    int newColor = 2;

    floodFill(img, 3, 4, sr, sc, newColor);

    // 打印结果
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }

    return 0;
}