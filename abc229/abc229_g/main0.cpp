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

// 本番WA

const ll INF = (ll)(1e15);

int main() {
	string s;
	int k;
	cin >> s >> k;
	int n = s.length();
	vector<int> yids;
	rep(i, n) if (s[i] == 'Y') yids.push_back(i+1);
	int yl = yids.size();
	vector<ll> ysum(yl+1);
	rep(i, yl) ysum[i+1] += ysum[i] + yids[i];
	int l = 0, r = yl+1;
	while (r-l > 1) {
		int c = l + (r-l) / 2 + 1;
		if (c > 0) {
			ll dval = INF;
			rep3(i, c, yl+1) {
				ll val = 0;
				int lid = i-c, rid = i;
				if (c%2 == 0) {
					int ltar = lid + c/2 - 1, rtar = ltar + 1;
					ll taddl = (yids[rtar] - yids[ltar]) / 2, taddr = taddl;
					if ((yids[rtar]-yids[ltar])%2 == 1) ++taddr;
					ll tsum = ysum[ltar+1] + taddr;
					val += tsum - ysum[lid] + ysum[rid] - ysum[rtar+1] + taddr * (c/2);
					val -= c;
				}
				else {
					int tar = lid + c/2;
					val += ysum[tar] - ysum[lid] + ysum[rid] - ysum[tar];
					val -= c-1;
				}
				dval = min(dval, val);
			}
			if (dval <= (ll)k) l = c;
			else r = c;
		}
		else l = c;
	}
	cout << (l+1) << endl;
	return 0;
}
