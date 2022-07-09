// 本番AC

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
	vector<int> mi(n);
	vector<vector<int>> pi(n), ei(n);
	random_device seed_gen;
	mt19937_64 engine(seed_gen());
	unordered_map<int, unordered_map<int, uint64_t>> rvals;
	unordered_map<int, map<int, int>> pcnt;
	rep(i, n) {
		cin >> mi[i];
		pi[i] = vector<int>(mi[i]);
		ei[i] = vector<int>(mi[i]);
		rep(j, mi[i]) {
			cin >> pi[i][j] >> ei[i][j];
			rvals[pi[i][j]][ei[i][j]] = engine();
			pcnt[pi[i][j]][ei[i][j]]++;
		}
	}
	uint64_t xval = 0;
	for (auto pi : pcnt) xval ^= rvals[pi.first][pi.second.rbegin()->first];
	set<uint64_t> xst;
	rep(i, n) {
		uint64_t tval = xval;
		rep(j, mi[i]) {
			auto itr = pcnt[pi[i][j]].find(ei[i][j]);
			if (itr->first==pcnt[pi[i][j]].rbegin()->first && pcnt[pi[i][j]].rbegin()->second==1) {
				tval ^= rvals[pi[i][j]][ei[i][j]];
				if (itr != pcnt[pi[i][j]].begin()) {
					--itr;
					tval ^= rvals[pi[i][j]][itr->first];
				}
			}
		}
		xst.insert(tval);
	}
	cout << (int)(xst.size()) << endl;
	return 0;
}
