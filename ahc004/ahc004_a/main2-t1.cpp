// AHC004:本番2-t1

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
const int csize = 1;
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
	vector<map<pair<int,int>,set<int>>> mval;
	map<int, ll> used;
	input *pin;
	output(int n) : n(n), b(n, string(n, 'A')) {}
	void init(input& in) {
		pin = &in;
		rep(i, n) rep(j, n) b[i][j] = (char)(b[i][j] + (rand() % 8));
		rep(i, n) b[i] += b[i];
		rep(i, n) b.push_back(b[i]);
		mval = vector<map<pair<int,int>,set<int>>>(n*n);
		score = pscore = calc();
		pb = b;
	}
	ll calc() {
		int cnt = 0;
		rep(i0, pin->m) {
			int slen = pin->s[i0].length();
			bool ok = false;
			rep(i, n) rep(j, n) {
				if (b[i].substr(j, slen) == pin->s[i0]) {
					ok = true;
					rep(i2, slen) mval[i*n+(j+i2)%n][{i2,0}].insert(i0);
					used[i0] += slen;
				}
				string b2;
				rep(i2, slen) b2 += b[i+i2][j];
				if (b2 == pin->s[i0]) {
					ok = true;
					rep(i2, slen) mval[(i+i2)%n*n+j][{i2,1}].insert(i0);
					used[i0] += slen;
				}
			}
			if (ok) {
				++cnt;
			}
		}
		return (score = (ll)round(double(1e8) / pin->m * double(cnt)));
	}
	bool diff_calc1(int p, char c) {
		ll diff1 = 0, diff2 = 0;
		map<int, ll> dused, dused2;
		set<int> sused, sused2;
		map<int,map<pair<int,int>,set<int>>> smval, smval2;
		for (auto pi : mval[p]) {
			int spos = pi.first.first, di = pi.first.second;
			for (int si : pi.second) {
				int sleni = pin->s[si].length();
				dused[si] += (int)(pin->s[si].length());
				diff1 += (int)(pin->s[si].length());
				if (di == 0) {
					for (int j2=(p%n+n-spos)%n; j2!=(p%n+n-spos+sleni)%n; j2=(j2+1)%n) smval[p/n+j2][{j2,0}].insert(si);
				}
				else {
					for (int i2=(p/n+n-spos)%n; i2!=(p/n+n-spos+sleni)%n; i2=(i2+1)%n) smval[i2*n+p%n][{i2,1}].insert(si);
				}
			}
		}
		for (auto dui : dused) if (dui.second >= used[dui.first]) sused.insert(dui.first);
		int scnt2 = 0;
		rep(i0, pin->m) {
			bool eok = false;
			rep(i, n) {
				int l = i, r = l+(int)(pin->s[i0].length())-1;
				if (r >= n) {
					int np2 = p%n + (p%n<l ? n : 0);
					if (l<=np2 && np2<=r) {
						string bt = b[p/n].substr(l, r-l+1);
						bt[np2-l] = c;
						if (bt == pin->s[i0]) {
							dused2[i0] += (int)(pin->s[i0].length());
							diff2 += (int)(pin->s[i0].length());
							rep3(i2, l, r+1) smval2[p/n*n+i2%n][{i2-l,0}].insert(i0);
							if (used.find(i0)==used.end() || (used.find(i0)!=used.end()&&sused.find(i0)!=sused.end())) {
								if (!eok) { ++scnt2; eok = true; }
							}
						}
					}
					int np3 = p/n + (p/n<l ? n : 0);
					if (l<=np3 && np3<=r) {
						string bt;
						rep3(i2, l, r+1) bt += b[i2][p%n];
						bt[np3-l] = c;
						if (bt == pin->s[i0]) {
							dused2[i0] += (int)(pin->s[i0].length());
							diff2 += (int)(pin->s[i0].length());
							rep3(i2, l, r+1) smval2[i2%n*n+p%n][{i2-l,1}].insert(i0);
							if (used.find(i0)==used.end() || (used.find(i0)!=used.end()&&sused.find(i0)!=sused.end())) {
								if (!eok) { ++scnt2; eok = true; }
							}
						} 
					}
				}
				else if (r < n) {
					if (l<=p%n && p%n<=r) {
						string bt = b[p/n].substr(l, r-l+1);
						bt[p%n-l] = c;
						if (bt == pin->s[i0]) {
							dused2[i0] += (int)(pin->s[i0].length());
							diff2 += (int)(pin->s[i0].length());
							rep3(i2, l, r+1) smval2[p/n*n+i2%n][{i2-l,0}].insert(i0);
							if (used.find(i0)==used.end() || (used.find(i0)!=used.end()&&sused.find(i0)!=sused.end())) {
								if (!eok) { ++scnt2; eok = true; }
							}
						}
					}
					if (l<=p/n && p/n<=r) {
						string bt;
						rep3(i2, l, r+1) bt += b[i2][p%n];
						bt[p/n-l] = c;
						if (bt == pin->s[i0]) {
							dused2[i0] += (int)(pin->s[i0].length());
							diff2 += (int)(pin->s[i0].length());
							rep3(i2, l, r+1) smval2[i2*n+p%n][{i2-l,1}].insert(i0);
							if (used.find(i0)==used.end() || (used.find(i0)!=used.end()&&sused.find(i0)!=sused.end())) {
								if (!eok) { ++scnt2; eok = true; }
							}
						}
					}
				}
			}
		}
		if (diff2 > diff1) {
			int sdcnt = scnt2 - (int)(sused.size());
			ll difscore = round((double)(1e8) / (double)pin->m * (sdcnt));
			score += difscore;
			for (auto m1 : smval) {
				int pi = m1.first;
				for (auto p1 : m1.second) {
					for (int s1 : p1.second) mval[pi][p1.first].erase(s1);
				}
			}
			for (auto du1 : dused) used[du1.first] -= du1.second;
			for (auto m2 : smval2) {
				int pi2 = m2.first;
				for (auto p2 : m2.second) {
					for (int s2 : p2.second) mval[pi2][p2.first].insert(s2);
				}
			}
			for (auto du2 : dused2) used[du2.first] += du2.second;
			return true;
		}
		else return false;
	}
	bool change1(int p, char c) {
		if (b[p/n][p%n] == c) return false;
		rep(i0, 2) rep(j0, 2) b[p/n+i0*n][p%n+j0*n] = (char)('A'+c);
		diff_calc1(p, c);
		/*
		if (score > pscore) { apply1(p, c); return true; }
		else { repair1(p); return false; }
		*/
	}
	bool change2(int p, int q) {
		if (p==q || b[p/n][p%n]==b[q/n][q%n]) return false;
		rep(i0, 2) rep(j0, 2) swap(b[p/n+i0*n][p%n+j0*n], b[q/n+i0*n][q%n+j0*n]);
		char pc = b[p/n][p%n];
		if (diff_calc1(p, b[q/n][q%n])) diff_calc1(q, pc);

		/*
		calc();
		if (score > pscore) { apply2(p, q); return true; }
		else { repair2(p, q); return false; }
		*/
	}
	void apply1(int p) {
		pscore = score;
		rep(i0, 2) rep(j0, 2) pb[p/n+i0*n][p%n+j0*n] = b[p/n+i0*n][p%n+j0*n];
		++tcnt;
	}
	void repair1(int p) {
		score = pscore;
		rep(i0, 2) rep(j0, 2) b[p/n+i0*n][p%n+j0*n] = pb[p/n+i0*n][p%n+j0*n];
	}
	void apply2(int p, int q) {
		pscore = score;
		rep(i0, 2) rep(j0, 2) {
			pb[p/n+i0*n][p%n+j0*n] = b[p/n+i0*n][p%n+j0*n];
			pb[q/n+i0*n][q%n+j0*n] = b[q/n+i0*n][q%n+j0*n];
		}
		++tcnt;
	}
	void repair2(int p, int q) {
		score = pscore;
		rep(i0, 2) rep(j0, 2) {
			b[p/n+i0*n][p%n+j0*n] = pb[p/n+i0*n][p%n+j0*n];
			b[q/n+i0*n][q%n+j0*n] = pb[q/n+i0*n][q%n+j0*n];
		}
	}
};

void rsolve(input& in, output& out, int tl=2.9) {
	out.init(in);
	int n = in.n;
	while (now_time() < tl) {
		if ((double)(rand())/RAND_MAX < 0.5) out.change1(rand()%(n*n), (char)('A'+rand()%8));
		else out.change2(rand()%(n*n), rand()%(n*n));
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
	rep(i, n) cout << res[i].substr(0, n) << endl;
	return 0;
}
