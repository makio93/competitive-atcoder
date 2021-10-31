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

// 本番AC

int main() {
	int n;
	string s;
	cin >> n >> s;
	string tar = "ABC";
	string ans;
	do {
		string res(3*n, '*');
		vector<vector<int>> cids(3);
		rep(i, 3*n) rep(j, 3) if (tar[j] == s[i]) cids[j].push_back(i);
		unordered_set<int> fids;
		int gval = 1;
		while ((int)(fids.size())<3*n && gval<=6) {
			vector<int> ord(3);
			rep(i, 3) ord[i] = i;
			do {
				if ((int)(fids.size()) >= 3*n) break;
				int kval = 0, id0 = 0, id2 = cids[ord[2]].size() - 1, cval = 0;
				while (cids[ord[0]][id0] < cids[ord[2]][id2]) {
					++kval;
					int lid1 = lower_bound(all(cids[ord[1]]), cids[ord[0]][id0]+1) - cids[ord[1]].begin();
					int rid1 = upper_bound(all(cids[ord[1]]), cids[ord[2]][id2]-1) - cids[ord[1]].begin();
					cval = max(cval, min(kval, max(0, rid1-lid1)));
					if (rid1-lid1 <= 0) break;
					if (rid1-lid1 <= kval) break;
					++id0; --id2;
				}
				if (cval > 0) {
					rep(i, cval) {
						res[cids[ord[0]][i]] = (char)(gval+'0');
						fids.insert(cids[ord[0]][i]);
					}
					int lid1 = lower_bound(all(cids[ord[1]]), cids[ord[0]][cval-1]+1) - cids[ord[1]].begin();
					rep3(i, lid1, lid1+cval) {
						res[cids[ord[1]][i]] = (char)(gval+'0');
						fids.insert(cids[ord[1]][i]);
					}
					rep3(i, (int)(cids[ord[2]].size())-cval, (int)(cids[ord[2]].size())) {
						res[cids[ord[2]][i]] = (char)(gval+'0');
						fids.insert(cids[ord[2]][i]);
					}
					vector<vector<int>> ncids(3);
					rep(i, 3) {
						for (int id : cids[ord[i]]) if (fids.find(id) == fids.end()) ncids[ord[i]].push_back(id);
					}
					swap(cids, ncids);
					++gval;
				}
			} while (next_permutation(all(ord)));
		}
		if ((int)(fids.size()) >= 3*n) {
			ans = res;
			break;
		}
	} while (next_permutation(all(tar)));
	cout << ans << endl;
	return 0;
}
