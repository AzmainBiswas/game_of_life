#ifndef ARRAY_H_
#define ARRAY_H_

// for creating array
int **CreateArray(int hight, int width);

// fill value in array
void FillArray(int **array, int hight, int width, int fill_value);

// for free array
void DestroyArray(int **array);

// get the neighbors
int GetNBD(int **array, int i, int j, int height, int width);

// for copying array
void CopyArray(int **dst, int **src, int hight, int width);

// set random state
void SetRandomState(int **array, int hight, int width);

// update state
void UpadteState(int **array, int hight, int width);

#endif
