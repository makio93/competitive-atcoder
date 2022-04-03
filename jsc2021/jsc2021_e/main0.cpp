// 本番1,WA

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

int calc(string& s, int k, int l, int r) {
	int d = r - l;
	if (k == 1) {
		if (d<=0 || (d==2)) return -1;
		else if (d <= 1) return 0;
		else {
			string s2 = s.substr(l, d);
			int res = 0, l1 = 0, r1 = (int)(s2.size())-1;
			while (l1<r1) {
				if (s2[l1] != s2[r1]) {
					++res;
					s2[r1] = s2[l1];
				}
				++l1; --r1;
			}
			string s3 = s2.substr(0, d/2), s3r = s3;
			reverse(all(s3r));
			if (s3 != s3r) return res;
			else res + 2;
		}
	}
	else {
		if (d <= 1) return -1;
		int r2 = d/2, l2 = (d+1)/2;
		int lval = calc(s, k-1, l, l+r2), rval = calc(s, k-1, l+l2, r);
		if (lval==-1 || rval==-1) return -1;
		else return lval + rval;
	}
}

int main() {
	int k;
	cin >> k;
	string s;
	cin >> s;
	if (k == 0) {
		if ((int)(s.length()) == 1) {
			cout << "impossible" << endl;
		}
		else {
			int res = 0, l = 0, r = s.length()-1;
			while (l<r) {
				if (s[l]==s[r]) ++res;
				++l; --r;
			}
			cout << res << endl;
		}
	}
	else {
		int res = calc(s, k, 0, (int)(s.size()));
		if (res >= 0) cout << res << endl;
		else cout << "impossible" << endl;
	}
	return 0;
}
