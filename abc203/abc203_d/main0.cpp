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

// 本番中に作成、WA

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> a(n, vector<int>(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	int klen = k * k;
	deque<pair<int, int>> kval;
	rep(i, k) rep(j, k) kval.emplace_back(a[i][j], i*n+j);
	sort(all(kval));
	pair<int, int> mid = kval[(klen-1)/2], mval = mid;
	int mptr = (klen-1)/2;
	rep3(i, k-1, n) {
		auto kval2 = kval;
		rep3(j, k, n) {
			rep(i2, k) {
				int ny = i-(k-1) + i2, nx = j;
				int ny2 = ny, nx2 = j - k;
				auto itr1 = lower_bound(all(kval2), make_pair(a[ny][nx],ny*n+nx));
				kval2.insert(itr1, make_pair(a[ny][nx],ny*n+nx));
				auto itr2 = lower_bound(all(kval2), make_pair(a[ny2][nx2],ny2*n+nx2));
				kval2.erase(itr2);
			}
			mid = kval2[mptr];
			mval = min(mval, mid);
		}
		if (i+1 < n) {
			rep(i2, k) {
				int ny = i + 1, nx = i2;
				int ny2 = ny - k, nx2 = nx;
				auto itr1 = lower_bound(all(kval), make_pair(a[ny][nx],ny*n+nx));
				kval.insert(itr1, make_pair(a[ny][nx],ny*n+nx));
				auto itr2 = lower_bound(all(kval), make_pair(a[ny2][nx2],ny2*n+nx2));
				kval.erase(itr2);
			}
			mid = kval[mptr];
			mval = min(mval, mid);
		}
	}
	cout << mid.first << endl;
	return 0;
}
