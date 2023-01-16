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
	int n, q;
	string s;
	cin >> n >> s >> q;
	vector<fenwick_tree<int>> ccnt(26, fenwick_tree<int>(n+1));
	rep(i, n) ccnt[s[i]-'a'].add(i, 1);
	set<int> sids;
	sids.insert(0);
	sids.insert(n);
	rep(i, n-1) if (s[i+1] < s[i]) sids.insert(i+1);
	rep(i1, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int xi;
			char ci;
			cin >> xi >> ci;
			--xi;
			ccnt[s[xi]-'a'].add(xi, -1);
			s[xi] = ci;
			ccnt[s[xi]-'a'].add(xi, 1);
			if (xi-1 >= 0) {
				if (s[xi] < s[xi-1]) sids.insert(xi);
				else if (sids.find(xi) != sids.end()) sids.erase(xi);
			}
			if (xi+1 < n) {
				if (s[xi+1] < s[xi]) sids.insert(xi+1);
				else if (sids.find(xi+1) != sids.end()) sids.erase(xi+1);
			}
		}
		else {
			int li, ri;
			cin >> li >> ri;
			--li;
			if (*sids.lower_bound(ri) > *sids.upper_bound(li)) {
				cout << "No" << endl;
				continue;
			}
			vector<int> acnt(26), bcnt(26);
			rep(i, 26) acnt[i] = ccnt[i].sum(0, n);
			rep(i, 26) bcnt[i] = ccnt[i].sum(li, ri);
			int bli = INF, bri = -INF;
			rep(i, 26) if (bcnt[i] > 0) {
				bli = min(bli, i);
				bri = max(bri, i);
			}
			bool ok = true;
			rep3(i, bli+1, bri) if (acnt[i] != bcnt[i]) {
				ok = false;
				break;
			}
			if (ok) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}
