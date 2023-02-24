// 解説AC2

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
	ll res = 0;
	rep3(i1, 1, n+1) {
		int ival = i1;
		vector<pair<int, int>> plst;
		for (int i=2; i*i<=ival; ++i) if (ival%i==0) {
			plst.emplace_back(i, 0);
			while (ival%i == 0) {
				plst.back().second++;
				ival /= i;
			}
		}
		if (ival > 1) plst.emplace_back(ival, 1);
		int jval = 1;
		for (auto pi : plst) if (pi.second%2 == 1) jval *= pi.first;
		ival = i1;
		int icnt = 1;
		while ((ll)jval*icnt*icnt <= (ll)n) {
			++res;
			++icnt;
		}
	}
	cout << res << endl;
	return 0;
}
