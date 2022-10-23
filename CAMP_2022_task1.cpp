#include <iostream>
#include <vector>
#include <ctime>

float FindDeterm(const std::vector<std::vector<int>>& matrix)
{
	return (matrix[0][0] * matrix[1][1] * matrix[2][2]) + (matrix[1][0] * matrix[2][1] * matrix[0][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][0]) -
		(matrix[0][2] * matrix[1][1] * matrix[2][0]) - (matrix[0][0] * matrix[1][2] * matrix[2][1]) - (matrix[0][1] * matrix[1][0] * matrix[2][2]);

}

int main()
{
	srand(time(0));

	std::vector<std::vector<int>> matrixA(3, std::vector<int>(3));
	std::vector<int> matrixB(3);
	std::vector<float> matrixX(3);
	int determ = 0;

	std::cout << "Matrix A:" << std::endl;
	for (auto& el : matrixA)
		for (auto& tmp : el)
			tmp = rand() % 10;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
			std::cout << matrixA[j][i] << ' ';
		std::cout << std::endl;
	}

	std::cout << std::endl << "Matrix B:" << std::endl;
	for (auto& el : matrixB)
	{
		el = rand() % 10;
		std::cout << el << std::endl;
	}

	determ = FindDeterm(matrixA);

	for (int i = 0; i < 3; ++i)
	{
		std::swap(matrixA[i], matrixB);
		matrixX[i] = FindDeterm(matrixA) / determ;
		std::swap(matrixA[i], matrixB);
	}

	std::cout << std::endl << "Matrix X:" << std::endl;
	for (auto& el : matrixX)
		std::cout << el << std::endl;

	return 0;
}