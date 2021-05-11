#include<bits/stdc++.h>
using namespace std;

void solve(int n, int t, int x, int num[]) {

    set<pair<int, int>> s1;     //pairs should be like <hi,ti> and not <ti,hi>

    for(int i=0;i<t;i++) s1.insert({0,i});

    int ti, hi;
    cout<<"YES\n";
    for(int i=0;i<n;i++){
        ti = i%t;
        pair<int, int> p = *s1.begin();
        cout<<p.second<<" ";
        s1.erase(p);
        s1.insert({p.first + num[i], p.second});
    }

    cout<<"\n";

}

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n,t,x;
        cin>>n>>t>>x;
        int num[n];
        for(int i=0;i<n;i++) cin>>num[i];

        solve(n,t,x,num);
    }
    return 0;
}
