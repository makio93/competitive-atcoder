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

// Grundy数を前もって全探索しても間に合う

vector<map<int, int>> memo;
int grundy(int wi, int bi) {
	if (memo[wi].find(bi) != memo[wi].end()) return memo[wi][bi];
	if (wi==0 && bi==0) return (memo[wi][bi] = 0);
	set<int> mex;
	if (wi >= 1) mex.insert(grundy(wi-1, bi+wi));
	if (bi >= 2) rep3(k, 1, bi/2+1) mex.insert(grundy(wi, bi-k));
	int res = 0;
	for (int m : mex) {
		if (m == res) ++res;
		else break;
	}
	return (memo[wi][bi] = res);
}

int main() {
	int n;
	cin >> n;
	vector<int> w(n), b(n);
	rep(i, n) cin >> w[i];
	rep(i, n) cin >> b[i];
	memo = vector<map<int, int>>(51);
	rep(i, 51) rep(j, 51) grundy(i, j);
	int xval = 0;
	rep(i, n) xval ^= memo[w[i]][b[i]];
	if (xval != 0) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}
