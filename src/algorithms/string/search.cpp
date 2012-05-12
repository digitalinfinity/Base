#pragma once

#include <base.h>
#include <tchar.h>
#include <algorithm>

namespace String {
	/*
	 * If string1 = length m and string 2 = length n
	 * We have a m+1 x n+1 matrix
	 * 0, 0 = 0
	 * m, n = distance
	 */
	int LevenshteinDistance(CharType* string1, CharType* string2)
	{
		size_t m = _tcslen(string1);
		size_t n = _tcslen(string2);

		Matrix<size_t> distances(m + 1, n + 1);
		for (size_t i = 0; i <= m; i++)
		{
			distances.Set(i, 0, i);
		}
		for (size_t j = 0; j <= n; j++)
		{
			distances.Set(0, j, j);
		}

		for (size_t j = 1; j <= n; j++)
		{
			for (size_t i = 1; i <= m; i++)
			{
				if (string1[i - 1] == string2[j - 1])
				{
					distances.Set(i, j, distances.Get(i - 1, j - 1));
				}
				else
				{
					size_t minDistance = std::min(distances.Get(i - 1, j) + 1, // Deletion
											      std::min(distances.Get(i, j - 1) + 1, // Insertion
														   distances.Get(i - 1, j - 1) + 1)); // Substitution

					distances.Set(i, j, minDistance);
				}
			}
		}

		return distances.Get(m, n);
	}
}