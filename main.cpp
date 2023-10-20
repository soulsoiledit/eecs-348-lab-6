#include <fstream>
#include <iostream>

const int SIZE = 100;

// function prototypes
void read_matrix(int first_matrix[SIZE][SIZE], int second_matrix[SIZE][SIZE],
                 int size, const std::string &filename);
void print_matrix();
void add_matrices();
void subtract_matrices();
void multiply_matrices();

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
                 int size, const std::string &filename) {
  std::ifstream File(filename);

  std::string myText;
  while (getline (File, myText)) {
    // Output the text from the file
    std::cout << myText;
  }

  File.close();
}
// functions go here
