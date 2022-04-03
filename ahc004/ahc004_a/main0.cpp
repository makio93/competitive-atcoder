// AHC004:本番0

#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

clock_t st;

double now_time(clock_t nt=0L) {
	if (nt == 0L) nt = clock();
	return (double)(nt - st) / CLOCKS_PER_SEC;
}

struct input {
	int n, m;
	vector<string> s;
	input(int n, int m, vector<string> s) : n(n), m(m), s(s) {}
};

struct output {
	int n;
	vector<string> b, pb;
	ll score, pscore;
	output(int n) : n(n), b(n, string(n, 'A')) {}
	void init(input& in) {
		rep(i, n) rep(j, n) b[i][j] = (char)(b[i][j] + (rand() % 8));
		rep(i, n) b[i] += b[i];
		rep(i, n) b.push_back(b[i]);
		score = pscore = calc(in);
		pb = b;
	}
	ll calc(input& in) {
		int cnt = 0;
		rep(i0, in.m) {
			int slen = in.s[i0].length();
			bool ok = false;
			rep(i, n) {
				rep(j, n) {
					if (b[i].substr(j, slen) == in.s[i0]) ok = true;
					else {
						string b2;
						rep(i2, slen) b2 += b[i+i2][j];
						if (b2 == in.s[i0]) ok = true;
					}
					if (ok) break;
				}
				if (ok) break;
			}
			if (ok) ++cnt;
		}
		return (score = (ll)round(double(1e8) / in.m * double(cnt)));
	}
	void apply() { pscore = score; pb = b; }
	void repair() { score = pscore; b = pb; }
};

void rsolve(input& in, output& out, int tl=2.9) {
	out.init(in);
	int n = in.n;
	while (now_time() < tl) {
		if ((double)(rand())/RAND_MAX < 0.5) {
			int p = rand() % (n*n), c = rand() % 8;
			if (out.b[p/n][p%n] == (char)('A'+c)) continue;
			out.b[p/n][p%n] = (char)('A'+c);
			out.calc(in);
			if (out.score > out.pscore) out.apply();
			else out.repair();
		}
		else {
			int p = rand() % (n*n), q = rand() % (n*n);
			if (p==q || out.b[p/n][p%n]==out.b[q/n][q%n]) continue;
			swap(out.b[p/n][p%n], out.b[q/n][q%n]);
			out.calc(in);
			if (out.score > out.pscore) out.apply();
			else out.repair();
		}
	}
}

int main() {
	st = clock();
	srand(time(NULL));
	int n, m;
	cin >> n >> m;
	vector<string> s(m);
	rep(i, m) cin >> s[i];
	input in(n, m, s);
	output out(n);
	rsolve(in, out);
	auto res = out.b;
	rep(i, n) cout << res[i].substr(0, n) << endl;
	return 0;
}
