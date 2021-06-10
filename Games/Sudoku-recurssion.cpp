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

    //if the cell is already filled, return false
    if(a[r][c] != 0) return false;
    
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

bool emptyCell( int a[][N], int &r, int &c) {
    fi(0,N) {
        fj(0, N) {
            if(a[i][j] == 0) {
                r = i;
                c = j;
                return true;
            }
        }
    }
}

bool sudokuSolver2(int arr[][N]) {
    int r, c;
    if(!emptyCell(arr, r, c)) return true;

    for(int i=1; i<=9; i++) {
        if(isSafe(arr, r, c, i)) {
            
            //assigning tentative value i
            arr[r][c] = i; 

            // checking if arr[r][c] = i, solves the rest of the sudoku or not
            if(sudokuSolver2(arr)) return true;

            // if all goes well, sudoku will return trye from line no. 99 itself
            // if that is not so
            arr[r][c] = 0;
        }
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

    if(sudokuSolver2(sudoku)) printSudoku(sudoku);
    else cout<<"No possible solution\n";

    return 0;
}
