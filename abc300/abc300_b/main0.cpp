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
	int h, w;
	cin >> h >> w;
	vector<string> a(h*2), b(h);
	rep(i, h) {
		string ai;
		cin >> ai;
		a[i] = a[i+h] = ai + ai;
	}
	rep(i, h) cin >> b[i];
	rep(i, h) rep(j, w) {
		bool ok = true;
		rep(i2, h) rep(j2, w) if (a[i+i2][j+j2] != b[i2][j2]) ok = false;
		if (ok) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
