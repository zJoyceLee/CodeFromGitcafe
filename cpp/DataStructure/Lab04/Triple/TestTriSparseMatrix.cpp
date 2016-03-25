#include "TriSparseMatrix.h"

template <typename T>
void printMatrix(int row, int col, const TriSparseMatrix<T> & matrix) {
    for(row = 0; row < matrix.GetRows(); ++row) {
        for(col = 0; col < matrix.GetCols(); ++col) {
            T value;
            matrix.GetElem(row, col, value);
            std::cout << value << '\t';
        }
        std::cout << std::endl;
    }
}

int main(void)
{
    try
	{
		const int a_rs = 7, a_cs = 6;
		const int b_rs = 7, b_cs = 6;
		const int c_rs = a_rs, c_cs = a_cs;
		TriSparseMatrix<int> a(a_rs, a_cs);
		int m[a_rs][a_cs] = {
			15,	 0,	 0,	22,	 0, -5,
			 0,	11,	 3,	 0,	 0,  0,
			 0,	 0,	 0,	 6,	 0,  0,
			 0,	 0,	 0,	 0,	 0,  0,
		    91,	 0,	 0,	 0,	 0,  0,
             0,  7,  0,  0,  0,  0,
             0,  0, 28,  0,  0,  0
		};

		TriSparseMatrix<int> b(b_rs, b_cs);
		int n[b_rs][b_cs] = {
          -100,  1,  0,  0,  0,  6,
            -1,  0,  0,  0,  0,  0,
             0,  0,  0,  3,  0,  1,
             0,  0,  1,  0,  0,  0,
             0,  0,  0,  0,  0, 32,
             0,  0,  0,  0,  0,  0,
             1,  0,  0,  0,  0,  0
		};

		for (int i = 0; i < a_rs; i++)
			for (int j = 0; j < a_cs; j++)
				a.SetElem(i, j, m[i][j]);
		for (int x = 0; x < b_rs; ++x)
			for (int y = 0; y < b_cs; ++y)
				b.SetElem(x, y, n[x][y]);


		std::cout << "Matrix a: " << std::endl;
		printMatrix(a_rs, a_cs, a);
		std::cout << "row: " << a.GetRows() << std::endl;
		std::cout << "col: " << a.GetCols() << std::endl;
		std::cout << "non-zeros: " << a.GetNum() << std::endl;

		a.SetElem(0, 0, 100);
		std::cout << "set element (0, 0) to 100: " << std::endl;
		printMatrix(a_rs, a_cs, a);

		int i_data;
		a.GetElem(0, 0, i_data);
        std::cout << "get element (0, 0): " << i_data << std::endl;

        std::cout << "Matrix a's transposed matrix: " << std::endl;
        // a.SimpleTranspose(b);
        TriSparseMatrix<int> a_transposed(a_cs, a_rs);
		a.FastTranspose(a_transposed);
		printMatrix(a_cs, a_rs, a_transposed);

        std::cout << "Matrix b: " << std::endl;
		printMatrix(b_rs, b_cs, b);

        TriSparseMatrix<int> c(c_rs, c_cs);
        std::cout << "Matrax_a add Matrix_b: " << std::endl;
        c = a + b;
        printMatrix(c_rs, c_cs, c);

    }
	catch (Error & err)
	{
		err.Show();
	}

	return 0;
}


