#include <iostream>


template<class T>

class Table {
private:
	T** arr;
	size_t rows;
	size_t columns;
public:
	Table(size_t Numb_rows, size_t Numb_colum) :rows(Numb_rows), columns(Numb_colum) {
		arr = new T*[rows];
		for (size_t i = 0; i < rows; ++i) {
			arr[i] = new T[columns];
		}
	}


	 T* operator[](size_t index) const {
		return arr[index];
	}

	T* operator[](size_t index) {
		return arr[index];
	}
	
	size_t Size() const {
		return rows * columns;
	}


	~Table() {
		for (size_t i = 0; i < rows; ++i)
			delete[] arr[i];
		delete[] arr;
	}


};





int main() {

	Table<int> table(3, 3);
	table[0][0] = 1;
	table[0][1] = 2;
	table[0][2] = 3;
	table[1][0] = 4;
	table[1][1] = 5;
	table[1][2] = 6;
	table[2][0] = 7;
	table[2][1] = 8;
	table[2][2] = 9;

	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < 3; ++j) {
			std::cout << table[i][j] << " ";
		}
		std::cout << std::endl;
	}


	std::cout << "Size of the table: " << table.Size() << std::endl;

	return 0;
}