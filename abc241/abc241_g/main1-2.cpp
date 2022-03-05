// 解説AC,ACLインクルードなし

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    mf_graph(int n) : _n(n), g(n) {}
    int add_edge(int from, int to, int cap) {
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        g[from].push_back(_edge{to, int(g[to].size()), cap});
        g[to].push_back(_edge{from, int(g[from].size()) - 1, 0});
        return m;
    }
    struct edge {
        int from, to;
        int cap, flow;
    };
    int flow(int s, int t) {
        return flow(s, t, numeric_limits<int>::max());
    }
    int flow(int s, int t, int flow_limit) {
        vector<int> level(_n), iter(_n);
        queue<int> que;
        auto bfs = [&]() {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            queue<int>().swap(que);
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, int up) {
            if (v == s) return up;
            int res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                int d =
                    self(self, e.to, min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) break;
            }
            return res;
        };
        int flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            fill(iter.begin(), iter.end(), 0);
            while (flow < flow_limit) {
                int f = dfs(dfs, t, flow_limit - flow);
                if (!f) break;
                flow += f;
            }
        }
        return flow;
    }
  private:
    int _n;
    struct _edge {
        int to, rev;
        int cap;
    };
    vector<pair<int, int>> pos;
    vector<vector<_edge>> g;
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> wins(n);
	set<pair<int, int>> eds;
	rep(i, n) rep(j, i) eds.emplace(j, i);
	rep(i, m) {
		int wi, li;
		cin >> wi >> li;
		--wi; --li;
		wins[wi]++;
		if (wi > li) swap(wi, li);
		eds.erase({wi, li});
	}
	int elen = eds.size();
	vector<int> aset;
	rep(i, n) {
		int sid = elen + n, tid = sid + 1;
		mf_graph g(tid+1);
		int eid = 0, wcnt = 0;
		for (auto [ai, bi] : eds) {
			if (ai==i || bi==i) {
				g.add_edge(sid, eid, 1);
				g.add_edge(eid, elen+i, 1);
				++wcnt;
			}
			else {
				g.add_edge(sid, eid, 1);
				g.add_edge(eid, elen+ai, 1);
				g.add_edge(eid, elen+bi, 1);
			}
			++eid;
		}
		bool ok = true;
		rep(j, n) {
			if (j == i) g.add_edge(elen+j, tid, wcnt);
			else {
				int tval = wins[i] + wcnt - 1 - wins[j];
				if (tval < 0) {
					ok = false;
					break;
				}
				g.add_edge(elen+j, tid, tval);
			}
		}
		if (!ok) continue;
		if (g.flow(sid, tid) == elen) aset.push_back(i+1);
	}
	int alen = aset.size();
	if (alen == 0) cout << endl;
	else rep(i, alen) printf("%d%c", aset[i], (i<alen-1?' ':'\n'));
	return 0;
}
