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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	pair<int, int> mval = { -1, -1 };
	auto f = [&](auto& f, int vi, int ki) -> int {
		if (vi == n-1) {
			if (ki <= n) {
				mval = { vi, vi };
				return -1;
			}
			else return ki - n;
		}
		else {
			vector<int> rlst;
			rep3(i, vi+1, n) if (a[i] < a[vi]) rlst.push_back(a[i]);
			sort(all(rlst));
			if ((int)(rlst.size()) >= ki) {
				int tar = rlst[ki-1], ri = -1;
				rep3(i, vi+1, n) if (a[i] == tar) {
					ri = i;
					break;
				}
				mval = { vi, ri };
				return -1;
			}
			int kval = f(f, vi+1, ki-(int)(rlst.size()));
			if (kval == -1) return -1;
			vector<int> tlst;
			rep3(i, vi+1, n) if (a[i] > a[vi]) tlst.push_back(a[i]);
			sort(all(tlst));
			if ((int)(tlst.size()) >= kval) {
				int tar = tlst[kval-1], ti = -1;
				rep3(i, vi+1, n) if (a[i] == tar) {
					ti = i;
					break;
				}
				mval = { vi, ti };
				return -1;
			}
			return kval - (int)(tlst.size());
		}
	};
	f(f, 0, k);
	auto res = a;
	reverse(res.begin()+mval.first, res.begin()+mval.second+1);
	rep(i, n) cout << (res[i]+1) << (i<n-1?' ':'\n');
	return 0;
}
