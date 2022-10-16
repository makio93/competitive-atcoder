// 本番AC

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

const int INF = (int)(1e9);

int main() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	int scnt = count(all(s), '1'), tcnt = count(all(t), '1');
	if (abs(scnt-tcnt)%2 != 0) {
		cout << -1 << endl;
		return 0;
	}
	int sval = scnt - tcnt;
	string u = string(n, '0');
	repr(i, n) {
		if (sval == 0) break;
		if (sval>0 && s[i]=='1' && t[i]=='0') {
			u[i] = '1';
			sval -= 2;
		}
		else if (sval<0 && s[i]=='0' && t[i]=='1') {
			u[i] = '1';
			sval += 2;
		}
	}
	cout << u << endl;
	return 0;
}
