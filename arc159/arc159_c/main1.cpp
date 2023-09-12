// 解説AC

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
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int sum = accumulate(all(a), 0), add = n * (n+1) / 2;
	if (sum%n!=0 && (sum+add)%n!=0) {
		cout << "No" << endl;
		return 0;
	}
	vector<vector<int>> res;
	if (sum%n != 0) {
		res.push_back(vector<int>(n, -1));
		auto& tlst = res.back();
		iota(all(tlst), 1);
		rep(i, n) a[i] += i + 1;
		sum += add;
	}
	int ave = sum / n;
	while (a != vector(n, ave)) {
		int li = 0, ri = 0;
		while (a[li] >= ave) ++li;
		while (a[ri] <= ave) ++ri;
		res.push_back(vector<int>(n, -1));
		auto& slst = res.back();
		slst[li] = 2;
		slst[ri] = 1;
		int id = 3;
		rep(i, n) if (slst[i] == -1) {
			slst[i] = id;
			++id;
		}
		res.push_back(vector<int>(n, -1));
		auto& tlst = res.back();
		tlst[li] = n;
		tlst[ri] = n-1;
		id = n-2;
		rep(i, n) if (tlst[i] == -1) {
			tlst[i] = id;
			--id;
		}
		a[li]++; a[ri]--;
	}
	cout << "Yes" << endl;
	int m = res.size();
	cout << m << endl;
	rep(i, m) rep(j, n) cout << res[i][j] << (j<n-1?' ':'\n');
	return 0;
}
