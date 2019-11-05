//
// Created by Bill on 5/11/2019.
//
#include <stdlib.h>
#include "uf.h"

void Initial(int N) {
    count = N;
    id = (int *) calloc(N, sizeof(int));
    for (int i = 0; i < N; ++i) {
        id[i] = i;
    }
}
boolean Connected(int p, int q) {
    return Find(p) == Find(q);
}

int Find(int p) {

}
void Union(int p, int q) {

}
