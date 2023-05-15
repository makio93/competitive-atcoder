// 本番WA

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
	vector<pair<pair<int, int>, pair<int, int>>> plst;
	rep(i, n) {
		fenwick_tree<int> fw(n);
		int rval = 0;
		rep3(j, i, n) {
			rval += fw.sum(a[j], n);
			fw.add(a[j], 1);
			plst.emplace_back(make_pair(i, ((j-i)*(j-i+1)/2-rval)-rval), make_pair(i, j));
		}
	}
	sort(all(plst));
	auto [li, ri] = plst[k-1].second;
	auto res = a;
	reverse(res.begin()+li, res.begin()+ri+1);
	rep(i, n) cout << (res[i]+1) << (i<n-1?' ':'\n');
	return 0;
}
