#include <iostream>
#include <vector>

float FindDeterm(const std::vector<std::vector<int>>& matrix)
{
	return (matrix[0][0] * matrix[1][1] * matrix[2][2]) + (matrix[1][0] * matrix[2][1] * matrix[0][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][0]) -
		(matrix[0][2] * matrix[1][1] * matrix[2][0]) - (matrix[0][0] * matrix[1][2] * matrix[2][1]) - (matrix[0][1] * matrix[1][0] * matrix[2][2]);
}

int main()
{
	std::vector<std::vector<int>> matrixA(3, std::vector<int>(3));
	std::vector<int> matrixB(3);
	std::vector<float> matrixX(3);
	int determ = 0;

	// Fill in matrix A //
	std::cout << "Fill in matrix A:" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << "A[" << i << "][" << j << "] = ";
			std::cin >> matrixA[j][i];
		}
		std::cout << std::endl;
	}

	// Fill in matrix B //
	std::cout << "Fill in matrix B:" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "B[" << i << "][" << 0 << "] = ";
		std::cin >> matrixB[i];
	}

	// Find determinant of 3x3 matrix //
	determ = FindDeterm(matrixA);

	// Formation of matrix X //
	for (int i = 0; i < 3; ++i)
	{
		std::swap(matrixA[i], matrixB);
		matrixX[i] = FindDeterm(matrixA) / determ;
		std::swap(matrixA[i], matrixB);
	}

	// Print matrix X //
	std::cout << std::endl << "Matrix X:" << std::endl;
	for (auto& el : matrixX)
		std::cout << el << std::endl;

	return 0;
}