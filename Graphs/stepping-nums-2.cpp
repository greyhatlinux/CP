#include<bits/stdc++.h>
using namespace std;

int bfs(int n, int m, int num) {
    queue<int> q;

    //single digit numbers are always stepping numbers
    q.push(num);

    int count = 0;
    while(!q.empty()) {
        int stepNum = q.front();
        q.pop();

        if(stepNum >= n && stepNum <= m) {
            cout<<stepNum<<" ";
            count++;
        }

        //no need to explore further
        if(stepNum == 0 || stepNum > m) continue;

        int lastDigit = stepNum % 10;
        if(lastDigit > 0 && lastDigit < 9) {
            q.push(stepNum*10 + lastDigit + 1);
            q.push(stepNum*10 + lastDigit - 1);
        }
        else if (lastDigit == 0) q.push(stepNum*10 + lastDigit + 1);
        else q.push(stepNum*10 + lastDigit - 1);
    }
    return count;
}

int steppingNumbers(int n, int m) {

    if(n>m) return INT_MIN;
    if(n == m) return 0;

    int count = 0;
    for(int i=0;i<10;i++) count += bfs(n,m,i);
}

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n,m;
        cin>>n>>m;
        int x = steppingNumbers(n,m);
        cout<<"\nTotal numbers : "<<x<<"\n";
    }
    return 0;
}
