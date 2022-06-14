// バチャ,自力AC

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
	string s;
	cin >> s;
	int n = s.length();
	vector<pair<char, int>> runs;
	runs.emplace_back(s[0], 1);
	rep3(i, 1, n) {
		if (s[i] == runs.back().first) runs.back().second++;
		else runs.emplace_back(s[i], 1);
	}
	int res = 0, m = runs.size();
	stack<pair<char, int>> st;
	rep(i, m) {
		if (st.empty()) st.emplace(runs[i].first, runs[i].second);
		else {
			while (runs[i].second > 0) {
				if (st.empty()) {
					st.emplace(runs[i].first, runs[i].second);
					runs[i].second = 0;
				}
				else if (st.top().first == runs[i].first) {
					st.top().second += runs[i].second;
					runs[i].second = 0;
				}
				else {
					int sub = min(st.top().second, runs[i].second);
					st.top().second -= sub;
					runs[i].second -= sub;
					res += sub * 2;
					if (st.top().second == 0) st.pop();
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}
