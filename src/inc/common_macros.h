#pragma once

#if _DEBUG
#define DBG 1
#endif

#ifdef _MSC_VER
#define MSVC_BUILD 1
#endif

#define null NULL

#ifdef UNICODE
typedef wchar_t CharType;
#else
typedef char CharType;
#endif

#ifndef FRIEND_TEST
#define FRIEND_TEST(testCaseName, testCase)
#endif

inline void Assert(bool condition) {
	_ASSERTE(condition);
}

inline void Assert(bool condition, CharType* msg) {
	_ASSERT_EXPR(condition, msg);
}

#ifdef MSVC_BUILD
// size_t is define as a part of the Windows headers in VC++
// g++'s stdlib defines it- to avoid redefinition, we typedef
// only if we're in VC++
typedef unsigned int size_t;

// Since VC++ and g++ process templates differently, sometimes
// VC++ requires the use of the typename keyword to resolve a type
// while g++ complains that it is an illegal use of said keyword
// The VCTYPENAME macro is used when we need to use typename simply
// to calm VC++ down
#define VCTYPENAME typename
#else
#define VCTYPENAME 
#endif

typedef void* Handle;

// Need to have custom no-throwing alloc
#include <new>