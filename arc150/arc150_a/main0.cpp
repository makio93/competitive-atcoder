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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		vector<int> zcnt(n+1);
		rep(i, n) zcnt[i+1] = zcnt[i] + (s[i]=='0' ? 1 : 0);
		int li = n, ri = -1;
		rep(i, n) if (s[i] == '1') {
			li = min(li, i);
			ri = max(ri, i);
		}
		int rcnt = 0;
		if (li != n) {
			++ri;
			if (ri-li <= k) {
				int lid = max(0, ri-k);
				while (lid<=li && lid+k<=n) {
					if (zcnt[lid+k]-zcnt[lid] == 0) ++rcnt;
					++lid;
				}
			}
		}
		else {
			int lid = 0;
			while (lid+k <= n) {
				if (zcnt[lid+k]-zcnt[lid] == 0) ++rcnt;
				++lid;
			}
		}
		if (rcnt == 1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
