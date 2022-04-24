// 復習0,解説AC-0

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
	int n, k;
	cin >> n >> k;
	vector<int> t, y;
	t.push_back(1);
	y.push_back(0);
	rep(i, n) {
		int ti, yi;
		cin >> ti >> yi;
		t.push_back(ti);
		y.push_back(yi);
	}
	ll res = (ll)(-1e18);
	priority_queue<int> sq;
	unordered_set<int> tst;
	ll tsum = 0;
	repr(i, n+1) {
		if (t[i] == 1) {
			res = max(res, y[i]+tsum);
			--k;
			if (k < 0) break;
			if ((int)(sq.size()) > k) {
				int sv = sq.top(); sq.pop();
				tsum += sv;
				tst.insert(sv);
			}
		}
		else {
			if (y[i] >= 0) {
				tsum += y[i];
				tst.insert(y[i]);
			}
			else {
				sq.push(y[i]);
				if ((int)(sq.size()) > k) {
					int sv = sq.top(); sq.pop();
					tsum += sv;
					tst.insert(sv);
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}
