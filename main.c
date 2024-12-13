#include <stdio.h>
#include <string.h>
#include "mazesolution.h"

int main() {
    printf("The first line contains two integers N and M (2 <= N, M <= 100).\n");
    printf("The next N lines each contain M integers representing the maze.\n");
    printf("The integers are provided without spaces between them.\n");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
    }

    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));

    bfs(0, 0);

    printf("%d\n", dis[n - 1][m - 1]);

    return 0;
}
