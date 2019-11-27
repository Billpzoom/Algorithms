//
// Created by Bill on 21/11/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"
#include <math.h>


void quick3way(int *a, int lo, int hi) {
    if (hi <= lo) return;
    int lt = lo, i = lo + 1, gt = hi;
    int v = a[lo];
    while (i <= gt) {
        if (a[i] < v) Exchange(a, lt++, i++);
        else if (a[i] > v) Exchange(a, i, gt--);
        else i++;
    }
    quick3way(a, lo, lt - 1);
    quick3way(a, gt + 1, hi);
}

void quick(int *a, int lo, int hi){
    if(hi <= lo) return;
    int j = Partition(a, lo, hi);
    quick(a,lo,j-1);
    quick(a,j+1,hi);
}

int Partition(int *a, int lo, int hi) {
    int i = lo, j = hi + 1;
    int v = a[lo];
    while (1) {
        while (Less(a[++i], v)) if (i == hi) break;
        while (Less(v, a[--j])) if (j == lo) break;
        if (i >= j) break;
        Exchange(a, i, j);
    }
    Exchange(a, lo, j);
    return j;
}

int *aux;

void LocalMerge(int *a, int lo, int mid, int hi) {
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; ++k) {
        aux[k] = a[k];
    }
    for (int l = lo; l <= hi; ++l) {
        if (i > mid) a[l] = aux[j++];
        else if (j > hi) a[l] = aux[i++];
        else if (Less(aux[j], aux[i])) a[l] = aux[j++];
        else a[l] = aux[i++];
    }
}

void mergebu(int *a, int len) {
    aux = (int *) malloc(sizeof(int) * len);
    for (int sz = 1; sz < len; sz = sz + sz) {
        for (int lo = 0; lo < len - sz; lo += sz + sz) {
            int h;
            if ((lo + sz + sz + 1) < (len - 1)) h = lo + sz + sz + 1;
            else h = len - 1;
            LocalMerge(a, lo, lo + sz - 1, h);
        }
    }
    free(aux);
}
void merge(int *a, int len) {
    aux = (int *) malloc(sizeof(int) * len);
    Merge(a, 0, len - 1);
    free(aux);
}

void Merge(int *a, int lo, int hi) {
    if (hi <= lo)
        return;

    int mid = lo + (hi - lo) / 2;

    Merge(a, lo, mid);
    Merge(a, mid + 1, hi);
    LocalMerge(a, lo, mid, hi);
}

void shell(int *a, int len) {
    int h = 1;
    while (h < len / 3) h = 3 * h + 1;
    while (h >= 1) {
        for (int i = h; i < len; ++i) {
            for (int j = i; j >= h && Less(a[j], a[j - h]); j -= h) {
                Exchange(a, j, j - h);
            }
        }
        h = h / 3;
    }
}

void insertion(int *a, int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = i; j > 0 && Less(a[j], a[j - 1]); j--) {
            Exchange(a,j,j-1);
        }
    }
}

void selection(int *a, int len)
{
    for (int i = 0; i < len ; ++i) {
        int min=i;
        for (int j = i+1; j < len; ++j) {
            if(Less(a[j],a[min])) min=j;
        }
        Exchange(a,i,min);
    }
}
int Less(int v, int w) {
    if (v < w) return 1;
    return 0;
}
void Exchange(int *a, int i,int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}
void Show(int *a, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", a[i]);
    }
    printf("\r\n");
}

int IsSorted(int *a,int len) {
    for (int i = 1; i < len; ++i) {
        if (Less(a[i], a[i - 1])) return 0;
    }
    return 1;
}

