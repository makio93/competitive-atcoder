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
	string n;
	cin >> n;
	int len = n.length();
	vector<int> ord(len);
	rep(i, len) ord[i] = i;
	ll res = 0;
	do {
		string vstr;
		rep(i, len) vstr += n[ord[i]];
		if (vstr[0] == '0') continue;
		rep3(i, 1, len) if (vstr[i] != '0') {
			ll val = stoll(vstr.substr(0, i)) * stoll(vstr.substr(i));
			res = max(res, val);
		}
	} while (next_permutation(all(ord)));
	cout << res << endl;
	return 0;
}
