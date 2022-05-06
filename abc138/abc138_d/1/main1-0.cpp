// 学習1回目,解説での誤解法,WAになる

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
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> ab(n-1);
	rep(i, n-1) {
		cin >> ab[i].first >> ab[i].second;
		ab[i].first--; ab[i].second--;
	}
	vector<int> vals(n);
	rep(i, q) {
		int pi, xi;
		cin >> pi >> xi;
		--pi;
		vals[pi] += xi;
	}
	sort(all(ab));
	rep(i, n-1) vals[ab[i].second] += vals[ab[i].first];
	rep(i, n) cout << vals[i] << (i<n-1?' ':'\n');
	return 0;
}
