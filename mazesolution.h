#ifndef MAZESOLUTION_H
#define MAZESOLUTION_H
#include<stdbool.h>
#define MAX 101

void bfs(int x, int y);

extern int dx[4];
extern int dy[4];
extern bool vis[MAX][MAX];
extern char board[MAX][MAX];
extern int dis[MAX][MAX];
extern int n, m;

#endif
