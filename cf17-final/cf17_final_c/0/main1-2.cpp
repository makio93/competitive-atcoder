// バチャ終了後,解説AC2

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
	vector<int> d(n);
	rep(i, n) cin >> d[i];
	vector<vector<int>> dcnt(13);
	rep(i, n) dcnt[d[i]].push_back(i);
	dcnt[0].push_back(n);
	bool zero = ((int)(dcnt[0].size())>1 || (int)(dcnt[12].size())>1);
	if (!zero) rep3(i, 1, 12) if ((int)(dcnt[i].size()) > 2) zero = true;
	if (zero) {
		cout << 0 << endl;
		return 0;
	}
	vector<bool> check(24);
	check[0] = true;
	if (!dcnt[12].empty()) check[12] = true;
	int pid = 1;
	rep3(i, 1, 12) {
		if ((int)(dcnt[i].size()) == 2) check[i] = check[24-i] = true;
		else if ((int)(dcnt[i].size()) == 1) {
			if (pid == 1) check[i] = true;
			else check[24-i] = true;
			pid *= -1;
		}
	}
	vector<int> did;
	rep(i, 24) if (check[i]) did.push_back(i);
	did.push_back(24);
	int res = INF, m = did.size();
	rep(i, m-1) res = min(res, did[i+1]-did[i]);
	cout << res << endl;
	return 0;
}
