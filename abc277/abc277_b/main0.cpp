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
const vector<char> tar1 = { 'H', 'D', 'C', 'S' };
const vector<char> tar2 = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	unordered_set<string> st;
	bool ok = true;
	rep(i, n) {
		if (find(all(tar1),s[i][0])==tar1.end() || find(all(tar2),s[i][1])==tar2.end()) {
			ok = false;
			break;
		}
		if (st.find(s[i]) != st.end()) {
			ok = false;
			break;
		}
		st.insert(s[i]);
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
