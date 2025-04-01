#pragma once

#include <stdio.h>

//#define ENABLE_LOGGING 1  

#if ENABLE_LOGGING
#define LOG(msg, ...) printf("[LOG] " msg "\n", ##__VA_ARGS__)
#else
#define LOG(msg, ...)
#endif