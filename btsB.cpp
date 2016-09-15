#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int a, b;
    string cad;
    
    while(cin>>a>>b){
        cin>>cad;
        int n=cad.size();
        
        int ind=0;
        for(int i=0; i<n; i++)
            ind+=(cad[i]=='B');

        long long ans=0;
        for(int l=ind-1, r=ind; ; r++, l--){
            while(r<n && cad[r]=='W')
                r++;
            if(r==n)
                break;
            while(l>=0 && cad[l]=='B')
                l--;
            if(l==-1)
                break;
            ans+=min((long long)a, (long long)(r-l)*(a-b));
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}
