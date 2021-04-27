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

// 解説を見てから実装、(k日先まで見た)貪欲法のみの方針

struct input {
	int d;
	vector<int> c;
	vector<vector<int>> s;
	input(int d, vector<int> c, vector<vector<int>> s) : d(d), c(c), s(s) {}
};
typedef vector<int> output;

ll scalc(input& in, output& out, int len=0) {
	if (len == 0) len = in.d;
	vector<int> last(26);
	ll res = 0;
	rep(i, len) {
		res += in.s[i][out[i]];
		last[out[i]] = i + 1;
		rep(j, 26) res -= (ll)((i+1) - last[j]) * in.c[j];
	}
	return res;
}

// k日先の最適解を見るように改良
void gsolve(input& in, output& out, int k=0) {
	vector<int> last(26);
	rep(i, in.d) {
		pair<ll, int> dif = { (ll)(-1e15), -1 };
		rep(j, 26) {
			int dlen = min(in.d,i+k+1) - (i+1) + 1;
			ll choose = in.s[i][j] - (ll)(in.c[j])*(min(in.d,i+k+1)-(i+1))*(min(in.d,i+k+1)-(i+1)+1)/2;
			ll nochoose = -(ll)(in.c[j])*((i+1-last[j])+(i+dlen-last[j]))*(dlen)/2;
			dif = max(dif, { choose - nochoose, j });
		}
		out[i] = dif.second;
		last[dif.second] = i+1;
	}
}

int main() {
	int d;
	cin >> d;
	vector<int> c(26);
	rep(i, 26) cin >> c[i];
	vector<vector<int>> s(d, vector<int>(26));
	rep(i, d) rep(j, 26) cin >> s[i][j];
	input in(d, c, s);
	pair<ll, output> sres = { (ll)(-1e15), output() };
	rep(i, d) {
		output tout(d);
		gsolve(in, tout, i);
		sres = max(sres, { scalc(in, tout), tout });
	}
	rep(i, d) cout << (sres.second[i]+1) << endl;
	// cout << max(0LL, (ll)(1e6)+scalc(in, out)) << endl;
	return 0;
}
