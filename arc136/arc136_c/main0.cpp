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

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	if (n == 1) {
		cout << a[0] << endl;
		return 0;
	}
	vector<pair<int, int>> alst(n);
	rep(i, n) alst[i] = { a[i], i };
	sort(alst.rbegin(), alst.rend());
	set<int> aids;
	ll res = 0;
	int bcnt = 0;
	rep(i, n) {
		aids.insert(alst[i].second);
		int add = 1, id = alst[i].second, aval = alst[i].first;
		if (aids.find((id+1)%n) != aids.end()) --add;
		if (aids.find((id-1+n)%n) != aids.end()) --add;
		bcnt += add;
		if (bcnt <= 0) {
			bcnt = 1;
			--res;
		}
		int sub = aval - (i+1<n ? alst[i+1].first : 0);
		res += (ll)sub * bcnt;
	}
	cout << res << endl;
	return 0;
}
