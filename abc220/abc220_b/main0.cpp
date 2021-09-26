#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
	int k;
	string a, b;
	cin >> k >> a >> b;
	ll aval = 0, bval = 0;
	int alen = a.length(), blen = b.length();
	rep(i, alen) {
		aval *= k;
		aval += a[i] - '0';
	}
	rep(i, blen) {
		bval *= k;
		bval += b[i] - '0';
	}
	cout << (aval*bval) << endl;
	return 0;
}
