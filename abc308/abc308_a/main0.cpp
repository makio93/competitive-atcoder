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
	int n = 8;
	vector<int> s(n);
	rep(i, n) cin >> s[i];
	bool ok = true;
	rep(i, n-1) if (s[i+1] < s[i]) ok = false;
	rep(i, n) if (s[i]<100 || s[i]>675) ok = false;
	rep(i, n) if (s[i]%25 != 0) ok = false;
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
