#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int a[5], b[5];
    
    while(cin>>a[0]){
        for(int i=1; i<5; i++)
            cin>>a[i];
        for(int i=0; i<5; i++)
            cin>>b[i];
        
        bool ans=true;
        for(int i=0; i<5; i++)
            if(a[i]+b[i]!=1)
                ans=false;
        cout<<(ans?"Y":"N")<<endl;
    }
    
    return 0;
}
