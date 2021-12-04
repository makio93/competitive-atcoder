#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番WA

const int INF = (int)(1e9);

const vector<vector<int>> costs = { 
	{ 0, 1, 2, 3, 2, 3, 4, 3, 4, 5 }, 
	{ 1, 0, 1, 2, 1, 2, 3, 2, 3, 4 }, 
	{ 2, 1, 0, 1, 2, 1, 2, 3, 2, 3 },
	{ 3, 2, 1, 0, 3, 2, 1, 4, 3, 2 }, 
	{ 2, 1, 2, 3, 0, 1, 2, 1, 2, 3 },
	{ 3, 2, 1, 2, 1, 0, 1, 2, 1, 2 },
	{ 4, 3, 2, 1, 2, 1, 0, 3, 2, 1 },
	{ 3, 2, 3, 4, 1, 2, 3, 0, 1, 2 },
	{ 4, 3, 2, 3, 2, 1, 2, 1, 0, 1 },
	{ 5, 4, 3, 2, 3, 2, 1, 2, 1, 0 }
};

int main() {
	int m, r;
	cin >> m >> r;
	vector<ll> rvals;
	ll rval = r;
	int clm = max((int)(1e7), m*100+1);
	rep(i, clm) {
		rvals.push_back(rval);
		rval += m;
	}
	int res = (int)(1e9);
	rep(i, clm) {
		string vstr = to_string(rvals[i]);
		int pos = 0, dist = 0, len = vstr.length();
		rep(j, len) {
			dist += costs[pos][vstr[j]-'0'] + 1;
			pos = vstr[j] - '0';
		}
		res = min(res, dist);
	}
	cout << res << endl;
	return 0;
}
