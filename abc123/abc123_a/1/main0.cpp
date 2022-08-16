// 学習1回目,自力AC

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

const vector<string> tar = { "Yay!", ":(" };

int main() {
	vector<int> a(5);
	rep(i, 5) cin >> a[i];
	int k;
	cin >> k;
	bool ok = true;
	rep(i, 5) rep3(j, i+1, 5) if (abs(a[i]-a[j]) > k) ok = false;
	if (ok) cout << tar[0] << endl;
	else cout << tar[1] << endl;
	return 0;
}
