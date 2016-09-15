#include <bits/stdc++.h>
using namespace std;

vector< vector< pair<int,int> > > g;
vector< bool > frs;

int dfs(int v, int p, int &b, int sm, int d){
    if(frs[v])
        b = max(b, sm);
    int res = 0;
    for(auto &to: g[v]){
        if(to.first == p)
            continue;
        res += dfs(to.first, v, b, sm+to.second, to.second);
    }
    if(res && frs[v]==false)
        res += d;
    res += d * frs[v];
    return res;
}

int main(){
    
    int n, f;
    
    while(cin>>n>>f){
        g.assign(n+1, vector< pair<int,int> >());
        frs.assign(n+1, false);
        
        int a, b, d;
        for(int i=0; i<n-1; i++){
            cin>>a>>b>>d;
            g[a].push_back({b, d});
            g[b].push_back({a, d});
        }
        
        for(int i=0; i<f; i++){
            cin>>a;
            frs[a]=true;
        }
        
        b=0;
        int total = dfs(1, -1, b, 0, 0);
        
        cout<<total-b<<endl;
    }
    
    return 0;
}
