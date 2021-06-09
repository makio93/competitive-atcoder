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

// 自力AC

int main() {
	int n;
	cin >> n;
	vector<vector<int>> sum(1001, vector<int>(1001));
	rep(i, n) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		sum[ly][lx]++; sum[ry][lx]--;
		sum[ly][rx]--; sum[ry][rx]++;
	}
	rep(i, 1001) rep3(j, 1, 1001) sum[j][i] += sum[j-1][i];
	rep(i, 1001) rep3(j, 1, 1001) sum[i][j] += sum[i][j-1];
	vector<int> kcnt(n+1);
	rep(i, 1001) rep(j, 1001) kcnt[sum[i][j]]++;
	rep3(i, 1, n+1) cout << kcnt[i] << endl;
	return 0;
}
