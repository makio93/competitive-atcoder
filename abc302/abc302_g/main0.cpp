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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	auto b = a;
	sort(all(b));
	vector<unordered_set<int>> st(4);
	rep(i, n) if (a[i] != b[i]) st[a[i]].insert(i);
	int res = 0;
	rep(i, n) {
		if (a[i] != b[i]) {
			int tid = *st[b[i]].begin();
			st[b[i]].erase(st[b[i]].begin());
			swap(a[i], a[tid]);
			if (a[tid] != b[tid]) st[a[tid]].insert(tid);
			++res;
		}
	}
	cout << res << endl;
	return 0;
}
