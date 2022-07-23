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
	string s, t;
	int k;
	cin >> s >> t >> k;
	vector<string> c(k), a(k);
	rep(i, k) cin >> c[i] >> a[i];
	unordered_map<string, int> dist;
	queue<string> que;
	int res = -1;
	dist[t] = 0;
	que.push(t);
	while (!que.empty()) {
		string vi = que.front(); que.pop();
		int di = dist[vi], ndi = di + 1, len = vi.length();
		rep(i, k) {
			int alen = a[i].length();
			if (len-(alen-1) < (int)(s.length())) continue;
			for (int j=0; j+alen-1<len; ++j) if (vi.substr(j, alen) == a[i]) {
				string ti = vi.substr(0, j) + c[i] + vi.substr(j+alen);
				if (dist.find(ti) != dist.end()) continue;
				dist[ti] = ndi;
				if (ti == s) {
					res = ndi;
					break;
				}
				que.push(ti);
			}
			if (res != -1) break;
		}
		if (res != -1) break;
	}
	cout << res << endl;
	return 0;
}
