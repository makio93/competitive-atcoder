// 解説AC1

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
	vector<bool> square(n+1);
	for (int i=1; i*i<=n; ++i) square[i*i] = true;
	unordered_map<int, vector<int>> vlst;
	rep3(i, 1, n+1) {
		int mval = 0;
		for (int j=1; j*j<=i; ++j) if (i%j == 0) {
			if (square[j]) mval = max(mval, j);
			if (j!=i/j && square[i/j]) mval = max(mval, i/j);
		}
		vlst[i/mval].push_back(i);
	}
	ll res = 0;
	for (auto& lst : vlst) res += (ll)lst.second.size() * lst.second.size();
	cout << res << endl;
	return 0;
}
