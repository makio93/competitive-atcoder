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
	string tp, rtp;
	cin >> n >> tp;
	rtp = tp;
	reverse(all(rtp));
	int m = tp.length();
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	function<int(string&, string&)> scalc = [&](string& str, string& tstr) {
		int rval = 0, slen = str.length();
		rep(j, slen) {
			if (j >= m || str[j] != tstr[j]) break;
			++rval;
		}
		return rval;
	};
	vector<int> res;
	rep(i, n) {
		int ai = scalc(s[i], tp), slen = s[i].length();
		reverse(all(s[i]));
		int bi = scalc(s[i], rtp);
		bool ok = false;
		if (m == slen && ai+bi >= m-1) ok = true;
		if (m+1 == slen && ai+bi >= m) ok = true;
		if (m == slen+1 && ai+bi >= slen) ok = true;
		if (ok) res.push_back(i);
	}
	int k = res.size();
	cout << k << endl;
	if (k == 0) cout << endl;
	else rep(i, k) cout << (res[i]+1) << (i<k-1?' ':'\n');
	return 0;
}
