#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番AC

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<int> dist(n+1, INF);
	queue<int> que;
	dist[n] = 0;
	que.push(n);
	while (!que.empty()) {
		int v = que.front(); que.pop();
		int d = dist[v], nd = d + 1;
		string vstr = to_string(v);
		int mcnt = min(v-1, (int)(vstr[0]-'0')+9*((int)(vstr.length())-1));
		rep3(i, 1, mcnt+1) if (dist[v-i] == INF) {
			string nstr = to_string(v-i);
			int add = 0;
			for (char ci : nstr) add += (int)(ci - '0');
			if (v-i+add != v) continue;
			dist[v-i] = nd;
			que.push(v-i);
		}
	}
	int res = 0;
	rep3(i, 1, n+1) if (dist[i] != INF) ++res;
	cout << res << endl;
	return 0;
}
