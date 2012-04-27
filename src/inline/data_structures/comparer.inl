#include "../../base.h"

#include <cstring>

template <typename T>
bool Comparer<T>::Equals(const T& t1, const T& t2)
{
	return (memcmp(&t1, &t2, sizeof(T)) == 0);
}

template <typename T>
bool Comparer<T*>::Equals(const T* t1, const T* t2)
{
	return (t1 == t2);
}
