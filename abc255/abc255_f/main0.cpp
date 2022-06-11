// 本番TLE

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
	vector<int> pi(n), ii(n);
	rep(i, n) {
		cin >> pi[i];
		pi[i]--;
	}
	rep(i, n) {
		cin >> ii[i];
		ii[i]--;
	}
	vector<int> li(n, -1), ri(n, -1);
	int pid = 0, iid = 0;
	auto dfs = [&](auto dfs, int vi=0, int par=-1) -> bool {
		if (pid >= n) return false;
		if (pi[pid] != vi) return false;
		++pid;
		if (ii[iid] == vi) {
			++iid;
			if (iid >= n) return true;
			else {
				if (ii[iid] == par) return true;
				else {
					ri[vi] = pi[pid];
					int tpid = pid, tiid = iid;
					if (dfs(dfs, pi[pid], vi)) return true;
					else {
						pid = tpid; iid = tiid;
						ri[vi] = -1;
						return true;
					}
				}
			}
		}
		else {
			li[vi] = pi[pid];
			int tpid = pid, tiid = iid;
			if (!dfs(dfs,pi[pid],vi) || ii[iid]!=vi) {
				pid = tpid; iid = tiid;
				li[vi] = -1;
				return false;
			}
			++iid;
			if (iid >= n) return true;
			else {
				if (ii[iid] == par) return true;
				else {
					ri[vi] = pi[pid];
					int tpid = pid, tiid = iid;
					if (dfs(dfs, pi[pid], vi)) return true;
					else {
						pid = tpid; iid = tiid;
						ri[vi] = -1;
						return true;
					}
				}
			}
		}
	};
	if (!dfs(dfs)) cout << -1 << endl;
	else {
		rep(i, n) {
			cout << (li[i]+1) << ' ' << (ri[i]+1) << endl;
		}
	}
	return 0;
}
