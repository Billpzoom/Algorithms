//
// Created by Bill on 4/12/2019.
//
#include <stdlib.h>
#include <string.h>
#include "BinarySerchST.h"


void Bi_Init(int maxN) {
    N = maxN;
    bi_keys = (char **) malloc(sizeof(char) * 64 * maxN);
    values = (int *) malloc(sizeof(int) * maxN);
}

int bi_size()
{
    return N;
}

int bi_get(char *key) {
    int i = rank(key);
    if (i < N && strcmp(bi_keys[i], key) == 0) {
        return values[i];
    } else{
        return 0;
    }
}

 int rank(char *key) {
     int lo = 0, hi = N - 1;
     while (lo <= hi) {
         int mid = lo + (hi - lo) / 2;
         int cmp = strcmp(key, bi_keys[mid]);
         if (cmp < 0)hi = mid - 1;
         else if (cmp > 0)lo = mid + 1;
         else return mid;
     }
     return lo;
 }

 void put(char *key, int val) {
     int i = rank(key);
     if (i < N && strcmp(bi_keys[i], key) == 0) {
         values[i] = val;
         return;
     }
     N = N + 1;
     char **addKeys = (char **) malloc(sizeof(char) * 64 * (N));
     int *addValues = (int *) malloc(sizeof(int) * (N));
     for (int j = 0; j < N; ++j) {
         if (j < i) {
             addKeys[j] = (char *) malloc(sizeof(char) * 64);
             strcpy(addKeys[j], bi_keys[j]);
             addValues[j] = values[j];
         } else if (j > i) {
             addKeys[j] = (char *) malloc(sizeof(char) * 64);
             strcpy(addKeys[j], bi_keys[j - 1]);
             addValues[j] = values[j - 1];
         } else {
             addKeys[i] = (char *) malloc(sizeof(char) * 64);
             strcpy(addKeys[i], key);
             addValues[i] = val;
         }
     }
     bi_keys = addKeys;
     values = addValues;
 }

 void bi_delete(char *key) {
     int i = rank(key);
     if (i < N && strcmp(bi_keys[i], key) == 0) {
         N = N - 1;
         char **deletedKeys = (char **) malloc(sizeof(char) * 64 * N);
         int *deletedValues = (int *) malloc(sizeof(int) * N);
         for (int j = 0; j < N; ++j) {
             if (j < i) {
                 deletedKeys[j] = (char *) malloc(sizeof(char) * 64);
                 strcpy(deletedKeys[j], bi_keys[j]);
                 deletedValues[j] = values[j];
             } else {
                 deletedKeys[j] = (char *) malloc(sizeof(char) * 64);
                 strcpy(deletedKeys[j], bi_keys[j + 1]);
                 deletedValues[j] = values[j + 1];
             }
         }
         bi_keys = deletedKeys;
         values = deletedValues;
     }
 }



