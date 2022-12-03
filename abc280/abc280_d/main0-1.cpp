// 本番WA1

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
	ll k;
	cin >> k;
	map<ll, int> plst;
	for (ll i=2; i*i<=k; ++i) {
		while (k%i == 0) {
			plst[i]++;
			k /= i;
		}
	}
	if (k > 1) plst[k]++;
	vector<map<ll, int>> dplst(51);
	rep3(i1, 2, 51) {
		int ival = i1;
		for (ll i=2; i*i<=ival; ++i) {
			while (ival%i == 0) {
				dplst[i1][i]++;
				ival /= i;
			}
		}
		if (ival > 1) dplst[i1][ival]++;
	}
	map<ll, int> dcnt;
	ll res = 1;
	auto ritr = plst.rbegin();
	while (ritr != plst.rend()) {
		while (ritr->second>0 && dcnt[ritr->first]<=ritr->first) {
			dcnt[ritr->first]++;
			ritr->second--;
			if (dcnt[ritr->first] > 1) {
				for (const auto& pi : dplst[dcnt[ritr->first]]) if (plst.find(pi.first) != plst.end()) {
					plst[pi.first] = max(0, plst[pi.first]-pi.second);
				}
			}
		}
		res = max(res, ritr->first*dcnt[ritr->first]);
		++ritr;
	}
	auto itr = plst.begin();
	while (itr != plst.end()) {
		while (itr->second>0 && dcnt[itr->first]>itr->first) {
			dcnt[itr->first]++;
			itr->second--;
			if (dcnt[itr->first] > 1) {
				for (const auto& pi : dplst[dcnt[itr->first]]) if (plst.find(pi.first) != plst.end()) {
					plst[pi.first] = max(0, plst[pi.first]-pi.second);
				}
			}
		}
		res = max(res, itr->first*dcnt[itr->first]);
		++itr;
	}
	cout << res << endl;
	return 0;
}
