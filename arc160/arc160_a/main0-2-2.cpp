// 自力AC1-2

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
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	pair<int, int> mval = { -1, -1 };
	fenwick_tree<int> ft(n);
	rep(i, n) ft.add(i, 1);
	auto f = [&](auto& f, int vi, int ki) -> int {
		if (vi == n-1) {
			if (ki <= n) {
				mval = { vi, vi };
				return -1;
			}
			else return ki - n;
		}
		else {
			ft.add(a[vi], -1);
			if (ft.sum(0, a[vi]) >= ki) {
				int ri = -1;
				rep3(i, 1, a[vi]+1) {
					if (ft.sum(0, i) == ki) {
						ri = find(all(a), i-1) - a.begin();
						break;
					}
				}
				mval = { vi, ri };
				return -1;
			}
			int kval = f(f, vi+1, ki-ft.sum(0, a[vi]));
			if (kval == -1) return -1;
			if (ft.sum(a[vi]+1, n) >= kval) {
				int ti = -1;
				rep3(i, a[vi]+2, n+1) {
					if (ft.sum(a[vi]+1, i) == kval) {
						ti = find(all(a), i-1) - a.begin();
						break;
					}
				}
				mval = { vi, ti };
				return -1;
			}
			ft.add(a[vi], 1);
			return kval - ft.sum(a[vi]+1, n);
		}
	};
	f(f, 0, k);
	auto res = a;
	reverse(res.begin()+mval.first, res.begin()+mval.second+1);
	rep(i, n) cout << (res[i]+1) << (i<n-1?' ':'\n');
	return 0;
}
