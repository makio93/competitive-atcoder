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

// 本番AC

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> acnt(2000);
	rep(i, n) acnt[a[i]-1]++;
	pair<int, int> mval = { (int)(1e9), (int)(1e9) };
	rep(i, 2000) if (acnt[i] > 0) mval = min(mval, { acnt[i], i+1 });
	cout << mval.second << endl;
	return 0;
}
