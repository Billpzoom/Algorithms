//
// Created by Bill on 5/11/2019.
//
#include <stdlib.h>
#include "uf.h"

void Initial(int N) {
    count = N;
    id = (int *) calloc(N, sizeof(int));
    sz = (int *) calloc(N, sizeof(int));
    for (int i = 0; i < N; ++i) {
        id[i] = i;
        sz[i] = 1;
    }
}
int Connected(int p, int q) {
    if( Find(p) == Find(q))
        return 1;
    return 0;
}

int Find(int p) {
    while (p != id[p])p = id[p];
    return p;
}
void Union(int p, int q) {
    int i = Find(p);
    int j = Find(q);
    if (i == j)return;

    if (sz[i] < sz[j]) {
        id[i] = j;
        sz[j] += sz[i];
    } else {
        id[j] = i;
        sz[i] += sz[j];
    }
    count--;
}
