// Link : https://www.geeksforgeeks.org/lowes-company-on-campus-interview-experience/

#include<bits/stdc++.h>
using namespace std;

#define fi(a,b) for(int i=(a);i<b;i++)
#define fj(a,b) for(int j=(a);j<b;j++)

void print(int r, int c, int *arr) {
	fi(0,r) {
		fj(0,c)
			cout<<*((arr+i*c) + j)<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}

void solve(int r, int c, int b, int n, int *arr) {
	//if b = 0 -> row rotation
	//if b = 1 -> column rotation

	//col rotation
	if(b) {
		int t1, t2;
		t1 = *((arr + 0*c)+n);
		fi(0,c-1) {
			t2 = *((arr + (i+1)*c) + n);
			*((arr + (i+1)*c) + n) = t1;
			t1 = t2;
		}
		*((arr + 0*c)+n) = t1;

	}

	//row rotation
	else {
		int t1, t2;
		t1 = *((arr + n*c)+0);
		fi(0,c-1) {
			t2 = *((arr + n*c) + i+1);
			*((arr + n*c) + i+1) = t1;
			t1 = t2;
		}
		*((arr + n*c)+0) = t1;
	}

}

int main() 
{
	int r,c,b,n;
	cin>>r>>c>>b>>n;
	int arr[r][c];
	fi(0,r) {
		fj(0,c) cin>>arr[i][j];
	}

	//checks on input params with verbose erroe message
	if(b>1 || b<0) {
		cout<<"Invalid operation\n"; 
		return 0;
	}
	if(n<1) {
		cout<<"Invalid row/col selection\n";
		return 0;
	}
	if(b && n>c) {
		cout<<"Target column out of bound\n"; 
		return 0;
	}
	if(!b && n>r) {
		cout<<"Target row out of bound\n";
		return 0;
	}

	//original matrix
	print(r, c, (int *)arr);

	//row/col rotate operation
	solve(r,c,b,n-1,(int *)arr);

	//final matrix
	print(r, c, (int *)arr);
 	return 0;
}

// sample input 1 : 
// 4 4 
// 1 3
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

// sample input 2 :
// 3 3
// 1 3
// 1 2 3 4 5 6 7 8 9

// sample input 3 :
// 3 3
// 1 0
// 1 2 3 4 5 6 7 8 9


