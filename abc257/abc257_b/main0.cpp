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
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> a(k), l(q);
	rep(i, k) cin >> a[i];
	rep(i, q) {
		cin >> l[i];
		l[i]--;
	}
	set<int> aids(a.begin(), a.end());
	rep(i, q) {
		auto itr = next(aids.begin(), l[i]);
		if ((*itr)+1<=n && aids.find((*itr)+1)==aids.end()) {
			int val = (*itr) + 1;
			aids.erase(itr);
			aids.insert(val);
		}
	}
	auto itr = aids.begin();
	rep(i, k) {
		cout << (*itr) << (i<k-1?' ':'\n');
		++itr;
	}
	return 0;
}
