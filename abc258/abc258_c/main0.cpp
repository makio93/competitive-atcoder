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
	int n, q;
	string s;
	cin >> n >> q >> s;
	int mid = 0;
	rep(i, q) {
		int qi, xi;
		cin >> qi >> xi;
		if (qi == 1) mid = (mid - xi + n) % n;
		else {
			--xi;
			int id = (xi + mid) % n;
			cout << s[id] << endl;
		}
	}
	return 0;
}
