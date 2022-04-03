// 本番2,WA

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

int cnt = 0;
bool calc(string& s, int k, int l, int r) {
	int len = r - l;
	if (k == 0) {
		if (len <= 0) return false;
		else {
			if (len == 1) return false;
			else {
				int l1 = l, r1 = r - 1;
				bool pal = true;
				while (l1 < r1) {
					if (s[l1] != s[r1]) {
						pal = false;
						break;
					}
					++l1; --r1;
				}
				if (pal) {
					s[l+(len-1)/2] = '$';
					++cnt;
				}
				return true;
			}
		}
	}
	else if (k >= 1) {
		if (len <= 0) return false;
		else if (len == 1) {
			if (k == 1) return true;
			else return false;
		}
		else if (len==2 && k==1) return false;
		else {
			int len2 = len / 2;
			if (!calc(s, k-1, l, l+len2)) return false;
			else {
				int l1 = l, r2 = r - 1;
				rep(i, len2) {
					if (s[l1+i] != s[r2-i]) {
						s[r2-i] = s[l1+i];
						if (s[l1+i] != '$') ++cnt;
					}
				}
				return true;
			}
		}
	}
}

int main() {
	int k;
	cin >> k;
	string s;
	cin >> s;
	string s2 = s;
	bool res = calc(s2, k, 0, (int)(s.length()));
	if (!res) {
		cout << "impossible" << endl;
		return 0;
	}
	int cntl = cnt;
	cnt = 0;
	reverse(all(s));
	res = calc(s, k, 0, (int)(s.length()));
	int cntr = cnt;
	cout << min(cntl, cntr) << endl;
	return 0;
}
