#include <iostream>
using namespace std;

void printBoard(int board[9][9]){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isValid(int board[9][9], int row, int column, int number){
    if(board[row][column] != 0){
        return false;
    }

    for (int i = 0; i < 9; i++)
    {
        if (board[i][column] == number)
        {
            return false;
        }
    }

    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == number)
        {
            return false;
        }
    }


    int subBlockStartRow =  (row/3)*3;
    int subBlockStartColumn = (column/3)*3;

    for (int i = subBlockStartRow; i < subBlockStartRow+3; i++)
    {
        for (int j = subBlockStartColumn; j < subBlockStartColumn+3; j++)
        {
            if (board[i][j] == number)
            {
                return false;
            }
        }
    }
    return true;
}

bool solve(int board[9][9]){ 
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(board[i][j] !=0){
                continue;
            }
            else if (board[i][j] == 0){
                for (int candidate = 1; candidate < 10; candidate++)
                {
                    if (isValid(board, i, j, candidate) == true){
                        board[i][j] = candidate;
                        if(solve(board) == true){
                            return true;
                        }
                        else{
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        } 
    } 
    printBoard(board);
    return true;
}

int main(){
    int board[9][9] = {
    {0, 0, 3, 9, 0, 0, 2, 0, 8},
    {0, 0, 1, 0, 0, 5, 0, 9, 3},
    {2, 0, 0, 0, 8, 6, 0, 1, 0},
    {4, 7, 0, 1, 0, 0, 3, 6, 0},
    {9, 0, 0, 6, 0, 2, 0, 0, 7},
    {0, 3, 6, 0, 0, 4, 0, 2, 9},
    {0, 2, 0, 5, 7, 0, 0, 0, 6},
    {3, 6, 0, 2, 0, 0, 5, 0, 0},
    {5, 0, 9, 0, 0, 3, 4, 0, 0}
    };
    
    cout << "Original board: "<< endl;
    printBoard(board);

    cout << "Solved board: " << endl;
    solve(board);

    return 0;
}