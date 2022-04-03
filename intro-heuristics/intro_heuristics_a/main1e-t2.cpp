#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 

clock_t st;

double now_time(clock_t nt=0L) {
	if (nt == 0L) nt = clock();
	return (double)(nt - st) / CLOCKS_PER_SEC;
}

struct input {
	int d;
	vector<int> c;
	vector<vector<int>> s;
	input(int d, vector<int> c, vector<vector<int>> s) : d(d), c(c), s(s) {}
};

typedef vector<int> output;

output tstat;
vector<set<int>> tds;

class states {
	ll score;
	output stat;
	vector<set<int>> ds;
public:
	states(input& in, output out) {
		score = 0LL;
		stat = out;
		ds = vector<set<int>>(26);
		init_score(in);
	}
	void init_score(input& in) {
		rep(i, 26) ds[i].insert(0);
		rep(i, in.d) {
			score += in.s[i][stat[i]];
			score -= (ll)in.c[stat[i]] * ((i+1)-(*ds[stat[i]].rbegin())) * ((i+1)-(*ds[stat[i]].rbegin())-1) / 2;
			ds[stat[i]].insert(i+1);
		}
		rep(i, 26) {
			score -= (ll)in.c[i] * (in.d-(*ds[i].rbegin())) * (in.d-(*ds[i].rbegin())+1) / 2;
			ds[i].insert(in.d+1);
		}
	}
	output output_states() { return stat; }
	ll diff_score(input& in, int c1, int c2) {
		ll dres = 0;
		int pdi = 0;
		for (int di : ds[c1]) {
			if (di == 0) continue;
			if (di-1 < in.d) dres += in.s[di-1][c1];
			dres -= (ll)in.c[c1] * (di-pdi) * (di-pdi-1) / 2;
			pdi = di;
		}
		pdi = 0;
		for (int di : ds[c2]) {
			if (di == 0) continue;
			if (di-1 < in.d) dres += in.s[di-1][c2];
			dres -= (ll)in.c[c2] * (di-pdi) * (di-pdi-1) / 2;
			pdi = di;
		}
		return dres;
	}
	bool change_state(input& in, bool mode, int p, int q) {
		tstat = stat;
		tds = ds;
		if (mode) {
			int pc = stat[p];
			ll old_diff = diff_score(in, pc, q);
			ds[pc].erase(p+1);
			stat[p] = q;
			ds[q].insert(p+1);
			ll next_diff = diff_score(in, pc, q);
			if (next_diff > old_diff) {
				score += next_diff - old_diff;
				return true;
			}
			else {
				/*
				ds[q].erase(p+1);
				stat[p] = pc;
				ds[pc].insert(p+1);
				*/
				stat = tstat;
				ds = tds;
				return false;
			}
		}
		else {
			ll old_diff = diff_score(in, stat[p], stat[q]);
			ds[stat[p]].erase(p+1);
			ds[stat[p]].insert(q+1);
			ds[stat[q]].erase(q+1);
			ds[stat[q]].insert(p+1);
			swap(stat[p], stat[q]);
			ll next_diff = diff_score(in, stat[q], stat[p]);
			if (next_diff > old_diff) {
				score += next_diff - old_diff;
				return true;
			}
			else {
				/*
				swap(stat[p], stat[q]);
				ds[stat[q]].erase(p+1);
				ds[stat[q]].insert(q+1);
				ds[stat[p]].erase(q+1);
				ds[stat[p]].insert(p+1);
				*/
				stat = tstat;
				ds = tds;
				return false;
			}
		}
	}
};

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

void rsolve(input& in, output& out, double tl=1.9) {
	srand(time(NULL));
    rep(i, in.d) out[i] = rand() % 26;
	states st(in, out);
    while (now_time() < tl) {
		if (rand()/(double)(RAND_MAX) < 0.5) {
			int nd = rand() % in.d, nc = rand() % 26;
			st.change_state(in, true, nd, nc);
		}
		else {
			int dl = rand() % in.d, dlen = min(in.d, dl+16) - dl, dr = dl + rand() % dlen;
			st.change_state(in, false, dl, dr);
		}
    }
	output res = st.output_states();
	out = res;
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
	//rep(i, d) cout << (out[i]+1) << endl;
	cout << max(0LL, (ll)(1e6)+scalc(in, out)) << endl;
    return 0;
}
