#include<bits/stdc++.h>
using namespace std;

#define N 9
#define endl "\n"
#define fi(a,b) for(int i=(a); i<b; i++)
#define fj(x,y) for(int j=(x); j<y; j++)

void printSudoku(int arr[][N]) {
    fi(0,N) {
        fj(0,N) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

//this checks if putting num [1-9] is safe as per sudoku rules or not
bool isSafe( int a[][N], int r, int c, int num) {
    //check in same row, and column
    fi(0,N) {
        if(a[r][i] == num) return false; //column changes
        if(a[i][c] == num) return false; //row changes
    }

    int rt, ct;
    rt = r - r%3;
    ct = c - c%3;

    //check for num in the same grid 
    fi(0, 3) {
        fj(0, 3) {
            if(a[i + rt][j + ct] == num) return false;
        }
    }

    return true;
}


bool sudokuSolver(int arr[][N], int r, int c) {

    // if we've reached the end of the 9x9 matrix
    if(r==N-1 && c==N) return true; 

    //note here it should be c==N and not c==N-1
    //elsem the last cell ie, sudoku[8][8] will remain empty.

    // if we've reached the last column
    if(c == N ) {
        r++;
        c = 0;
    }

    // check if the cell is already filled
    if(arr[r][c] > 0 ) return sudokuSolver(arr, r, c+1);

    //now weve reached the empty cell
    //we'll start filling the empty cell
    fi(1,N+1) {

        //if putting i in the empty cell is safe, then
        if(isSafe(arr, r, c, i)) {
            arr[r][c] = i;

            //if its safe, then we'll check the possibility with the next column
            if(sudokuSolver(arr, r, c+1)) return true;
        }

        // if code reaches here, it means our number was wrong.
        arr[r][c] = 0;
    }
    return false;
}

int main() 
{

    int sudoku[N][N]={ { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
                    
    if(sudokuSolver(sudoku, 0, 0)) printSudoku(sudoku);
    else cout<<"No possible solution\n";

    return 0;
}
