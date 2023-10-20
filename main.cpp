#include <fstream>
#include <iostream>

const int MAX_SIZE = 100;

void read_matrix(int first_matrix[MAX_SIZE][MAX_SIZE], int second_matrix[MAX_SIZE][MAX_SIZE], int &size, const std::string &filename);
void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int &size);
void add_matrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int &size, int result[MAX_SIZE][MAX_SIZE]);
void subtract_matrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int &size, int result[MAX_SIZE][MAX_SIZE]);
void multiply_matrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int &size, int result[MAX_SIZE][MAX_SIZE]);

int main() {
  int first_matrix[MAX_SIZE][MAX_SIZE];
  int second_matrix[MAX_SIZE][MAX_SIZE];
  int result_matrix[MAX_SIZE][MAX_SIZE];
  int size;

  std::printf("Aryan Kevat\n");
  std::printf("Lab #6: Matrix manipulation\n\n");

  read_matrix(first_matrix, second_matrix, size, "input");
  std::cout << "Matrix A:\n";
  print_matrix(first_matrix, size);
  std::cout << "\nMatrix B:\n";
  print_matrix(second_matrix, size);

  std::cout << "\nMatrix Sum (A + B):\n";
  add_matrices(first_matrix, second_matrix, size, result_matrix);
  print_matrix(result_matrix, size);

  std::cout << "\nMatrix Product (A * B):\n";
  multiply_matrices(first_matrix, second_matrix, size, result_matrix);
  print_matrix(result_matrix, size);

  std::cout << "\nMatrix Difference (A - B):\n";
  subtract_matrices(first_matrix, second_matrix, size, result_matrix);
  print_matrix(result_matrix, size);

  return 0;
}

void read_matrix(int first_matrix[MAX_SIZE][MAX_SIZE], int second_matrix[MAX_SIZE][MAX_SIZE], int &size, const std::string &filename) {
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

void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int &size) {
  int padding[MAX_SIZE] = {};
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      std::string num_str = std::to_string(matrix[i][j]);
      if (num_str.length() > padding[j]) {
        padding[j] = num_str.length();
      }
    }
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      std::printf("%*d ", padding[j], matrix[i][j]);
    }
    std::cout << "\n";
  }
}

void add_matrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int &size, int result[MAX_SIZE][MAX_SIZE]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      result[i][j] = matrixA[i][j] + matrixB[i][j];
    }
  }
}

void subtract_matrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int &size, int result[MAX_SIZE][MAX_SIZE]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      result[i][j] = matrixA[i][j] - matrixB[i][j];
    }
  }
}

void multiply_matrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int &size, int result[MAX_SIZE][MAX_SIZE]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      int dot_product = 0;
      for (int k = 0; k < size; k++) {
        dot_product += matrixA[i][k] * matrixB[k][j];
      }
      result[i][j] = dot_product;
    }
  }
}
