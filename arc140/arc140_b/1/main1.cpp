// 学習1回目,解説AC

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
	string s;
	cin >> n >> s;
	int xcnt = 0, xsum = 0;
	rep3(i, 1, n-1) if (s.substr(i-1, 3) == string("ARC")) {
		int li = i-1, ri = i+1;
		while (li>=0 && s[li]=='A') --li;
		while (ri<n && s[ri]=='C') ++ri;
		if (min(i-li-1, ri-i-1) > 0) {
			xsum += min(i-li-1, ri-i-1);
			++xcnt;
		}
	}
	cout << min(xcnt*2, xsum) << endl;
	return 0;
}
