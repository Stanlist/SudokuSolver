#include <iostream>

using namespace std;

const int SIZE = 9;

//Prints out a grid
void printGrid(int grid[SIZE][SIZE])
{
    for(int row = 0; row < SIZE; row++)
    {
        for(int col = 0; col < SIZE; col++)
        {
            cout << grid[row][col] << "  ";
        }
        cout << endl;
    }
}

//Checks if a grid is valid AFTER inputting a new value
bool isValid(int grid[SIZE][SIZE], int row, int col, int num)
{
    //Returns false if the same number appears in the same column
    for(int index = 0; index < SIZE; index++)
    {
        if(grid[row][index] == num)
            return false;
    }

    //Returns false if the same number appears in the samn row
    for(int index = 0; index < SIZE; index++)
    {
        if(grid[index][col] == num)
            return false;
    }

    //The start of 3x3 subsection in which a particular point resides in
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

//Checks whether this there is an empty location in the grid past the inputted coordinates
bool emptyLocation(int grid[SIZE][SIZE], int& row, int& col)
{
    //Changes row and col since they are passed by reference
    while(row < SIZE)
    {
        while(col < SIZE)
        {
            if(grid[row][col] == 0)
            {
                return true;
            }
            col++;
        }
        row++;
        col = 0;
    }
    return false;
}

//Solves Puzzle using Backtracking
bool solve(int grid[SIZE][SIZE])
{
    int row = 0;
    int col = 0;

    bool isNotFull = emptyLocation(grid, row, col);

    //If there are no empty spots in the grid (no zeros), the sudoku is solved and the grid will be displayed
    if(!isNotFull)
    {
        printGrid(grid);
        return true;
    }
    
    //Trys each number to determine whether it will work
    //Backtracking part
    for(int count = 1; count <= SIZE; count++)
    {
        if(isValid(grid, row, col, count))
        {
            grid[row][col] = count;
            if(solve(grid))
                return true;
            
            //If next iteration returns false (no more possible numbers to  choose from), the program backtracks by erasing the previous iteration and tried a different number
            grid[row][col] = 0;    
        }
        
    }
    return false;
}


int main()
{
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
    cout << "Unsolved Grid:" << endl;
    printGrid(grid);

    cout << "Solved Grid:" << endl;
    solve(grid);
    

    system("PAUSE");
    return EXIT_SUCCESS;
}