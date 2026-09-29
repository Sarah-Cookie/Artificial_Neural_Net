#include <iostream>
#include <vector>
#include <cstdint>

template<class size_t> class Matrix{
public:
		Matrix(uint32_t sizex, uint32_t sizey)

		size_t &operator[](uint32_t entry_x, uint32_t entry_y);
		size_t operator[](uint32_t entry_x, uint32_t entry_x) const;
		
		friend Matrix operator*(Matrix init_1, Matrix init_2);
		friend Matrix operator+(Matrix init_1, Matrix init_2);
		friend Matrix operator-(Matrix init_1, Matrix init_2);
		friend Matrix operator/(Matrix init_1, Matrix init_2);

		uint32_t len();

		void itt_func(void (*func_ptr)(Matrix init)); //Takes a function pointer, function must return void
private:
		vector<size_t> *ptr;
		uint32_t size_x; //arr of arr
		uint32_t size_y; //values of lower arr
};

Matrix::Matrix(uint32_t sizex, uint32_t sizey)
{
		vector<size_t> arr[sizex][sizey];
		ptr = arr;
		size_x = sizex;
		size_y = sizey;
}

uint32_t Matrix::len()
{
		return size_x * size_y;
}

size_t Matrix::operator[](uint32_t entry_x, uint32_t entry_y) const
{
		return *ptr + (entry_x * size_x + entry_y);
}

Matrix operator+(Matrix init_1, Matrix init_2)
{
		Matrix temp();

		//Finish the operator funcs then add code for += -= and .T() then we should be zen for now.
}
