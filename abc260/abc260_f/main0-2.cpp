// 終了後,自力,TLE

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
	int s, t, m;
	cin >> s >> t >> m;
	vector<int> u(m), v(m);
	vector<bitset<300005>> vtos(t);
	rep(i, m) {
		cin >> u[i] >> v[i];
		u[i]--; v[i]--;
		vtos[v[i]-s][u[i]] = 1;
	}
	vector<int> res;
	rep(i, t) {
		rep3(j, i+1, t) if ((int)((vtos[i]&vtos[j]).count()) >= 2) {
			res.push_back(s+i);
			res.push_back(s+j);
			auto btmp = vtos[i] & vtos[j];
			int tcnt = 0;
			rep(i2, s) if (btmp[i2]) {
				res.push_back(i2);
				++tcnt;
				if (tcnt == 2) break;
			}
			if (!res.empty()) break;
		}
		if (!res.empty()) break;
	}
	if (!res.empty()) rep(i, 4) cout << (res[i]+1) << (i<3?' ':'\n');
	else cout << -1 << endl;
	return 0;
}
