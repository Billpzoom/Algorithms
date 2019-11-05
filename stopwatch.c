//
// Created by Bill on 4/11/2019.
//

#include <windows.h>
#include <stdio.h>

#include "stopwatch.h"

void Start() {
    QueryPerformanceFrequency(&freq);
    printf("frequency of pc is %d\n", freq.QuadPart);
    QueryPerformanceCounter(&start_t);
}

void Stop() {
    QueryPerformanceCounter(&stop_t);
    exe_time = 1e3 * (stop_t.QuadPart - start_t.QuadPart) / freq.QuadPart;
}

