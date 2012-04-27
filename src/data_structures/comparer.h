#pragma once

template <typename T>
class Comparer
{
public:
	static bool Equals(const T& item1, const T& item2);
};

template <typename T>
class Comparer<T*>
{
public:
	static bool Equals(const T* item1, const T* item2);
};
