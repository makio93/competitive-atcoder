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
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	unordered_map<int, int> cnt;
	rep(i, n) cnt[a[i]]++;
	rep(i, m) cnt[b[i]]++;
	vector<int> res;
	for (auto p : cnt) if (p.second == 1) res.push_back(p.first);
	sort(all(res));
	if ((int)(res.size()) > 0) rep(i, (int)(res.size())) printf("%d%c", res[i], (i<(int)(res.size())-1?' ':'\n'));
	else cout << endl;
	return 0;
}

