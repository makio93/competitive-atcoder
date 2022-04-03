// 終了後,解答不能

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
	int h, w, n;
	cin >> h >> w >> n;
	map<pair<int, int>, int> rca;
	vector<map<int, unordered_set<int>>> ravals(h), cavals(w);
	dsu d(n);
	rep(i, n) {
		int ri, ci, ai;
		cin >> ri >> ci >> ai;
		--ri; --ci;
		rca[{ri, ci}] = ai;
		ravals[ri][ai].insert(ci);
		cavals[ci][ai].insert(ri);
	}
	map<pair<int, int>, int> dist;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> que;
	for (auto pi : rca) {
		dist[pi.first] = 0;
		que.emplace(0, pi.first);
	}
	while (!que.empty()) {
		auto [di, pi] = que.top(); que.pop();
		int ri = pi.first, ci = pi.second, ai = rca[pi], ndi = di - 1;
		auto ritr = ravals[ri].find(ai), citr = cavals[ci].find(ai);
		if (ritr != ravals[ri].end()) {
			auto nitr = next(ritr);
			for (auto nci : nitr->second) {
				if (dist.find({ri,nci})!=dist.end() && dist[{ri,nci}]<=ndi) continue;
				dist[{ri, nci}] = ndi;
				que.emplace(ndi, make_pair(ri, nci));
			}
		}
		if (citr != cavals[ci].end()) {
			auto nitr = next(citr);
			for (auto nri : nitr->second) {
				if (dist.find({ci,nri})!=dist.end() && dist[{ci,nri}]<=ndi) continue;
				dist[{ci, nri}] = ndi;
				que.emplace(ndi, make_pair(ci, nri));
			}
		}
	}
	int mval = 0;
	for (auto pi : dist) 
	return 0;
}
