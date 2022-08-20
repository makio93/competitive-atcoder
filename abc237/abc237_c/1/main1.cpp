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
	string s;
	cin >> s;
	int n = s.length(), ri = n-1, li = 0;
	while (ri>=0 && s[ri]=='a') --ri;
	while (li<=ri && s[li]=='a') ++li;
	if (li > n-ri-1) {
		cout << "No" << endl;
		return 0;
	}
	int lj = li, rj = ri;
	while (lj<rj && s[lj]==s[rj]) ++lj, --rj;
	if (lj >= rj) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
