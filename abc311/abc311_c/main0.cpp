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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	vector<int> b, res;
	vector<bool> visited(n);
	function<void(int)> dfs = [&](int vi) {
		visited[vi] = true;
		b.push_back(vi);
		if (visited[a[vi]]) {
			int li = find(all(b), a[vi]) - b.begin();
			res.insert(res.end(), b.begin()+li, b.end());
		}
		else dfs(a[vi]);
	};
	dfs(0);
	int m = res.size();
	cout << m << endl;
	rep(i, m) cout << (res[i]+1) << (i<m-1?' ':'\n');
	return 0;
}
