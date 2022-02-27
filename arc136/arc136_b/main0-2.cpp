// 本番WA2

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
	vector<int> alst, blst;
	unordered_set<int> ause, buse;
	repr(i, n) {
		if (ause.find(a[i]) == ause.end()) {
			alst.push_back(bids[a[i]]);
			ause.insert(a[i]);
		}
	}
	repr(i, n) {
		if (buse.find(b[i]) == buse.end()) {
			blst.push_back(bids[b[i]]);
			buse.insert(b[i]);
		}
	}
	reverse(all(alst));
	reverse(all(blst));
	fenwick_tree<ll> acnt(n+1), bcnt(n+1);
	ll arev = 0, brev = 0;
	repr(i, (int)(alst.size())) {
		arev += acnt.sum(0, alst[i]);
		acnt.add(alst[i], 1);
	}
	repr(i, (int)(blst.size())) {
		brev += bcnt.sum(0, blst[i]);
		bcnt.add(blst[i], 1);
	}
	if (abs(arev-brev)%2 == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
