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

const int INF = (int)(1e9);

int main() {
	int n;
	string tp;
	cin >> n >> tp;
	int m = tp.length();
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<int> res;
	rep(i, n) {
		if (s[i].length() == m) {
			int cnt = 0;
			rep(j, m) if (s[i][j] != tp[j]) ++cnt;
			if (cnt <= 1) res.push_back(i);
		}
		else if (s[i].length()+1 == m) {
			int li = 0, ri = m-1;
			while (li<m-1 && tp[li]==s[i][li]) ++li;
			while (ri>0 && tp[ri]==s[i][ri-1]) --ri;
			if (li >= ri) res.push_back(i);
		}
		else if (s[i].length()-1 == m) {
			int li = 0, ri = m;
			while (li<m && s[i][li]==tp[li]) ++li;
			while (ri>0 && s[i][ri]==tp[ri-1]) --ri;
			if (li >= ri) res.push_back(i);
		}
	}
	int k = res.size();
	cout << k << endl;
	if (k == 0) cout << endl;
	else rep(i, k) cout << (res[i]+1) << (i<k-1?' ':'\n');
	return 0;
}
