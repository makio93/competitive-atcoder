// 自力WA

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

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	auto b = a;
	sort(all(b));
	vector<vector<bool>> g(4, vector<bool>(4)), roop(4, vector<bool>(4)), droop(4, vector<bool>(4));
	function<bool(int,int)> is_roop = [&](int ui, int vi) {
		if (!g[ui][vi]) return false;
		if (ui==vi || roop[ui][vi]) return true;
		array<bool, 4> visited;
		rep(ii, 4) visited[ii] = false;
		queue<int> que;
		visited[ui] = true;
		que.push(ui);
		while (!que.empty()) {
			int ti = que.front(); que.pop();
			rep(ii, 4) if (g[ti][ii] && !visited[ii]) {
				visited[ii] = true;
				que.push(ii);
			}
		}
		return visited[vi];
	};
	function<bool(int,int)> search_roop = [&](int ui, int vi) {
		if (!g[ui][vi] || ui==vi || !roop[ui][vi]) return false;
		bool ok = false;
		if (droop[ui][vi]) ok = true;
		array<bool, 4> visited;
		array<int, 4> pre;
		rep(ii, 4) visited[ii] = false;
		rep(ii, 4) pre[ii] = -1;
		queue<int> que;
		visited[ui] = true;
		que.push(ui);
		while (!que.empty()) {
			int ti = que.front(); que.pop();
			rep(ii, 4) if (g[ti][ii] && !visited[ii]) {
				visited[ii] = true;
				pre[ii] = ti;
				que.push(ii);
			}
		}
		int ti = vi;
		while (pre[ti] != -1) {
			if (droop[ti][pre[ti]]) ok = true;
			droop[ti][pre[ti]] = droop[pre[ti]][ti] = false;
			ti = pre[ti];
		}
		droop[vi][ui] = droop[ui][vi] = false;
		return ok;
	};
	function<void(int,int)> set_roop = [&](int ui, int vi) {
		if (!roop[ui][vi] || ui==vi) return;
		array<bool, 4> visited;
		array<int, 4> pre;
		rep(ii, 4) visited[ii] = false;
		rep(ii, 4) pre[ii] = -1;
		queue<int> que;
		visited[ui] = true;
		que.push(ui);
		while (!que.empty()) {
			int ti = que.front(); que.pop();
			rep(ii, 4) if (g[ti][ii] && !visited[ii]) {
				visited[ii] = true;
				pre[ii] = ti;
				que.push(ii);
			}
		}
		if (!visited[vi]) return;
		int ti = vi;
		while (pre[ti] != -1) {
			roop[ti][pre[ti]] = roop[pre[ti]][ti] = true;
			ti = pre[ti];
		}
		return;
	};
	int res = 0;
	rep(i, n) if (a[i] != b[i]) {
		if (!is_roop(a[i], b[i])) {
			g[a[i]][b[i]] = g[b[i]][a[i]] = true;
			if (is_roop(a[i], b[i])) {
				++res;
				set_roop(a[i], b[i]);
			}
		}
		else if (search_roop(a[i], b[i])) ++res;
		else droop[a[i]][b[i]] = droop[b[i]][a[i]] = true;
	}
	--res;
	cout << res << endl;
	return 0;
}
