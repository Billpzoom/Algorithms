//
// Created by Bill on 21/11/2019.
//
#include <stdio.h>
#include "sorts.h"


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

