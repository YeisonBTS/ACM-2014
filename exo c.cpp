#include <bits/stdc++.h>
using namespace std;

/*
 * parsin simple
 */

int main(){
	
	string ln;
	cin>>ln;
	
	int sm=0, cnt=0;
	for(int i=0; i<(int)ln.size(); i++, cnt++){
		if(ln[i+1]=='0'){
			sm+=(ln[i]-'0')*10;
			i++;
		}else{
			sm+=(ln[i]-'0');
		}
	}
	
	printf("%.2lf\n", (double)sm/cnt);
	
	return 0;
}
