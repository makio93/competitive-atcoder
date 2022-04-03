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

int main() {
	int n, x;
	cin >> n >> x;
	--x;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	vector<bool> known(n);
	queue<int> que;
	known[x] = true;
	que.push(x);
	while (!que.empty()) {
		int v = que.front(); que.pop();
		if (!known[a[v]]) {
			known[a[v]] = true;
			que.push(a[v]);
		}
	}
	int res = 0;
	rep(i, n) if (known[i]) ++res;
	cout << res << endl;
	return 0;
}
