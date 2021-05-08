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

bool dfs(vector<vector<int>>& res, vector<int>& a, vector<set<vector<int>>>& blst, int d=0) {
	int n = a.size();
	if (d == n) return false;
	else {
		auto blst2 = blst;
		rep(i, 200) {
			if (!blst[i].empty()) {
				int ti = (i + a[d]) % 200;
				for (auto v : blst[i]) {
					auto tv = v;
					tv.push_back(d+1);
					blst2[ti].insert(tv);
				}
			}
		}
		blst2[a[d]%200].insert(vector<int>({d+1}));
		swap(blst2, blst);
		bool ok = false;
		rep(i, 200) if (!blst[i].empty()) {
			if ((int)(blst[i].size()) >= 2) {
				res.push_back(vector<int>(*blst[i].begin()));
				res.push_back(vector<int>(*next(blst[i].begin())));
				ok = true;
				break;
			}
		}
		if (ok) return true;
		else return dfs(res, a, blst, d+1);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<int>> res;
	vector<set<vector<int>>> blst(200);
	if (dfs(res, a, blst)) {
		cout << "Yes" << endl;
		rep(i, 2) {
			int len = res[i].size();
			cout << len << ' ';
			rep(j, len) printf("%d%c", res[i][j], (j<len-1?' ':'\n'));
		}
	}
	else cout << "No" << endl;
	/*
	{
		rep(i, 200) if (!blst[i].empty()) {
			for (auto v : blst[i]) {
				int n2 = v.size();
				rep(j, n2) printf("%d%c", v[j], (j<n2-1?' ':'\n'));
			}
			cout << endl;
		}
	}
	*/
	return 0;
}
