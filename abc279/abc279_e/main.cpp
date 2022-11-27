// 

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
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(n);
	rep(i, m) {
		cin >> a[i];
		a[i]--;
	}
	iota(all(b), 0);
	rep(i, m) swap(b[a[i]], b[a[i]+1]);
	vector<int> rb(n);
	rep(i, n) rb[b[i]] = i;
	vector<int> tb(n);
	iota(all(tb), 0);
	rep(i, m) {
		if (tb[a[i]]!=0 && tb[a[i]+1]!=0) cout << (rb[0]+1) << endl;
		else if (tb[a[i]] == 0) cout << (rb[tb[a[i]+1]]+1) << endl;
		else cout << (rb[tb[a[i]]]+1) << endl;
		swap(tb[a[i]], tb[a[i]+1]);
	}
	return 0;
}
