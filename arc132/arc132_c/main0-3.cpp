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

// 本番実装,WA

using mint = modint998244353;

int main() {
	int n, d;
	cin >> n >> d;
	vector<int> a(n), b(n, -1), hids;
	set<int> st;
	rep(i, n) st.insert(i);
	rep(i, n) {
		cin >> a[i];
		if (a[i] != -1) a[i]--;
		if (a[i] != -1) st.erase(a[i]);
		else hids.push_back(i);
	}
	vector<int> hvals;
	for (int hval : st) hvals.push_back(hval);
	rep(i, (int)(hids.size())) b[hids[i]] = hvals[i];
	rep(i, d+1) b.push_back(-1);
	vector<map<vector<int>, mint>> dp(n+d+1);
	vector<int> ord(d+1);
	rep(i, d+1) ord[i] = i;
	rep(i, d+1) dp[n+i][ord] = 1;
	repr(i, n) {
		vector<int> tord = ord;
		do {
			bool ok = true;
			rep(j, d+1) {
				if (b[i+j] == -1) {
					if (tord[j] != j) {
						ok = false;
						break;
					}
				}
				else {
					int tid = i + tord[j];
					if (b[tid] == -1) {
						ok = false;
						break;
					}
					if (b[tid]<i+j-d || b[tid]>i+j+d) ok = false;
					else if (b[i+j]<tid-d || b[i+j]>tid+d) ok = false;
				}
				if (!ok) break;
			}
			if (ok) {
				int aid = 0;
				rep(j, d+1) if (tord[j] == 0) {
					aid = j;
					break;
				}
				++aid;
				vector<int> nord = ord;
				do {
					bool ok2 = true;
					rep(j, (d+1-aid)) if (nord[j] != tord[aid+j]-aid) ok2 = false;
					if (!ok2) continue;
					if (dp[i+aid].find(nord) != dp[i+aid].end()) dp[i][tord] += dp[i+aid][nord];
				} while (next_permutation(all(nord)));
			}
		} while (next_permutation(all(tord)));
	}
	mint res = 0;
	rep(i, d) {
		vector<int> rord = ord;
		do {
			if (dp[i].find(rord) != dp[i].end()) res += dp[i][rord];
		} while (next_permutation(all(rord)));
	}
	cout << res.val() << endl;
	return 0;
}
