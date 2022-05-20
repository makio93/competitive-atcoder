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

int main() {
	int n;
	ll x;
	cin >> n >> x;
	vector<vector<int>> a(n);
	rep(i, n) {
		int li;
		cin >> li;
		rep(j, li) {
			int ai;
			cin >> ai;
			a[i].push_back(ai);
		}
	}
	unordered_map<ll, ll> cnt;
	cnt[1] = 1;
	rep(i, n) {
		unordered_map<ll, ll> ncnt;
		for (int aj : a[i]) for (auto pi : cnt) if (pi.first <= x/aj) ncnt[pi.first*aj] += pi.second;
		swap(ncnt, cnt);
	}
	cout << cnt[x] << endl;
	return 0;
}
