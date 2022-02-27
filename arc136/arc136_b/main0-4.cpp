// 終了後,ヒント有りで実装,AC

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
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	auto atmp = a, btmp = b;
	sort(all(atmp));
	sort(all(btmp));
	if (atmp != btmp) {
		cout << "No" << endl;
		return 0;
	}
	unordered_map<int, int> bids;
	rep(i, n) {
		if (bids.find(b[i]) == bids.end()) {
			int mlen = bids.size();
			bids[b[i]] = mlen;
		}
	}
	if ((int)(bids.size()) < n) {
		cout << "Yes" << endl;
		return 0;
	}
	rep(i, n) a[i] = bids[a[i]];
	rep(i, n) b[i] = bids[b[i]];
	fenwick_tree<ll> acnt(n+1), bcnt(n+1);
	ll arev = 0, brev = 0;
	repr(i, n) {
		arev += acnt.sum(0, a[i]);
		acnt.add(a[i], 1);
	}
	repr(i, n) {
		brev += bcnt.sum(0, b[i]);
		bcnt.add(b[i], 1);
	}
	if (abs(arev-brev)%2 == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
