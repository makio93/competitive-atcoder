#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番AC

int main() {
	int n;
	cin >> n;
	vector<string> s(n), t(n);
	rep(i, n) cin >> s[i];
	rep(i, n) cin >> t[i];
	function<void(vector<string>&)> roll = [](vector<string>& a) {
		int n = a.size();
		vector<string> b(n, string(n, '.'));
		rep(i, n) rep(j, n) b[j][n-i-1] = a[i][j];
		swap(b, a);
	};
	int res = (int)(1e9);
	rep(i1, 4) {
		int val = i1;
		if (i1 == 3) val = 1;
		rep(i, n) rep(j, n) if (s[i][j] != t[i][j]) ++val;
		res = min(res, val);
		roll(s);
	}
	cout << res << endl;
	return 0;
}
