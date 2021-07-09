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

// 自力解答、WA

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int sum = 0;
	rep(i, n) sum += a[i];
	vector<vector<int>> g(n);
	rep(i, q) {
		int xi, yi;
		cin >> xi >> yi;
		--xi; --yi;
		g[xi].push_back(yi);
		g[yi].push_back(xi);
	}
	vector<set<int>> val(sum+1), res;
	vector<bool> exist(sum+1), visited(n);
	exist[0] = true;
	rep(i, n) {
		vector<vector<bool>> existl(2);
		vector<vector<set<int>>> vall(2);
		rep(i0, 2) {
			if (!visited[i]) {
				vector<set<int>> vali(sum+1);
				vector<bool> existi(sum+1);
				vector<int> visitedi(n, -1);
				existi[0] = true;
				function<bool(int,int,int)> dfs = [&](int v, int p, int c) {
					visited[v] = true;
					visitedi[v] = c;
					if (c == 1) {
						repr(i1, sum) if (existi[i1]) {
							auto tmps = vali[i1];
							tmps.insert(v);
							if (existi[i1+a[v]] && vali[i1+a[v]]!=tmps) {
								res.push_back(vali[i1+a[v]]);
								res.push_back(tmps);
								return false;
							}
							else if (!existi[i1+a[v]]) {
								existi[i1+a[v]] = true;
								vali[i1+a[v]] = tmps;
							}
						}
					}
					for (int t : g[v]) if (t != p) {
						if (visitedi[t] != -1) continue;
						if (c == 0) {
							bool ok = true;
							rep(i2, (int)(g[t].size())) if (visitedi[g[t][i2]] == 1) ok = false;
							if (ok && !dfs(t, v, 1)) return false;
						}
						if (!dfs(t, v, 0)) return false;
					}
					visitedi[v] = -1;
					return true;
				};
				if (!dfs(i, -1, i0)) break;
				else {
					existl[i0] = existi;
					vall[i0] = vali;
				}
			}
		}
		if ((int)(res.size()) == 2) break;
		rep3r(i1, 1, sum+1) if (existl[0][i1] && existl[1][i1]) {
			if (vall[0][i1] != vall[1][i1]) {
				res.push_back(vall[0][i1]);
				res.push_back(vall[1][i1]);
				break;
			}
		}
		if ((int)(res.size()) == 2) break;
		rep(i0, 2) {
			rep3r(i1, 1, sum+1) if (existl[i0][i1]) {
				repr(j, sum+1) if (exist[j]) {
					if (j+i1 > sum) continue;
					if (j+i1 <= sum) {
						auto tmps = val[j];
						for (int v2 : vall[i0][i1]) tmps.insert(v2);
						if (exist[j+i1] && val[j+i1]!=tmps) {
							res.push_back(val[j+i1]);
							res.push_back(tmps);
							break;
						}
					}
				}
			}
			if ((int)(res.size()) == 2) break;
		}
		if ((int)(res.size()) == 2) break;
	}
	rep(i, 2) {
		int ri = res[i].size();
		cout << ri << endl;
		int id = 0;
		for (auto itr=res[i].begin(); itr!=res[i].end(); ++itr,++id) printf("%d%c", (*itr)+1, (id<ri-1?' ':'\n'));
	}
	return 0;
}
