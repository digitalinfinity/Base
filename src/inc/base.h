#pragma once

#define BASE_VERSION 0.1
#include <crtdbg.h>

#include "common_macros.h"

/**
 * Macros to control what to include
 *
 * BASE_NO_DATA_STRUCTURES: Skips including any data structure headers
 *   BASE_NO_LINKED_LIST: Skips including the linked list data structure
 */

#include "util/Ptr.h"
#include "util/Log.h"

#ifndef BASE_NO_DATA_STRUCTURES
#include "data_structures/data_structures.h"
#endif

#ifndef BASE_NO_ALGORITMS
#include "algorithms/algorithms.h"
#endif
