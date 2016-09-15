#include <bits/stdc++.h>
using namespace std;

char ln[1000000];
long long mem[1000000][3];

long long count(int l, int r){
    long long res=0;
    for(int i=l; i<r; i++){
        mem[i][0]=mem[i][1]=mem[i][2]=0;
        int dig = (ln[i]-'0')%3;
        mem[i][dig]=1;
        if(i>l){
            for(int j=0; j<3; j++)
                mem[i][(j+dig)%3]+=mem[i-1][j];
        }
        res+=mem[i][0];
    }
    return res;
}

int main(){
    
    while(cin>>ln){
        int n = strlen(ln);
        
        long long ans=0;
        int l=0, r=0;
        for(int i=0; i<=n; i++){
            if(isdigit(ln[i])){
                r=i+1;
            }else{
                if(l<r){
                    ans+=count(l, r);
                }
                l=r=i+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
