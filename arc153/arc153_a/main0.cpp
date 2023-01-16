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
vector<vector<int>> tids = { { 7 }, { 6, 8 }, { 4, 5 }, { 3 }, { 2 }, { 0, 1 } };

int main() {
	int n;
	cin >> n;
	--n;
	string res(9, '0');
	for (const auto& ti : tids) {
		int add = (ti[0] == 0) ? 1 : 0;
		for (const int& id : ti) res[id] += (n%10) + add;
		n /= 10;
	}
	cout << res << endl;
	return 0;
}
