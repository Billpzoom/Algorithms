//
// Created by Bill on 4/12/2019.
//

#ifndef INC_131_ALGORITHMS_BINARYSERCHST_H
#define INC_131_ALGORITHMS_BINARYSERCHST_H
char **bi_keys;
int *values;
int N;

void Bi_Init(int maxN);
int bi_size();
int bi_get(char *key);
int rank(char *key);
void put(char *key, int value);
void bi_delete(char *key);

#endif //INC_131_ALGORITHMS_BINARYSERCHST_H
