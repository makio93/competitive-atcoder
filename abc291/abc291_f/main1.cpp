// 解説AC

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

template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = (int)(1e9);

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<int> ldp(n, INF), rdp(n, INF);
	ldp[0] = 0;
	rep(i, n-1) rep(j, m) if (s[i][j] == '1') chmin(ldp[i+j+1], ldp[i]+1);
	rdp[n-1] = 0;
	repr(i, n-1) rep(j, m) if (s[i][j] == '1') chmin(rdp[i], rdp[i+j+1]+1);
	rep3(k, 1, n-1) {
		int val = INF;
		for (int i=k-m+1; i<k; ++i) {
			if (i < 0) continue;
			for (int j=k+1; j<k+m; ++j) {
				if (j>=n || j-i>m || s[i][j-i-1]=='0') continue;
				val = min(val, ldp[i]+rdp[j]+1);
			}
		}
		if (val == INF) val = -1;
		cout << val << (k<n-2?' ':'\n');
	}
	return 0;
}
