#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <stdbool.h>

#define MAX 101

int main() {
    void *handle;
    void (*bfs)(int, int);
    int *n, *m;
    char (*board)[MAX];
    int (*dis)[MAX];
    bool (*vis)[MAX];
    char *error;


    printf("The first line contains two integers N and M (2 <= N, M <= 100).\n");
    printf("The next N lines each contain M integers representing the maze.\n");
    printf("The integers are provided without spaces between them.\n");


    handle = dlopen("./libmyal.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        exit(1);
    }

    bfs = dlsym(handle, "bfs");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Error: %s\n", error);
        dlclose(handle);
        exit(1);
    }


    n = dlsym(handle, "n");
    m = dlsym(handle, "m");
    board = dlsym(handle, "board");
    vis = dlsym(handle, "vis");
    dis = dlsym(handle, "dis");

    if (!n || !m || !board || !vis || !dis) {
        fprintf(stderr, "Error: Failed to load global variables\n");
        dlclose(handle);
        exit(1);
    }


    printf("Enter the size of the maze (n m): ");
    scanf("%d %d", n, m);

    if (*n <= 0 || *n > MAX || *m <= 0 || *m > MAX) {
        fprintf(stderr, "Error: n and m must be between 1 and %d\n", MAX);
        dlclose(handle);
        exit(1);
    }


    printf("Enter the maze (%d lines with %d characters each):\n", *n, *m);
    for (int i = 0; i < *n; i++) {
        scanf("%s", board[i]);
        for (int j = 0; j < *m; j++) {
            vis[i][j] = false;
            dis[i][j] = 0;
        }
    }


    bfs(0, 0);


    printf("Shortest path to range: %d\n", dis[*n - 1][*m - 1]);


    dlclose(handle);

    return 0;
}
