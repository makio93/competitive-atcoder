// 本番WA2

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
	vector<int> a(n), b(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	rep(i, n) {
		cin >> b[i];
		b[i]--;
	}
	vector<int> acnt(n), bcnt(n);
	rep(i, n) acnt[a[i]]++;
	rep(i, n) bcnt[b[i]]++;
	if (acnt != bcnt) {
		cout << "No" << endl;
		return 0;
	}
	unordered_set<int> dvals;
	rep(i, n) {
		if (acnt[i] >= 2) dvals.insert(i);
		if (bcnt[i] >= 2) dvals.insert(i);
	}
	vector<int> alst, blst;
	rep(i, n) if (a[i]!=b[i] && dvals.find(a[i])==dvals.end() && dvals.find(b[i])==dvals.end()) {
		alst.push_back(a[i]);
		blst.push_back(b[i]);
	}
	int m = alst.size();
	if (m == 0) {
		cout << "Yes" << endl;
		return 0;
	}
	unordered_map<int, int> aids;
	rep(i, m) aids[alst[i]] = i;
	int res = 0;
	unordered_set<int> st;
	rep(i, m) st.insert(i);
	while (!st.empty()) {
		int id = *st.begin(), cnt = 1;
		st.erase(id);
		while (st.find(aids[blst[id]]) != st.end()) {
			id = aids[blst[id]];
			++cnt;
			st.erase(id);
		}
		if (res == 0) res += cnt;
		else res += cnt - 1;
	}
	if (res>=3 && res%2 == 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
