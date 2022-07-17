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
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	set<int> nums;
	rep(i, n) nums.insert(i);
	vector<int> res, tmp;
	for (int id : nums) tmp.push_back(id);
	sort(all(tmp), [&](int li, int ri) -> bool {
		return (a[li] != a[ri]) ? a[li] > a[ri] : li < ri;
	});
	rep(i, x) {
		res.push_back(tmp[i]);
		nums.erase(tmp[i]);
	}
	tmp.clear();
	for (int id : nums) tmp.push_back(id);
	sort(all(tmp), [&](int li, int ri) -> bool {
		return (b[li] != b[ri]) ? b[li] > b[ri] : li < ri;
	});
	rep(i, y) {
		res.push_back(tmp[i]);
		nums.erase(tmp[i]);
	}
	tmp.clear();
	for (int id : nums) tmp.push_back(id);
	sort(all(tmp), [&](int li, int ri) -> bool {
		return (a[li]+b[li] != a[ri]+b[ri]) ? a[li]+b[li] > a[ri]+b[ri] : li < ri;
	});
	rep(i, z) {
		res.push_back(tmp[i]);
		nums.erase(tmp[i]);
	}
	int m = res.size();
	sort(all(res));
	rep(i, m) cout << (res[i]+1) << endl;
	return 0;
}
