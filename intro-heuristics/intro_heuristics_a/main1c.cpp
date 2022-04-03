#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 単純な山登り法

struct input {
	int d;
	vector<int> c;
	vector<vector<int>> s;
	input(int d, vector<int> c, vector<vector<int>> s) : d(d), c(c), s(s) {}
};
typedef vector<int> output;

time_t st;

double now_time() { return (double)(clock() - st) / CLOCKS_PER_SEC; }

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

/*
void gsolve(input& in, vector<int>& out) {
	vector<int> last(26);
	rep(i, in.d) {
		pair<ll, int> dif = { (ll)(-1e15), -1 };
		rep(j, 26) dif = max(dif, { (ll)(in.s[i][j])+(ll)(in.c[j])*((i+1)-last[j]), j });
		out[i] = dif.second;
		last[dif.second] = i+1;
	}
}
*/

void rsolve(input& in, vector<int>& out, double tl=1.9) {
    srand(time(NULL));
    rep(i, in.d) out[i] = rand() % 26;
    ll score = scalc(in, out);
    while (now_time() < tl) {
        int nd = rand() % in.d, nc = rand() % 26, pc = out[nd];
        out[nd] = nc;
        ll nscore = scalc(in, out);
        if (nscore > score) score = nscore;
        else out[nd] = pc;
    }
}

int main() {
    st = clock();
	int d;
	cin >> d;
	vector<int> c(26);
	rep(i, 26) cin >> c[i];
	vector<vector<int>> s(d, vector<int>(26));
	rep(i, d) rep(j, 26) cin >> s[i][j];
	input in(d, c, s);
	output out(d);
	rsolve(in, out);
	rep(i, d) cout << (out[i]+1) << endl;
	// cout << max(0LL, (ll)(1e6)+scalc(in, out)) << endl;
    return 0;
}
