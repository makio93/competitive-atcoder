// 本番

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
	string s;
	cin >> n >> s;
	string st;
	int res = 0;
	rep(i, n) {
		st.push_back(s[i]);
		while ((int)(st.length())>=3 && st.substr((int)(st.length()-3),3)==string("ARC")) {
			rep(j, 3) st.pop_back();
			if (res%2 == 0) st += string("R");
			else st += string("AC");
			++res;
		}
	}
	cout << res << endl;
	return 0;
}
