#include <iostream>
#include "random"
using namespace std;

// Creates a matrix of pointers with n rows and n columns

bool* matrix_maker(int rows, int columns){

    bool* matrix = new bool [rows * columns];


// Initialises the matrix as false
    for (int i = 0; i < rows ; i++){
        for (int x = 0; x < columns; x++){
            matrix [i * columns + x ] = false;
        }
    }


    return matrix;

}
void free_matrix(bool* matrix){
    delete[] matrix;
}

int randmk(){
    int randomNum = rand() % 4;
    return randomNum;

}

int moving(bool* matrix, int& row, int& col, int rows, int columns, int valueinp) {
    /* Using the C++11 <random> library to generate a value from 1 to 4:
    0 = up | 1 = down | 2 = left | 3 = right */
    int value = valueinp;


    switch (value) {
        case 0:
           if (row>0) row--;
            break;
        case 1:
            if (row < rows - 1) row++;
            break;
        case 2:
            if (col>0) col--;
            break;
        case 3:
            if (col < columns - 1) col++;
            break;





    }
    matrix[row * columns + col] = true;
    return value; // Range [0, 3]

}

int main() {
    int rows,columns;


    cin >> rows >> columns;


    bool* matrix = matrix_maker(rows,columns);


    for (int i = 0; i < rows ; i++){
        for (int x = 0; x < columns; x++){
            cout << matrix[i * columns + x];

        }
        cout << "\n" ;
    }

    int row = 0, col = 0; // Starting position
    matrix[row * columns + col] = true;
    for (int i = 0; i < 4 ; i++){
        for (int x = 0; x < 4; x++){
            int valueinp = randmk();
            moving(matrix, row, col, rows, columns,valueinp);
            cout << moving(matrix, row, col, rows, columns,valueinp) << "\n";


        }

    }
    for (int i = 0; i < rows ; i++){
        for (int x = 0; x < columns; x++){
            cout << matrix[i * columns + x];

        }
        cout << "\n" ;
    }


    free_matrix(matrix);


    return 0;
}
