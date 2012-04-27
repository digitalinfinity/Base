#pragma once

#define null NULL
#define Assert assert

typedef unsigned int size_t;
typedef void* Handle;

// Need to have custom no-throwing alloc
#include <new>