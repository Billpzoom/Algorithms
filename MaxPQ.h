//
// Created by Bill on 27/11/2019.
//

#ifndef INC_131_ALGORITHMS_MAXPQ_H
#define INC_131_ALGORITHMS_MAXPQ_H

void init(int maxN);
_Bool isEmpty();
void insert(int *pq, int v);
int delMax(int *pq);
_Bool less(int *pq, int i, int j);
void exch(int *pq, int i, int j);
void swim(int *pq, int k);
void sink(int *pq, int k, int end);
void sort(int *pq);
#endif //INC_131_ALGORITHMS_MAXPQ_H
