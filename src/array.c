#include "../include/array.h"
#include <stdlib.h>

int **CreateArray(int height, int width) {
  // Allocate memory for the values of the 2D array

  int *values = calloc(width * height, sizeof(int));
  // Allocate memory for the array of pointers
  int **array = malloc(height * sizeof(int *));

  // Set up the pointers to point to each row of the 2D array
  for (int i = 0; i < height; i++) {
    array[i] = values + i * width;
  }

  return array;
}

void FillArray(int **array, int hight, int width, int fill_value) {
  for (int i = 0; i < hight; i++) {
    for (int j = 0; j < width; j++) {
      array[i][j] = fill_value;
    }
  }
}

void DestroyArray(int **array) {
  free(*array);
  free(array);
}

// get the neighbors
int GetNBD(int **array, int i, int j, int height, int width) {
  int sum = 0;

  if (i == 0 && j == 0) {
    sum = array[i][j + 1] + array[i + 1][j] + //
          array[i + 1][j + 1];
  } else if (i == 0 && j == width - 1) {
    sum = array[i][j - 1] + //
          array[i + 1][j - 1] + array[i + 1][j];
  } else if (i == height - 1 && j == 0) {
    sum = array[i - 1][j] + array[i - 1][j + 1] + //
          array[i][j + 1];
  } else if (i == height - 1 && j == width - 1) {
    sum = array[i - 1][j - 1] + array[i - 1][j] + //
          array[i][j - 1];
  } else if (i == 0) {
    sum = array[i][j - 1] + array[i][j + 1] + //
          array[i + 1][j - 1] + array[i + 1][j] + array[i + 1][j + 1];
  } else if (i == height - 1) {
    sum = array[i - 1][j - 1] + array[i - 1][j] + array[i - 1][j + 1] + //
          array[i][j - 1] + array[i][j + 1];
  } else if (j == 0) {
    sum = array[i - 1][j] + array[i - 1][j + 1] + array[i][j + 1] + //
          array[i + 1][j] + array[i + 1][j + 1];
  } else if (j == width - 1) {
    sum = array[i - 1][j - 1] + array[i - 1][j] + array[i][j - 1] + //
          array[i + 1][j - 1] + array[i + 1][j];
  } else {
    sum = array[i - 1][j - 1] + array[i - 1][j] + array[i - 1][j + 1] + //
          array[i][j - 1] + array[i][j + 1] +                           //
          array[i + 1][j - 1] + array[i + 1][j] + array[i + 1][j + 1];
  }

  return sum;
}

// for copying array
void CopyArray(int **dst, int **src, int hight, int width) {
  for (int i = 0; i < hight; i++) {
    for (int j = 0; j < width; j++) {
      dst[i][j] = src[i][j];
    }
  }
}

// set random state
void SetRandomState(int **array, int hight, int width) {
  for (int i = 0; i < hight; i++) {
    for (int j = 0; j < width; j++) {
      array[i][j] = rand() % 2;
    }
  }
}

// update state
void UpadteState(int **array, int hight, int width) {
  // copy array
  int **copy_array = CreateArray(hight, width);
  CopyArray(copy_array, array, hight, width);

  for (int i = 0; i < hight; i++) {
    for (int j = 0; j < width; j++) {
      int total_nbd_elements = GetNBD(copy_array, i, j, hight, width);

      if (copy_array[i][j] == 0 && total_nbd_elements == 3) {
        array[i][j] = 1;
      } else if (copy_array[i][j] == 1 && (total_nbd_elements == 2 || total_nbd_elements == 3)) {
        array[i][j] = 1;
      } else if (total_nbd_elements < 2) {
        array[i][j] = 0;
      } else if (total_nbd_elements > 3) {
        array[i][j] = 0;
      }
    }
  }

  // destroy copy array;
  DestroyArray(copy_array);
}
