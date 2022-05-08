// 本番,TLE

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
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	cin >> q;
	vector<int> x(q), y(q);
	rep(i, q) cin >> x[i] >> y[i];
	vector<int> qid(q);
	iota(all(qid), 0);
	int sq = max(1, (int)sqrt(q));
	sort(all(qid), [&](int v1, int v2) {
		if (y[v1]/sq != y[v2]/sq) return y[v1]/sq < y[v2]/sq;
		else {
			if ((y[v1]/sq)%2 == 0) return x[v1] < x[v2];
			else return x[v1] > x[v2];
		}
	});
	unordered_map<int, int> acnt, bcnt;
	unordered_set<int> unsame;
	auto aadd = [&](int val, int sub) -> void {
		acnt[val] += sub;
		if ((acnt[val]==0) == (bcnt[val]==0)) {
			if (unsame.find(val) != unsame.end()) unsame.erase(val);
		}
		else unsame.insert(val);
		if (acnt[val] == 0) acnt.erase(val);
	};
	auto badd = [&](int val, int sub) -> void {
		bcnt[val] += sub;
		if ((acnt[val]==0) == (bcnt[val]==0)) {
			if (unsame.find(val) != unsame.end()) unsame.erase(val);
		}
		else unsame.insert(val);
		if (bcnt[val] == 0) bcnt.erase(val);
	};
	vector<bool> ans(q);
	int yi = 0, xi = 0;
	rep(i, q) {
		while (xi < x[qid[i]]) {
			aadd(a[xi], 1);
			++xi;
		}
		while (xi > x[qid[i]]) {
			--xi;
			aadd(a[xi], -1);
		}
		while (yi < y[qid[i]]) {
			badd(b[yi], 1);
			++yi;
		}
		while (yi > y[qid[i]]) {
			--yi;
			badd(b[yi], -1);
		}
		ans[qid[i]] = (unsame.empty());
	}
	rep(i, q) {
		if (ans[i]) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
