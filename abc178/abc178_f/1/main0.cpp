// 学習1回目,自力WA

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
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	unordered_map<int, pair<int, int>> acnt, bcnt;
	rep(i, n) {
		if (acnt.find(a[i]) == acnt.end()) acnt[a[i]].first = i;
		acnt[a[i]].second++;
	}
	rep(i, n) {
		if (bcnt.find(b[i]) == bcnt.end()) bcnt[b[i]].first = i;
		bcnt[b[i]].second++;
	}
	int sub = 0, rsub = 0;
	for (auto pi : acnt) if (bcnt.find(pi.first) != bcnt.end()) {
		int aid = pi.second.first + pi.second.second, bid = bcnt[pi.first].first;
		if (bid > aid) bid -= n;
		sub = max(sub, aid-bid);
		int rbid = bcnt[pi.first].first + bcnt[pi.first].second, raid = pi.second.first;
		if (rbid < raid) rbid += n;
		rsub = max(rsub, rbid-raid);
	}
	vector<int> blst(n), rblst(n);
	rep(i, n) blst[(i+sub)%n] = b[i];
	rep(i, n) rblst[(i-rsub+n)%n] = b[i];
	bool ok = true;
	rep(i, n) if (a[i] == blst[i]) {
		ok = false;
		break;
	}
	if (ok) {
		cout << "Yes" << endl;
		rep(i, n) printf("%d%c", blst[i], (i<n-1?' ':'\n'));
	}
	else {
		ok = true;
		rep(i, n) if (a[i] == rblst[i]) {
			ok = false;
			break;
		}
		if (ok) {
			cout << "Yes" << endl;
			rep(i, n) printf("%d%c", rblst[i], (i<n-1?' ':'\n'));
		}
		else cout << "No" << endl;
	}
	return 0;
}
