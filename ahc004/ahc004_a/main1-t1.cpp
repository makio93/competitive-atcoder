// AHC004:本番1-t1

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
const int csize = 10;
int tcnt, rcnt;

double now_time(clock_t nt=0L) {
	if (nt == 0L) nt = clock();
	double dnt = (double)(nt - st) / CLOCKS_PER_SEC;
	if (tcnt >= rcnt) {
		cout << "Current is " << tcnt << "times, ";
		printf("Passed time : %.5f ms.\n", dnt);
		rcnt += csize;
	}
	return dnt;
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
	input *pin;
	output(int n) : n(n), b(n, string(n, 'A')) {}
	void init(input& in) {
		pin = &in;
		rep(i, n) rep(j, n) b[i][j] = (char)(b[i][j] + (rand() % 8));
		rep(i, n) b[i] += b[i];
		rep(i, n) b.push_back(b[i]);
		score = pscore = calc();
		pb = b;
	}
	bool change(int p, char c) {
		if (b[p/n][p%n] == c) return false;
		rep(i0, 2) rep(j0, 2) b[p/n+i0*n][p%n+j0*n] = (char)('A'+c);
		calc();
		if (score > pscore) { apply(); return true; }
		else { repair(); return false; }
	}
	bool exchange(int p, int q) {
		if (p==q || b[p/n][p%n]==b[q/n][q%n]) return false;
		rep(i0, 2) rep(j0, 2) swap(b[p/n+i0*n][p%n+j0*n], b[q/n+i0*n][q%n+j0*n]);
		calc();
		if (score > pscore) { apply(); return true; }
		else { repair(); return false; }
	}
	ll calc() {
		int cnt = 0;
		rep(i0, pin->m) {
			int slen = pin->s[i0].length();
			bool ok = false;
			rep(i, n) {
				rep(j, n) {
					if (b[i].substr(j, slen) == pin->s[i0]) ok = true;
					else {
						string b2;
						rep(i2, slen) b2 += b[i+i2][j];
						if (b2 == pin->s[i0]) ok = true;
					}
					if (ok) break;
				}
				if (ok) break;
			}
			if (ok) ++cnt;
		}
		return (score = (ll)round(double(1e8) / pin->m * double(cnt)));
	}
	void apply() { pscore = score; pb = b; ++tcnt; }
	void repair() { score = pscore; b = pb; ++tcnt; }
};

void rsolve(input& in, output& out, int tl=2.9) {
	out.init(in);
	int n = in.n;
	while (now_time() < tl) {
		if ((double)(rand())/RAND_MAX < 0.5) out.change(rand()%(n*n), (char)('A'+rand()%8));
		else out.exchange(rand()%(n*n), rand()%(n*n));
	}
}

int main() {
	st = clock();
	tcnt = 0; rcnt = csize;
	srand(time(NULL));
	int n, m;
	cin >> n >> m;
	vector<string> s(m);
	rep(i, m) cin >> s[i];
	input in(n, m, s);
	output out(n);
	rsolve(in, out);
	auto res = out.b;
	//rep(i, n) cout << res[i].substr(0, n) << endl;
	return 0;
}
