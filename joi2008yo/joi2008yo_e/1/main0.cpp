// 自力AC

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
	int r, c;
	cin >> r >> c;
	vector<vector<int>> a(r, vector<int>(c));
	rep(i, r) rep(j, c) cin >> a[i][j];
	int res = INF;
	rep(i1, (1<<r)) {
		int sum = 0;
		rep(i, c) {
			int cnt0 = 0, cnt1 = 0;
			rep(j, r) {
				int val = a[j][i];
				if ((i1>>j)&1) val = 1 - val;
				cnt0 += val;
				cnt1 += 1 - val;
			}
			sum += min(cnt0, cnt1);
		}
		res = min(res, sum);
	}
	cout << (r*c-res) << endl;
	return 0;
}
