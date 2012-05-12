#pragma once

class MatrixTests;

template <typename T>
class Matrix
{
private:
	FRIEND_TEST(MatrixTests, CreateMatrixSquare);
	FRIEND_TEST(MatrixTests, CreateMatrixNonSquare);

public:
	Matrix(size_t length):
	  m_nRows(length),
	  m_nCols(length),
	  m_buffer(null)
	{
		Init();
	}

	Matrix(size_t rows, size_t cols):
	  m_nRows(rows),
	  m_nCols(cols),
	  m_buffer(null)
	{
		Init();
	}

	~Matrix()
	{
		if (m_buffer != null)
		{
			delete[] m_buffer;
		}
	}

	const T& Get(size_t i, size_t j);
	void Set(size_t i, size_t j, const T& value);
	
#ifdef DBG
	size_t GetBufferLength() { return m_nBufferLength; }
#endif

private:
	void Init();
	size_t GetBufferIndex(size_t i, size_t j) 
	{ 
		Assert(i < m_nRows);
		Assert(j < m_nCols);

		return (i * m_nCols) + j; 
	}

	T* m_buffer;
#ifdef DBG
	size_t m_nBufferLength;
#endif

	size_t m_nRows;
	size_t m_nCols;
};