//
// Created by 00000 on 22/11/2019.
//

#ifndef INC_131_ALGORITHMS_SORTS_H
#define INC_131_ALGORITHMS_SORTS_H
int Less(int v, int w);
void Exchange(int *a, int i,int j);
void Show(int *a, int len);
int IsSorted(int *a,int len);
void selection(int *a,int len);
void insertion(int *a, int len);
void shell(int *a, int len);
void LocalMerge(int *a, int lo, int mid, int hi);
void Merge(int *a, int l, int hi);
void merge(int *a, int len);
void mergebu(int *a, int len);

#endif //INC_131_ALGORITHMS_SORTS_H
