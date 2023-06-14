// 解説AC

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
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	rep(i, n) {
		cin >> b[i];
		b[i]--;
	}
	vector<int> acnt(n), bcnt(n);
	rep(i, n) acnt[a[i]]++;
	rep(i, n) bcnt[b[i]]++;
	if (acnt != bcnt) {
		cout << "No" << endl;
		return 0;
	}
	if (*max_element(all(acnt)) >= 2) {
		cout << "Yes" << endl;
		return 0;
	}
	fenwick_tree<ll> aft(n), bft(n);
	ll aval = 0, bval = 0;
	repr(i, n) {
		aval += aft.sum(0, a[i]);
		aft.add(a[i], 1);
	}
	repr(i, n) {
		bval += bft.sum(0, b[i]);
		bft.add(b[i], 1);
	}
	if (aval%2 == bval%2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
