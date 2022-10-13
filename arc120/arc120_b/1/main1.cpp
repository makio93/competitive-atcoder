// 学習1回目,解説AC

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

const ll mod = 998244353LL;

const string tar = "RB.";

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	vector<vector<int>> ccnt(h+w-1, vector<int>(3));
	rep(i, h) rep(j, w) ccnt[i+j][tar.find(s[i][j])]++;
	ll res = 1;
	rep(i, h+w-1) {
		if (ccnt[i][2]>0 && ccnt[i][0]==0 && ccnt[i][1]==0) res = res * 2 % mod;
		else if (ccnt[i][0]>0 && ccnt[i][1]>0) res = 0;
	}
	cout << res << endl;
	return 0;
}
