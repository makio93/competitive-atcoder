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
	int n;
	ll x;
	cin >> n >> x;
	vector<vector<int>> a(n);
	rep(i, n) {
		int li;
		cin >> li;
		rep(j, li) {
			int ai;
			cin >> ai;
			a[i].push_back(ai);
		}
	}
	unordered_map<ll, int> vals;
	vals[1] = 1;
	rep(i, n) {
		unordered_map<ll, int> nvals;
		for (auto pi : vals) for (int ai : a[i]) if (pi.first <= x/ai) nvals[pi.first*ai] += pi.second;
		swap(nvals, vals);
	}
	cout << vals[x] << endl;
	return 0;
}
