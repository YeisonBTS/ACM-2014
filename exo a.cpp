#include <bits/stdc++.h>
using namespace std;

/*
 * solo implementacion
 */

int main(){
	
	int w, n, p, a;
	cin>>w>>n>>p;
	
	int ans=0;
	for(int i=0; i<p; i++){
		cin>>a;
		if(a>=w && a<=n)
			ans++;
	}
	
	cout<<ans<<endl;
	
	return 0;
}
