#include <iostream>
using namespace std;
#define N 5

void solve();
void printSolution(int board[N][N]);
bool isSafe(int board[N][N], int row, int column);
bool backtracking(int board[N][N], int column);

int main()
{
    solve();
    return 0;
}

void printSolution(int board[N][N])
{
    static int k = 1;
    cout << k << endl;
    k++;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout<< board[i][j]<<" ";
        cout << endl;
    }
    cout << endl;
}

//agar ba queen haye qablish tadakhol ndasht true bargardun
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    //check kardane poshte radif
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    //nimeye bala
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    //nimeye payin
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool backtracking(int board[N][N], int col)
{
    //agar hame queen ha qarar gereftan print kon
    if (col == N)
    {
        printSolution(board);
        return true;
    }

    //queen ro tuye hameye satr haye in sutun qarar bede
    bool result = false;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            result = backtracking(board, col + 1) ;

            //agar in qarar dadan be solution naresid queen ro remove mikonim
            board[i][col] = 0; // Backtrack
        }
    }
    return false;
}

//kole board ro 0 mikonim
void solve()
{
    int board[N][N];
    memset(board, 0, sizeof(board));
    backtracking(board, 0);
}

