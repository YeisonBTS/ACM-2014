#include <bits/stdc++.h>
#include <cstdio>
#define db(a) cout << #a << " = " << a << endl
#define db2(a, b) cout << #a << " = " << a \
<< " " << #b << " = " << b << endl
#define db3(a, b, c) cout << #a << " = " << a \
<< " " << #b << " = " << b \
<< " " << #c << " = " << c << endl

using namespace std;
bool cmpChars(const char & a1, const char & b1) {
        if (a1 == 'D')
    		return true;
		if (a1 == 'C' &&
    		b1 == 'D')
    		return false;
		if (a1 == 'H' &&
    		(b1 == 'D' || b1 == 'C'))
    		return false;
		if (a1 == 'S' &&
    		b1 != 'S')
    		return false;
		return true;
}
bool cmp(const string &a,const string &b) {
	if (a[0] == b[0]) {
	    return cmpChars(a[1], b[1]);
	}
	if (a[0] > '9' && b[0] > '9') {
		if (a[0] == 'T') {
			if (b[0] == 'T') {
			    return cmpChars(a[1], b[1]);
		   }
		   else return true;
		}
		if (a[0] == 'J') {
			if (b[0] == 'J') {
                return cmpChars(a[1], b[1]);
 		    }
		    else
		    if (b[0] == 'T')
		        return false;
		    return true;
		}
		if (a[0] == 'Q') {
			if (b[0] == 'Q') {
                return cmpChars(a[1], b[1]);
 		    }
		    else
		    if (b[0] == 'T' || b[0] == 'J')
		        return false;
		    return true;
		}
		if (a[0] == 'K') {
			if (b[0] == 'K') {
                return cmpChars(a[1], b[1]);
 		    }
		    else
		    if (b[0] == 'T' || b[0] == 'J' || b[0] == 'Q')
		        return false;
		    return true;
		}
		if (a[0] == 'A') {
			if (b[0] == 'A') {
                return cmpChars(a[1], b[1]);
 		    }
		    else
		        return false;
		}
	    return true;
	}
	return a <= b;
}

int main() {

    int t;
    char nums[] = "0123456789", c[] = "DCHS", m10[] = "TJQKA";

    cin>>t;

    while(t--){
        vector <string> W(26), hand(52);
       for(int i=0; i<26; i++){
           cin >> W[i];
       }

       sort(W.begin(),W.end(), cmp);
       int k = 0;
        for (int i = 2; i < 10; i++)
        for( int j = 0; j < 4; j++) {
            hand[k] += nums[i];
            hand[k++] += c[j];
            //	db2(nums[i], c[j]);
        }
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 4; j++) {
                //	db2(m10[i], c[j]);
                hand[k] += m10[i];
                hand[k++] += c[j];
            }

        //for(int i=0; i<52; i++){
          // cout << hand[i] << endl;
        //}
	    vector<pair<string, bool> > h(52);
        //	db(k);
	    k = 0;
	    for (int i = 0; i < 52; i++) {
	        h[i].first = hand[i];
	        if (k < 26 && W[k] == hand[i])
		        h[i].second = true, k++;
            //db3(i, h[i].first, h[i].second);
        }
    	int res = 0;
    	//db(k);
    	//db(h.size());
    	//db(W.size());
    	k--;
        for (int i = 51; i >= 0 && k >= 0; i--) {
//        continue;
//            db2(i, k);
//             db3(51 - i, h[i].first, W[k]);
            if (h[i].second == false &&
                cmp(h[i].first, W[k])) {
                res++;
                k--;
            }

        }
        db(res);
        cout << res << endl;
    }
    return 0;
}
