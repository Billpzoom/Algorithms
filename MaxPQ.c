//
// Created by Bill on 27/11/2019.
//
#include <stdlib.h>
#include "MaxPQ.h"

int N = 0;


void init(int maxN) {
    N = maxN;
}
_Bool isEmpty() {
    return N == 0;
}
void insert(int *pq, int v) {
    pq = (int *) realloc(pq, sizeof(int) * (++N));
    pq[N] = v;
    swim(pq, N);
}
int delMax(int *pq) {
    int max = pq[1];
    exch(pq, 1, N--);
    pq = (int *) realloc(pq, sizeof(int) * N);
    sink(pq, 1, N);
    return max;
}
_Bool less(int *pq, int i, int j) {
    return pq[i] < pq[j];
}
void exch(int *pq, int i, int j) {
    int t = pq[i];
    pq[i] = pq[j];
    pq[j] = t;
}
void swim(int *pq, int k) {
    while (k > 1 && less(pq, k / 2, k)) {
        exch(pq, k / 2, k);
        k = k / 2;
    }
}
void sink(int *pq, int k, int end) {
    while (2 * k <= end) {
        int j = 2 * k;
        if (j < end && less(pq, j, j + 1)) j++;
        if (!less(pq, k, j))break;
        exch(pq, k, j);
        k = j;
    }
}


void sort(int *pq){
    for (int k = N/2; k >= 1 ; k--) {
        sink(pq,k,N);
    }
    while (N>1){
        exch(pq,1,N--);
        sink(pq,1,N);
    }
}

