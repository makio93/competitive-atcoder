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

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int cnt = 0;
	stack<pair<int, int>> st;
	rep(i, n) {
		if (!st.empty() && st.top().first==a[i]) st.top().second++;
		else st.emplace(a[i], 1);
		++cnt;
		if (st.top().second >= st.top().first) {
			cnt -= st.top().second;
			st.pop();
		}
		cout << cnt << endl;
	}
	return 0;
}
