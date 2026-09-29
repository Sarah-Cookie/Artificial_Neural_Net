#include <iostream>
#include <vector>
#include <cstdint>
#include <stdexcept>

template<class size_t> class Matrix{
public:
		Matrix(uint32_t sizex, uint32_t sizey)

		size_t &operator[](uint32_t entry_x, uint32_t entry_y);
		size_t operator[](uint32_t entry_x, uint32_t entry_x) const;
		size_t operator[](uint32_t itterator);
		this* operator+=(Matrix init1);

		friend Matrix operator*(Matrix init_1, Matrix init_2);
		friend Matrix operator+(Matrix init_1, Matrix init_2);
		friend Matrix operator-(Matrix init_1, Matrix init_2);
		friend Matrix operator/(Matrix init_1, Matrix init_2);
		
		uint32_t len();
		uint32_t get_x(){return size_x;}
		uint32_t get_y(){return size_y;}
		void itt_func(void (*func_ptr)(Matrix init)); //Takes a function pointer, function must return void
private:
		vector<size_t> *ptr;
		uint32_t size_x; //arr of arr
		uint32_t size_y; //values of lower arr
		void throw_size(Matrix *init_1);
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
void throw_size(Matrix *init_1)
{
	
		std::throw runtime_error("Matrix: Invalid size operations. ("+ size_x +" x "+ size_y + 
				") and (" init_1.get_x() + " x " + init_1.get_y() + ").");

}
this* operator+=(Matrix init_1){
		
		if(size_x != init_1.get_x() || size_y != init_1.get_y())
		{
				throw_size(&init_1);
		}

		for(int i{}; i<this.len(); i++)
		{
				(this->*ptr+1) += init_1[i];
		}
}

size_t Matrix::operator[](uint32_t entry_x, uint32_t entry_y) const
{
		return *ptr + (entry_x * size_x + entry_y);
}

size_t operator[](uint32_t itterator)
{
		return *ptr + itterator;
}


Matrix operator+(Matrix init_1, Matrix init_2)
{
		Matrix temp();

		//Finish the operator funcs then add code for += -= and .T() then we should be zen for now.
}
