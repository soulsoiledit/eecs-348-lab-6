#include <fstream>
#include <iostream>

const int SIZE = 100;

// function prototypes
void read_matrix(int first_matrix[SIZE][SIZE], int second_matrix[SIZE][SIZE],
                 int size, const std::string &filename);
void print_matrix();
void add_matrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int &size, int result[SIZE][SIZE]);
void subtract_matrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int &size, int result[SIZE][SIZE]);
void multiply_matrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int &size, int result[SIZE][SIZE]);

int main() {
  int first_matrix[SIZE][SIZE];
  int second_matrix[SIZE][SIZE];
  int result_matrix[SIZE][SIZE];
  int size;

  read_matrix(first_matrix, second_matrix, size, "input");
  //
  //
  //
  //
  return 0;
}

void read_matrix(int first_matrix[SIZE][SIZE], int second_matrix[SIZE][SIZE],
                 int &size, const std::string &filename) {

  std::ifstream File(filename);
  File >> size;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
        File >> first_matrix[i][j];
    }
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
        File >> second_matrix[i][j];
    }
  }

  File.close();
}
// functions go here
void add_matrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int &size, int result[SIZE][SIZE]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
        result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

void subtract_matrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int &size, int result[SIZE][SIZE]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
        result[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
}

void multiply_matrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int &size, int result[SIZE][SIZE]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
        int dot_product = 0;
        for (int k = 0; k < size; k++) {
            dot_product += matrix1[i][k] * matrix2[k][j];
        }
        result[i][j] = dot_product;
    }
  }
}
