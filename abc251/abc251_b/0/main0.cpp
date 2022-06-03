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
	int n, w;
	cin >> n >> w;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	unordered_set<int> st;
	rep(i, n) {
		if (a[i] <= w) st.insert(a[i]);
		rep3(j, i+1, n) {
			if (a[i]+a[j] <= w) st.insert(a[i]+a[j]);
			rep3(k, j+1, n) if (a[i]+a[j]+a[k] <= w) st.insert(a[i]+a[j]+a[k]);
		}
	}
	cout << (int)(st.size()) << endl;
	return 0;
}
