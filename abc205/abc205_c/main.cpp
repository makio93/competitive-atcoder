#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (c == 0) cout << '=' << endl;
	else {
		char achar = (abs(a) >= abs(b)) ? (abs(a) == abs(b)) ? '=' : '>' : '<';
		char achar2 = (abs(a) >= abs(b)) ? (abs(a) == abs(b)) ? '=' : '<' : '>';
		if (c%2 == 0) {
			cout << achar << endl;
		}
		else {
			if (a<0 || b<0) {
				if (a<0 && b>=0) cout << '<' << endl;
				else if (a>=0 && b<0) cout << '>' << endl;
				else cout << achar2 << endl;
			}
			else cout << achar << endl;
		}
	}
	return 0;
}
