#include <bits/stdc++.h>
using namespace std;

/*
 * teniendo en cuenta que 2^n = 4^(n/2)
 * siendo la base 4 el modulo con 3 siempre sera 1
 * por lo tanto si H > 1 el modulo sera 1
 */

int main(){
	
	// se debe leer como cadena puesto que la entrada no entra
	// en un entero
	string num;
	cin>>num;
	
	if(num=="1"){
		cout<<2<<endl;
	}else{
		cout<<1<<endl;
	}
	
	return 0;
}
