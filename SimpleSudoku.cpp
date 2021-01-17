/*
    A simple program the solves sudoku puzzles
*/

#include <iostream>

using namespace std;

const int SIZE = 9;

void printGrid(int grid[SIZE][SIZE])
{
     for(int row = 0; row < SIZE; row++)
    {  
        for(int col = 0; col < SIZE; col++)
        {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

bool isValid(int grid[SIZE][SIZE], int row, int col, int num)
{
    for(int index = 0; index < SIZE; index++)
    {
        if(grid[row][index] == num)
            return false;
    }

    for(int index = 0; index < SIZE; index++)
    {
        if(grid[index][col] == num)
            return false;
    }

    int startRow = row - row % 3, startCol = col - col % 3;

    for(int r = 0; r < 3; r++)
    {
        for(int c = 0; c < 3; c++)
        {
            if(grid[r + startRow][c + startCol] == num)
                return false;
        }
    }
    return true;
}

//Recursive function that will solve sudoku puzzle by checking every possiblility of numbers until it finds one that works
bool simpleSolve(int grid[SIZE][SIZE], int row, int col)
{
    //Returns true if at the last element in matrix
    if(row == SIZE - 1 && col == SIZE)
    {
        return true;
    }

    //Moves onto next row if past last element in the row
    if(col == SIZE)
    {
        row++;
        col = 0;
    }

    //Skips element if it is already filled with a value (0 means it's empty)
    if(grid[row][col] > 0)
    {
        return simpleSolve(grid, row, col + 1);
    }
    
    //Iterates through 1 - 9 and finds the values that will work in each empty element
    for(int num = 1; num <= SIZE; num++)
    {
        //If a value is valid, set the current element to that value
        if(isValid(grid, row, col, num))
        {
            grid[row][col] = num;

            //Recursivly repeats this process until the entire grid is solved
            if(simpleSolve(grid, row, col + 1))
            {
                return true;
            }
            
            //If not valid number, reset that element, loops back and checks with next number
            grid[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    //OG Grid
    // int grid[SIZE][SIZE] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
    //                          { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
    //                          { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
    //                          { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
    //                          { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
    //                          { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
    //                          { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
    //                          { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
    //                          { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    //Test Grids
    // int grid[SIZE][SIZE] = { {0, 0, 0, 2, 6, 0, 7, 0, 1},
    //                         {6, 8, 0, 0, 7, 0, 0, 9, 0},
    //                         {1, 9, 0, 0, 0, 4, 5, 0, 0},
    //                         {8, 2, 0, 1, 0, 0, 0, 4, 0},
    //                         {0, 0, 4, 6, 0, 2, 9, 0, 0},
    //                         {0, 5, 0, 0, 0, 3, 0, 2, 8},
    //                         {0, 0, 9, 3, 0, 0, 0, 7, 4},
    //                         {0, 4, 0, 0, 5, 0, 0, 3, 6},
    //                         {7, 0, 3, 0, 1, 8, 0, 0, 0} };

    int grid[SIZE][SIZE] = { {0, 2, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 6, 0, 0, 0, 0, 3},
                            {0, 7, 4, 0, 8, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 3, 0, 0, 2},
                            {0, 8, 0, 0, 4, 0, 0, 1, 0},
                            {6, 0, 0, 5, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 1, 0, 7, 8, 0},
                            {5, 0, 0, 0, 0, 9, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 4, 0} };

    
    printGrid(grid);
    cout << endl;

    if(simpleSolve(grid, 0, 0))
    {
        printGrid(grid);
    }
    else
    {
        cout << "No Solutions. " << endl;
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}