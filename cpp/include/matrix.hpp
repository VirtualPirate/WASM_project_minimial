#ifndef Matrix_H
#define Matrix_H

#include <initializer_list>
#include <stdexcept>
#include <iostream>

template <typename T>
class Matrix {

	T* array;
	size_t row_length;
	size_t column_length;
	size_t no_of_elements;

	template <typename Type>
	friend std::ostream& operator<<(std::ostream&, const Matrix<Type>&);

public:

	Matrix() : array{ nullptr }, row_length{}, column_length{}{
	}

	Matrix(std::initializer_list<std::initializer_list<T>> list_) {
		row_length = list_.size();
		column_length = list_.begin()->size();
		no_of_elements = row_length * column_length;

		for (auto& each : list_) {
			if (each.size() != column_length)
				throw std::runtime_error{ "The column size is not same" };
		}

		array = new T[no_of_elements]{};

		size_t index = 0;
		for (auto& each_list : list_) {
			for (auto& each_element : each_list) {
				array[index] = each_element;
				index++;
			}
		}
	}

	Matrix(size_t row, size_t column) {
		array = new T[row * column]{};
		row_length = row;
		column_length = column;
		no_of_elements = row_length * column_length;
	}

	Matrix(const Matrix<T>& lvalue) {
		array = new T[no_of_elements];
		memcpy(array, lvalue.array, sizeof(T) * no_of_elements);
		row_length = lvalue.row_length;
		column_length = lvalue.column_length;
		no_of_elements = lvalue.no_of_elements;
	}
	Matrix& operator=(const Matrix<T>& lvalue) {
		if (array) delete[] array;
		array = new T[no_of_elements];
		memcpy(array, lvalue.array, sizeof(T) * no_of_elements);
		row_length = lvalue.row_length;
		column_length = lvalue.column_length;
		no_of_elements = lvalue.no_of_elements;

		return *this;
	}

	Matrix(Matrix<T>&& rvalue) {
		array = rvalue.array;
		row_length = rvalue.row_length;
		column_length = rvalue.column_length;
		no_of_elements = rvalue.no_of_elements;

		rvalue.array = nullptr;
	}

	Matrix& operator=(Matrix<T>&& rvalue) {
		if (array) delete[] array;

		array = rvalue.array;
		row_length = rvalue.row_length;
		column_length = rvalue.column_length;
		no_of_elements = rvalue.no_of_elements;

		rvalue.array = nullptr;

		return *this;
	}

	T* operator[](size_t index) {
		return &(array[column_length * index]);
	}

	T* const operator[](size_t index) const {
		return &(array[column_length * index]);
	}

	bool operator==(const Matrix<T>& other) const {
		if (this->same_order(other)) {

			for (size_t current_index = 0; current_index < no_of_elements; current_index++) {

				if (array[current_index] != other.array[current_index])
					return false;
			}
			return true;
		}
		return false;
	}

	bool operator!=(const Matrix<T>& other) const {
		return !(*this == other);
	}

	bool same_order(const Matrix<T>& other) const {
		return row_length == other.row_length && column_length == other.column_length;
	}

	bool is_multiplicable(const Matrix<T>& other) const {
		return column_length == other.row_length;
	}

	Matrix<T> operator+(const Matrix<T>& other) const {
		if (this->same_order(other)) {
			Matrix result(column_length, row_length);
			for (size_t current_index = 0; current_index < no_of_elements; current_index++)
				result.array[current_index] = std::move(this->array[current_index] + other.array[current_index]);
			return result;
		}
		else
			throw std::runtime_error{ "[Matrix::operator+] : The order of the Matrix is not similar" };
	}

	Matrix<T> operator*(const Matrix<T>& other) const {
		if (is_multiplicable(other)) {
			Matrix result{ row_length, other.column_length };
			for (size_t each_row = 0; each_row < row_length; each_row++) {
				for (size_t each_column = 0; each_column < other.column_length; each_column++) {
					for (size_t row_index = 0; row_index < row_length; row_index++)
						result[each_row][each_column] = std::move(result[each_row][each_column] + other[row_index][each_column] * (*this)[each_row][row_index]);
				}
			}
			return result;
		}
		else
			throw std::runtime_error{ "The mutiplication is not possible" };
	}

	Matrix<T> operator*(const T& other) const {
		Matrix result{ column_length, row_length };
		for (size_t current_index = 0; current_index < no_of_elements; current_index++)
			result.array[current_index] = std::move(result.array[current_index] * other);
		return result;
	}

	~Matrix() { delete[] array; }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& other)
{
	for (size_t row_index = 0; row_index < other.row_length; row_index++) {
		os << "[ ";
		for (size_t column_index = 0; column_index < other.column_length; column_index++) {
			if (column_index + 1 < other.column_length)
				os << other[row_index][column_index] << ", ";
			else
				os << other[row_index][column_index] << " ]\n";
		}
	}

	return os;
}

#endif
