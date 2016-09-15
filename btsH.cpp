#include <bits/stdc++.h>
using namespace std;

int dis(int a, int b){
    return min( 24-abs(a-b), abs(a-b) );
}

int main(){
    
    int n, ns[1005];
    
    while(cin>>n){
        for(int i=0; i<n; i++)
            cin>>ns[i];
cout<<"["<<ns[0]<<":"<<n+ns<<"]";
        sort(ns, ns+n);
for(int I=0;I<n;I++){
    cout<<ns[I]<<endl;    	
}
        int a=0, b=0;
        for(int i=0; i<n; i+=2)
            a+=dis(ns[i], ns[i+1]);
        
        for(int i=1; i<n; i+=2)
            b+=dis(ns[i], ns[(i+1)%n]);
        
        cout<<min(a, b)<<endl;
    }
    
    return 0;
}
