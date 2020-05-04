#pragma once

#include <stddef.h>

#define ENTROPY_EFAULT (int) 1

#define ENTROPY_EIO (int) 2

extern int GetEntropy (void* buffer, size_t length);
