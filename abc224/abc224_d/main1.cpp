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

int main() {
	int n = 9, m;
	cin >> m;
	vector<unordered_set<int>> g(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].insert(vi);
		g[vi].insert(ui);
	}
	vector<int> vals(n, 8);
	rep(i, n-1) {
		int pi;
		cin >> pi;
		--pi;
		vals[pi] = i;
	}
	string si, tar = "012345678";
	rep(i, n) si += (char)(vals[i]+'0');
	unordered_map<string, int> dist;
	queue<string> que;
	dist[si] = 0;
	que.push(si);
	while (!que.empty()) {
		string vstr = que.front(); que.pop();
		int d = dist[vstr], nd = d + 1;
		int pid = -1;
		rep(i1, 9) if (vstr[i1] == '8') pid = i1;
		for (int ti : g[pid]) {
			string tstr = vstr;
			swap(tstr[pid], tstr[ti]);
			if (dist.find(tstr)!=dist.end() && dist[tstr]<=nd) continue;
			dist[tstr] = nd;
			if (tstr != tar) que.push(tstr);
		}
	}
	if (dist.find(tar) != dist.end()) cout << dist[tar] << endl;
	else cout << -1 << endl;
}
