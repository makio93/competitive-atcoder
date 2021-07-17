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

// 本番中に実装、方針を途中で修正

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	map<string, set<int>> bdict;
	rep(i, n) {
		int slen = s[i].length();
		bdict[s[i].substr(slen-3)].insert(i);
	}
	vector<vector<int>> rg(n);
	rep(i, n) if (bdict.find(s[i].substr(0, 3)) != bdict.end()) {
		for (int id : bdict[s[i].substr(0, 3)]) rg[i].push_back(id);
	}
	vector<set<bool>> vals(n);
	rep(i, n) if ((int)(rg[i].size()) <= 1) {
		if ((int)(rg[i].size()) == 0) vals[i].insert(true);
		else {
			queue<int> que;
			vector<int> dist(n, INF);
			que.push(i);
			dist[i] = 0;
			vals[i].insert(true);
			while (!que.empty()) {
				int v = que.front(); que.pop();
				int d = dist[v], nd = d + 1;
				bool nval = (nd%2 == 0);
				for (int t : rg[v]) if (vals[t].find(nval) == vals[t].end()) {
					if (nval) {
						//if (vals[t].find(false) != vals[t].end()) vals[t].erase(false);
						que.push(t);
						dist[t] = nd;
						vals[t].insert(true);
					}
					else {
						//if (vals[t].find(true) == vals[t].end()) {
							que.push(t);
							dist[t] = nd;
							vals[t].insert(nval);
						//}
					}
				}
			}
		}
	}
	rep(i, n) {
		if (vals[i].empty() || ((int)(rg[i].size())==1&&rg[i][0]==i)) cout << "Draw" << endl;
		else if (vals[i].find(false)==vals[i].end()) cout << "Takahashi" << endl;
		else cout << "Aoki" << endl;
	}
	return 0;
}
