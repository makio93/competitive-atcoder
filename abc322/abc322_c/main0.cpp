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
	int n, m;
	cin >> n >> m;
	vector<bool> b(n);
	rep(i, m) {
		int ai;
		cin >> ai;
		--ai;
		b[ai] = true;
	}
	vector<int> acnt(n);
	int mval = INF;
	repr(i, n) {
		if (b[i]) mval = i;
		acnt[i] = mval;
	}
	rep(i, n) cout << (acnt[i]-i) << endl;
	return 0;
}
