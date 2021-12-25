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
	string x;
	cin >> x;
	int n = x.length();
	vector<int> dsub(n+1);
	rep(i, n) {
		dsub[i] += x[i] - '0';
		dsub[n] -= x[i] - '0';
	}
	int nval = dsub[0];
	vector<int> dval(n+1);
	dval[0] = dsub[0];
	rep3(i, 1, n+1) {
		nval += dsub[i];
		dval[i] = nval;
	}
	rep3r(i, 1, n) {
		dval[i-1] += dval[i] / 10;
		dval[i] %= 10;
	}
	string res = to_string(dval[0]);
	rep3(i, 1, n) res += (char)(dval[i]+'0');
	cout << res << endl;
	return 0;
}
