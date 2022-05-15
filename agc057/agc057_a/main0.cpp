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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int l, r;
		cin >> l >> r;
		string sl = to_string(l), sr = to_string(r);
		int ten = 1, rlen = sr.length();
		rep(i, rlen-1) ten *= 10;
		if (sl.length() == sr.length()) cout << (r-l+1) << endl;
		else if (sr[0] != '1') cout << (r-ten+1) << endl;
		else {
			int ci = max(stoi(sr.substr(0, rlen-1)), stoi(sr.substr(1))) + 1;
			ci = max(ci, l);
			int sub = ten - ci;
			cout << (r-ten+1+sub) << endl;
		}
	}
	return 0;
}
