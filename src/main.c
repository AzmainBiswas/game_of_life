/*
 * Conway's Game of Life:
 *
 * The "Game of Life" is a cellular automaton devised by the British
 * mathematician John Horton Conway in 1970. It is a zero-player game, meaning
 * that its evolution is determined by its initial state, requiring no further
 * input. The game consists of a grid of cells, each of which can be in one of
 * two possible states: alive or dead.
 * RULL:
 *    1. Any live cell with fewer than two live neighbors dies, as if by underpopulation.
 *    2. Any live cell with two or three live neighbors lives on to the next generation.
 *    3. Any live cell with more than three live neighbors dies, as if by overpopulation.
 *    4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 *
 */

// includs
#include "../include/array.h"
#include <raylib.h>

#define FPS 10

// setting some variable
const int cell_size = 4;

// const int rows = 150;    // rows
// const int columns = 150; // width

const int rows = 1080;    // rows
const int columns = 720; // width

const int screen_width = (columns - 1) * cell_size;
const int screen_hight = (rows - 1) * cell_size;

void DrawCells(int **array, int hight, int width);
void ResetCells(int **array, int hight, int width);

int main() {
  InitWindow(screen_width, screen_hight, "Conway's Game Of Life");

  // lower FPS used to easily visualise the progress of each generation
  SetTargetFPS(FPS);

  // creating array
  int **cells = CreateArray(rows, columns);

  // set random inetial state
  SetRandomState(cells, rows, columns);
  DrawCells(cells, rows, columns);

  while (!WindowShouldClose()) {
    // press q to quite.
    SetExitKey(KEY_Q);

    // press R to restart the game.
    if (IsKeyPressed(KEY_R)) {
      ResetCells(cells, rows, columns);
    }

    UpadteState(cells, rows, columns);
    DrawCells(cells, rows, columns);
  }

  DestroyArray(cells);
  CloseWindow();
}

void DrawCells(int **array, int hight, int width) {
  BeginDrawing();
  ClearBackground(BLACK);

  for (int i = 0; i < hight; i++) {
    for (int j = 0; j < width; j++) {
      if (array[i][j] == 1) {
        DrawRectangle(i * cell_size, j * cell_size, cell_size, cell_size, WHITE);
      }
    }
  }

  EndDrawing();
}

void ResetCells(int **array, int hight, int width) {
  FillArray(array, hight, width, 0);
  SetRandomState(array, hight, width);
}
