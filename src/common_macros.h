#pragma once

#define null NULL
#define Assert assert

#ifdef _MSC_VER
typedef unsigned int size_t;
#define VCTYPENAME typename
#else
#define VCTYPENAME 

#endif

typedef void* Handle;

// Need to have custom no-throwing alloc
#include <new>