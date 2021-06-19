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

// 頑張ってやろうとした、やめよう

// vector<vector<int>> create(vector<vector<int>>& g, map<int, int>& in, )

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> g(n);
	vector<int> incnt(n);
	dsu d(n);
	scc_graph sg(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		incnt[bi]++;
		d.merge(ai, bi);
		sg.add_edge(ai, bi);
	}
	auto sl = sg.scc();
	if ((int)(sl.size()) < n) {
		cout << -1 << endl;
		return 0;
	}
	auto dl = d.groups();
	int gi = dl.size(), ci = 1;
	rep3(i, 1, gi+1) {
		if (ci >= k) break;
		ci *= i;
	}
	map<int, vector<int>> ord;
	rep(i, n) {
		int li = d.leader(sl[i].front());
		ord[li].push_back(sl[i].front());
	}
	vector<vector<int>> gl;
	for (auto vi : ord) gl.emplace_back(vi.second);
	int llen = gl.size();
	if (ci >= k) {
		vector<int> pn(llen);
		rep(i, llen) pn[i] = i;
		int ri = 0;
		do {
			vector<int> res;
			rep(i, llen) {
				int pid = pn[i];
				rep(j, (int)(gl[pid].size())) res.push_back(gl[pid][j]+1);
			}
			rep(i, n) printf("%d%c", res[i], (i<n-1?' ':'\n'));
			++ri;
			if (ri >= k) break;
		} while (next_permutation(all(pn)));
		return 0;
	}
	int kcnt = 0;
	rep(i, n) {
		int gri = g[i].size();
		if (gri == 0) continue;
		int kc2 = 1;
		rep3(i, 1, gri+1) {
			kc2 *= i;
			if (kcnt+kc2 >= k) break;
		}
		kcnt += kc2;
		if (kcnt >= k) break;
	}
	if (kcnt < k) {
		cout << -1 << endl;
		return 0;
	}
	/*
	vector<vector<vector<int>>> res(llen);
	int ccnt0 = kcnt;
	rep(i, llen) {
		int ccnt = 1;
		set<int> s;
		vector<set<int>> slst;
		rep(j, gl[i].size()) if (g[gl[i][j]].size()==1 && incnt[gl[i][j]]==0) s.insert(gl[i][j]);
		if (ccnt0 < k) {
			if ((int)(s.size()) > 1) {
				slst.push_back(s);
				int cc2 = 1;
				rep3(j, 1, (int)(s.size())+1) {
					cc2 *= j;
					if (ccnt0*(ccnt+cc2) >= k) break;
				}
				ccnt += cc2-1;
			}
		}
		vector<int> vi;
		while (!s.empty()) {
			int si = *s.begin(); s.erase(s.begin());
			vi.push_back(si);
			set<int> ts;
			rep(j, g[si].size()) {
				incnt[g[si][j]]--;
				if (incnt[g[si][j]] == 0) {
					s.insert(g[si][j]);
					st.insert(g[si][j]);
				}
			}
			if ((int)(ts.size()) > 1) {
				if (ccnt0*ccnt < k) {
					if ((int)(ts.size()) > 1) {
						slst.push_back(ts);
						int cc2 = 1;
						rep3(j, 1, (int)(ts.size())+1) {
							cc2 *= j;
							if (ccnt0*(ccnt+cc2) >= k) break;
						}
						ccnt += cc2;
					}
				}
			}
		}
		vector<vector<int>> resi;
		resi.push_back(vi);
		rep(j, (int)(slst.size())) {
			vector<int> vid;
			for (auto itr=slst[j].begin(); itr!=slst[j].end(); ++itr) {
				int sval = *itr;
				int vpid = vi.find(sval) - vi.begin();
				vid.push_back(vpid);
			}
			vector<int> pord((int)(vid.size()));
			rep(j2, (int)(pord.size())) pord[j2] = j2;
			rep(j2, (int)(vid.size())-1) 
			while (next_permutation(all(pord))) {

			}
		}
	}
	*/
	return 0;
}
