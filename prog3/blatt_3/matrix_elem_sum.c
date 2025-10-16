#include <stdio.h>

double matrix_elem_sum(double matrix[], int n, int lengths[]) {
  double sum = 0; 
  int num_count = 1; 

  //finde die Anzahl der Einträge  
  for (int i = 0; i < n; i++){
    num_count *= lengths[i]; 
  }
  //Iteriere durch die Matrix anhand der Anzahl der Einträge 
  for (int i = 0; i < num_count; i++){
    sum += matrix[i]; 
  }
  //gib die Summe zurück 
  return sum; 
}

int main(void) {
  double matrix2d[3][2] = 
    { {111, 112}, 
      {121, 122}, 
      {131, 132} 
    };
  int lengths2d[2] = {3, 2};

  double matrix3d[2][3][4] = {
    { {111, 112, 113, 114}, {121, 122, 123, 124}, {131, 132, 133, 134} },
    { {211, 212, 213, 214}, {221, 222, 223, 224}, {231, 232, 233, 234} }
  };
  int lengths3d[3] = {2, 3, 4};

  printf("Sum of matrix2d = %f\n", matrix_elem_sum((double*)matrix2d, 2, lengths2d));  /* gibt 729 aus */
  printf("Sum of matrix3d = %f\n", matrix_elem_sum((double*)matrix3d, 3, lengths3d));  /* gibt 4140 aus */

  return 0;
}
