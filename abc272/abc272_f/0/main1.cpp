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
	string s, t;
	cin >> n >> s >> t;
	string x = s + s + string(n, 'a') + t + t + string(n, 'z');
	auto sa = suffix_array(x);
	ll res = 0;
	int tcnt = 0, xlen = sa.size();
	repr(i, xlen) {
		if (sa[i] < n) res += tcnt;
		else if (sa[i]>=3*n && sa[i]<4*n) ++tcnt;
	}
	cout << res << endl;
	return 0;
}
