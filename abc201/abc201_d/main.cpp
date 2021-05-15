#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int NINF = -(1e9);

vector<vector<pair<int,int>>> memo;
pair<int,int> calc(vector<string>& a, pair<int,int> v) {
	int h = a.size(), w = a.front().size(), t = (v.first+v.second) % 2;
	int i = v.first, j = v.second;
	if (memo[i][j] != pair<int,int>({NINF, NINF})) return memo[i][j];
	if (i==h-1 && j==w-1) {
		int val = (a[i][j]=='+') ? 1 : -1;
		if (i==0 && j==0) val = 0;
		pair<int, int> res = {0, 0};
		if (t == 0) res.second = val;
		else res.first = val;
		return (memo[i][j] = res);
	}
	else {
		pair<int, int> dval = {NINF, NINF}, rval = {NINF, NINF};
		if (i+1 < h) dval = calc(a, {i+1,j});
		if (j+1 < w) rval = calc(a, {i,j+1});
		pair<int, int> res = { 0, 0 };
		if (dval == pair<int,int>({NINF, NINF})) res = rval;
		else if (rval == pair<int,int>({NINF, NINF})) res = dval;
		else {
			if (t == 0) {
				if (dval.first-dval.second >= rval.first-rval.second) res = dval;
				else res = rval;
			}
			else {
				if (dval.second-dval.first >= rval.second-rval.first) res = dval;
				else res = rval;
			}
		}
		int val = (a[i][j]=='+') ? 1 : -1;
		if (i==0 && j==0) val = 0;
		if (t == 0) res.second += val;
		else res.first += val;
		return (memo[i][j] = res);
	}
}

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	rep(i, h) cin >> a[i];
	memo = vector<vector<pair<int,int>>>(h, vector<pair<int,int>>(w, pair<int,int>({NINF, NINF})));
	pair<int, int> res = calc(a, {0,0});
	if (res.first > res.second) cout << "Takahashi" << endl;
	else if (res.second > res.first) cout << "Aoki" << endl;
	else cout << "Draw" << endl;
	return 0;
}
