#include "mazesolution.h"
#include <stdbool.h>
#include <string.h>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[MAX][MAX];
char board[MAX][MAX];
int dis[MAX][MAX];
int n, m;

void bfs(int x, int y) {
    int queue[MAX * MAX][2];
    int front = 0, rear = 0;

    queue[rear][0] = x;
    queue[rear][1] = y;
    rear++;
    vis[x][y] = true;
    dis[x][y] = 1;

    while (front < rear) {
        int cur_x = queue[front][0];
        int cur_y = queue[front][1];
        front++;

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (vis[nx][ny] || board[nx][ny] == '0')
                continue;

            queue[rear][0] = nx;
            queue[rear][1] = ny;
            rear++;

            vis[nx][ny] = true;
            dis[nx][ny] = dis[cur_x][cur_y] + 1;
        }
    }
}
