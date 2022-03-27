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
	vector<int> a(n+1), b(m+1), c(n+m+1);
	rep(i, n+1) cin >> a[i];
	rep(i, n+m+1) cin >> c[i];
	rep(i, min(n,m)+1) {
		int mi = m;
		rep3(j, n-i, n+1) {
			if (j < n) c[n+m-i] -= a[j] * b[mi];
			else b[mi] = c[n+m-i] / a[n];
			--mi;
		}
	}
	if (m > n) {
		repr(i, m-n) {
			int mi = i + n;
			rep(j, n+1) {
				if (j < n) c[i+n] -= a[j] * b[mi];
				else b[mi] = c[i+n] / a[n];
				--mi;
			}
		}
	}
	rep(i, m+1) printf("%d%c", b[i], (i<m?' ':'\n'));
	return 0;
}
