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
	string s;
	cin >> s;
	int n = s.length();
	deque<char> tdeq;
	bool rev = false;
	rep(i, n) {
		if (s[i] == 'R') rev = !rev;
		else {
			if (!rev) tdeq.push_back(s[i]);
			else tdeq.push_front(s[i]);
		}
	}
	if (rev) reverse(all(tdeq));
	vector<pair<char, int>> trun;
	int tdlen = (int)(tdeq.size());
	rep(i, tdlen) {
		if (!trun.empty() && tdeq[i]==trun.back().first) {
			trun.back().second++;
			if (trun.back().second%2==0) trun.pop_back();
		}
		else trun.emplace_back(tdeq[i], 1);
	}
	string t;
	int trlen = trun.size();
	rep(i, trlen) if (trun[i].second%2==1) t += trun[i].first;
	cout << t << endl;
	return 0;
}
