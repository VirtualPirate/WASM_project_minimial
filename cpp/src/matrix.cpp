#include <iostream>
#include "matrix.hpp"

int main(){
	std::cout << "How are you" << std::endl;
	// Matrix<int> matrix_0{
	// 	{1,2,3},
	// 	{3,4,5},
	// 	{6,7,8}
	// };

	// Matrix<int> matrix_1{
	// 	{1,2,3},
	// 	{3,4,5},
	// 	{6,7,8}
	// };

	// Matrix<int> matrix_2{
	// 	{1,2,3},
	// 	{3,0,5},
	// 	{6,7,8}
	// };

	// Matrix<int> matrix_3{
	// 	{2,5},
	// 	{8,10}
	// };

	// Matrix<int> matrix_4{
	// 	{5,4},
	// 	{50, 40}
	// };

	// // matrix_0.print();
	// std::cout << matrix_0[0][2] << std::endl;
	// std::cout << matrix_0[2][1] << std::endl;
	// std::cout << matrix_0[2][0] << std::endl;
	// std::cout << matrix_0[1][1] << std::endl;
	// std::cout << matrix_0[1][0] << std::endl;
	// std::cout << matrix_0[2][2] << std::endl;

	// std::cout << matrix_0 << std::endl;
	// std::cout << (matrix_0 == matrix_1) << std::endl;
	// std::cout << (matrix_2 == matrix_1) << std::endl;

	// std::cout << (matrix_0 + matrix_1) << std::endl;

	// std::cout << (matrix_3 * matrix_4) << std::endl;

	return 0;
}


extern "C" int hello(){
	return 42;
}

extern "C" {
	char* greet(){
		return "Hello ";
	}
}