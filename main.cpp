#include <iostream>
#include <iomanip>
using namespace std;

struct matrix
{
  int** data;       // Pointer to 2-D array that will simulate matrix
  int row, col;
};
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
//matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator+  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
					    // new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
					     // matrix with difference
   // change mat & return new matrix
matrix operator+= (matrix& mat, int scalar);
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
       	// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
       // and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);

       	// Print matrix  as follows (2 x 3)			4	 6 	  8
	       // and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
  int data1 [] = {1,2,3,4,5,6,7,8};
  int data2 [] = {13,233,3,4,5,6};
  int data3 [] = {10,100,10,100,10,100,10,100};

  matrix mat1, mat2, mat3;

  createMatrix (4, 2, data1, mat1);
  createMatrix (2, 3, data2, mat2);
  createMatrix (4, 2, data3, mat3);


  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;


  //cout << (mat3 - mat1) << endl;
  cout << (mat1 + mat3) << endl;
  cout<<(mat3 * mat1)<<endl;
  cout<<(mat1-mat3)<<endl;
  cout<<(mat3+2);
  cout<<(mat3-2);
  cout<<(mat3*3);
  //cout<< (mat1 + 3)<<endl;
 //cout<< (mat1 - 3)<<endl;
 //cout<< (mat1 * 2)<<endl;

/* The next code will not work until you write the functions
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;

  cout << (mat1 + mat3) << endl << endl;
  cout << (mat3 + mat3) << endl << endl;

  ++mat1;
  cout << mat1 << endl;

  mat1+= mat3 += mat3;
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;
  // Add more examples of using matrix
  // .......
*/
  return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data = new int* [row];

  for (int i = 0; i < row; i++)
    mat.data[i] = new int [col];

  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      mat.data[i][j] = num[i * col + j];

}
//
//_________________________________________
// overloading "cout" operator to print matrix in a proper way
ostream& operator<< (ostream& out, matrix mat)
{


    for (int i = 0; i< mat.row; i++)
    {
        for (int j = 0; j< mat.col; j++)
        {
            out << setw(4)<< mat.data[i][j] << setw(4);
        }
        out << endl;
    }
     return out;
}

//
//___________________________________________
//overloading "Cin" operator to get input from user

istream& operator>> (istream& in, matrix& mat)
{
    int _row = mat.row;
    int _col = mat.col;
    int elements[(_row * _col)];
    for (int i = 0; i < (_row * _col); i++)
    {
        in >> elements[i];
    }
    mat.data = new int* [_row];

    for (int i = 0; i < _row; i++)
        mat.data[i] = new int [_col];

    for (int i = 0; i < _row; i++)
        for (int j = 0; j < _col; j++)
            mat.data[i][j] = elements[i * _col + j];

    return in;
}
//
//____________________________________________

//20170260
//sum 2 matrices
matrix operator+  (matrix mat1, matrix mat2)
{
        matrix summation;
        summation.row = mat1.row;
        summation.col = mat1.col;
        summation.data = new int* [summation.row];
        for (int i = 0; i < summation.row; i++)
            summation.data[i] = new int [summation.col];
        for (int i = 0; i < summation.row; i++)
        {
            for (int j = 0; j < summation.col; j++)
                summation.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }

        return summation;

}
//difference 2 matrices
matrix operator-  (matrix mat1, matrix mat2)
{
    matrix diff;
    diff.row = mat1.row;
    diff.col = mat1.col;
    diff.data = new int* [diff.row];

        for (int i = 0; i < diff.row; i++)
        diff.data[i] = new int [diff.col];

        for (int i = 0; i < diff.row; i++)
            for (int j = 0; j < diff.col; j++)
                diff.data[i][j] = mat1.data[i][j] - mat2.data[i][j];

    return diff;
}
//Multiplication of 2 Matrices
matrix operator*  (matrix mat1, matrix mat2)
{
    matrix multi;
    multi.row = mat1.row;
    multi.col = mat1.col;
    multi.data = new int* [multi.row];

        for (int i = 0; i < multi.row; i++)
        multi.data[i] = new int [multi.col];

        /*for (int i = 0; i < multi.row; i++)
            for (int j = 0; j < multi.col; j++)
                multi.data[i][j] = mat1.data[i][j] - mat2.data[i][j];*/

        for(int i = 0; i < mat1.row; i++){

            for(int j = 0; j < mat2.col; j++)
                for(int k = 0; k < mat1.col; k++)
                    multi.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
        }

    return multi;
}

//Adding Scalar
matrix operator+  (matrix mat1, int scalar)
{
    matrix sumS;
    sumS.row = mat1.row;
    sumS.col = mat1.col;
    sumS.data = new int* [sumS.row];

    for (int i = 0; i < sumS.row; i++)
        sumS.data[i] = new int [sumS.col];

        for (int i = 0; i < sumS.row; i++)
            for (int j = 0; j < sumS.col; j++)
                sumS.data[i][j] = mat1.data[i][j] + scalar;
    return sumS;
}
//Subtracting Scalar
matrix operator-  (matrix mat1, int scalar)
{
    matrix subS;
    subS.row = mat1.row;
    subS.col = mat1.col;
    subS.data = new int* [subS.row];

    for (int i = 0; i < subS.row; i++)
        subS.data[i] = new int [subS.col];

        for (int i = 0; i < subS.row; i++)
            for (int j = 0; j < subS.col; j++)
                subS.data[i][j] = mat1.data[i][j] - scalar;
    return subS;
}
//Multiplying scalar
matrix operator*  (matrix mat1, int scalar)
{
    matrix multS;
    multS.row = mat1.row;
    multS.col = mat1.col;
    multS.data = new int* [multS.row];

    for (int i = 0; i < multS.row; i++)
        multS.data[i] = new int [multS.col];

        for (int i = 0; i < multS.row; i++)
            for (int j = 0; j < multS.col; j++)
                multS.data[i][j] = mat1.data[i][j] * scalar;
    return multS;
}

