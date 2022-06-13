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

int main() {
	int n;
	cin >> n;
	vector<int> a(2*n);
	rep(i, 2*n) cin >> a[i];
	vector<int> ord(2*n);
	iota(all(ord), 0);
	sort(all(ord), [&](int li, int ri) -> bool { return a[li] < a[ri]; });
	vector<bool> bl(2*n);
	rep(i, n) bl[ord[i]] = true;
	string res(2*n, '.');
	stack<int> st;
	rep(i, 2*n) {
		if (st.empty() || bl[st.top()]==bl[i]) st.push(i);
		else {
			res[st.top()] = '(';
			res[i] = ')';
			st.pop();
		}
	}
	cout << res << endl;
	return 0;
}
