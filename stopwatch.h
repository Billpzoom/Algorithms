//
// Created by 00000 on 5/11/2019.
//

#ifndef INC_131_ALGORITHMS_STOPWATCH_H
#define INC_131_ALGORITHMS_STOPWATCH_H

#include <windows.h>
#include <stdio.h>

double exe_time;
LARGE_INTEGER freq;
LARGE_INTEGER start_t,stop_t;
void Start();
void Stop();

#endif //INC_131_ALGORITHMS_STOPWATCH_H
