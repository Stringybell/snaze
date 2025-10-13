#include <iostream>

using namespace std;

// Creates a matrix of pointers with n rows and n columns

bool** matrix_maker(int rows, int columns){

    bool** matrix = new bool * [rows];

    for (int i = 0; i < rows ; i++){
        matrix[i] = new bool[columns];
    }

// Initialises the matrix as false
    for (int i = 0; i < rows ; i++){
        for (int x = 0; x < columns; x++){
            matrix[i][x] = false;
        }
    }


    return matrix;

}
void free_matrix(bool** matrix, int rows){
    for (int i = 0; i < rows; i++){
        delete matrix [i];
    }
    delete matrix;
}


int main() {
    int rows,columns;
    cin >> rows >> columns;

    bool** matrix = matrix_maker(rows,columns);

    for (int i = 0; i < rows ; i++){
        for (int x = 0; x < columns; x++){
            cout << matrix[i][x];
        }
        cout << "\n" ;
    }

    free_matrix(matrix, rows);


    return 0;
}
