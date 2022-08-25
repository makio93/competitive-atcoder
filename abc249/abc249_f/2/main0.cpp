// 学習2回目,自力AC

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

const ll LINF = (ll)(1e18);

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> t(n+1), y(n+1);
	t[0] = 1;
	y[0] = 0;
	rep3(i, 1, n+1) cin >> t[i] >> y[i];
	priority_queue<int, vector<int>, greater<int>> ulst;
	priority_queue<int> dlst;
	ll sum = 0, res = -LINF;
	int kcnt = k;
	repr(i, n+1) {
		if (t[i] == 2) {
			if (y[i] >= 0) {
				ulst.push(y[i]);
				sum += y[i];
			}
			else {
				dlst.push(y[i]);
				if ((int)(dlst.size()) > kcnt) {
					sum += dlst.top();
					ulst.push(dlst.top());
					dlst.pop();
				}
			}
		}
		else {
			res = max(res, sum+y[i]);
			--kcnt;
			if (kcnt < 0) break;
			if ((int)(dlst.size()) > kcnt) {
				sum += dlst.top();
				ulst.push(dlst.top());
				dlst.pop();
			}
		}
	}
	cout << res << endl;
	return 0;
}
