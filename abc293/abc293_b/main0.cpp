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

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	vector<bool> acnt(n);
	rep(i, n) if (!acnt[i]) acnt[a[i]] = true;
	vector<int> res;
	rep(i, n) if (!acnt[i]) res.push_back(i+1);
	int k = res.size();
	cout << k << endl;
	rep(i, k) cout << res[i] << (i<k-1?' ':'\n');
	return 0;
}
