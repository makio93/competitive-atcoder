#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> s(n), t(m);
	rep(i, n) cin >> s[i];
	rep(i, m) cin >> t[i];
	vector<int> scnt(2), tcnt(2);
	rep(i, n) scnt[s[i]]++;
	rep(i, m) tcnt[t[i]]++;
	bool ok = true;
	rep(i, 2) if (tcnt[i]>0 && scnt[i]==0) ok = false;
	ll res = (ok) ? (ll)(1e18) : -1;
	if (ok) {
		int snum = 0, tnum = 0;
		rep(i, 2) if (scnt[i] > 0) ++snum;
		rep(i, 2) if (tcnt[i] > 0) ++tnum;
		if (snum==1 && tnum==1) res = m;
		else {
			vector<int> dir = { 1, n-1 };
			rep(i1, 2) {
				ll cnt = 0;
				bool moved = false;
				int sid = 0;
				rep(i, m) {
					if (moved) {
						if (t[i-1] == t[i]) ++cnt;
						else cnt += 2;
					}
					else {
						if (t[i] == s[sid]) ++cnt;
						else {
							while (t[i] != s[sid]) {
								sid = (sid + dir[i1]) % n;
								++cnt;
							}
							++cnt;
							moved = true;
						}
					}
				}
				res = min(res, cnt);
			}
		}
	}
	cout << res << endl;
	return 0;
}
