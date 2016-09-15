#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

vector< int > di, dj;
set< pair<int,int> > vis, pts;

void bipartite(int x, int y, int &a, int &b, int c=0){
    if(c==0) a++;
    else b++;
    vis.insert({x, y});
    for(int i=0; i<(int)di.size(); i++){
        pair<int,int> pt = {x+di[i], y+dj[i]};
        if(vis.count(pt))
            continue;
        if(pts.count(pt))
            bipartite(pt.X, pt.Y, a, b, 1-c);
    }
}

int main(){
   
    for(int i=-5; i<=5; i++){
        for(int j=-5; j<=5; j++){
            if(i==0 && j==0)
                continue;
            if((long long)i*i+(long long)j*j>25)
                continue;
            di.push_back(i);
            dj.push_back(j);
        }
    }
    
    int n;
    
    while(cin>>n){
        int x, y;
        
        pts.clear();
        for(int i=0; i<n; i++){
            cin>>x>>y;
            pts.insert({x, y});
        }
        
        int ans=0;
        
        vis.clear();
        for(auto &i: pts){
            if(vis.count(i)==0){
                int a=0, b=0;
                bipartite(i.X, i.Y, a, b);
                ans+=min(a, b);
            }
        }
        
        cout<<ans<<endl;
    }

    return 0;
}
