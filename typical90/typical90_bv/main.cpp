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

// 自力AC

vector<unordered_map<string, pair<ll, string>>> memo;
pair<ll, string> calc(string s, int m=0) {
	if (memo[m].find(s) != memo[m].end()) return memo[m][s];
	string orgs = s;
	ll res = 0;
	int len = s.length();
	if (s.back() == 'c') {
		int cpos = -1;
		repr(i, len-1) if (s[i] == 'c') {
			cpos = i;
			break;
		}
		if (cpos != -1) {
			int rlen = cpos + 1;
			auto res1 = calc(s.substr(0, rlen), 1);
			res += res1.first;
			rep(i, rlen) s[i] = res1.second[i];
		}
		if (m == 0) {
			auto res1 = calc(s.substr(0, len-1), 0);
			res += res1.first;
			rep(i, len-1) s[i] = res1.second[i];
		}
		s.back() = 'b';
		rep(i, len-1) s[i] = (char)('a' + ((s[i]-'a') + 1) % 3);
		++res;
		cpos = -1;
		repr(i, len-1) if (s[i] == 'c') {
			cpos = i;
			break;
		}
		if (cpos != -1) {
			int rlen = cpos + 1;
			auto res2 = calc(s.substr(0, rlen), 1);
			res += res2.first;
			rep(i, rlen) s[i] = res2.second[i];
		}
	}
	int cpost = -1;
	repr(i, len-1) if (s[i] == 'c') {
		cpost = i;
		break;
	}
	if (cpost != -1) {
		auto rest = calc(s.substr(0, cpost+1), 1);
		res += rest.first;
		rep(i, cpost+1) s[i] = rest.second[i];
	}
	if (m == 1) return (memo[m][orgs] = { res, s });
	if (s.back() == 'b') {
		int bpos = -1;
		repr(i, len-1) if (s[i] == 'b') {
			bpos = i;
			break;
		}
		if (bpos != -1) {
			int rlen = bpos + 1;
			auto res1 = calc(s.substr(0, rlen), 0);
			res += res1.first;
			rep(i, rlen) s[i] = res1.second[i];
		}
		s.back() = 'a';
		rep(i, len-1) s[i] = (char)('a' + ((s[i]-'a') + 1) % 3);
		++res;
		bpos = -1;
		repr(i, len-1) if (s[i] != 'a') {
			bpos = i;
			break;
		}
		if (bpos != -1) {
			int rlen = bpos + 1;
			auto res2 = calc(s.substr(0, rlen), 0);
			res += res2.first;
			rep(i, rlen) s[i] = res2.second[i];
		}
	}
	int bpost = -1;
	repr(i, len-1) if (s[i] == 'b') {
		bpost = i;
		break;
	}
	if (bpost != -1) {
		auto rest = calc(s.substr(0, bpost+1), 0);
		res += rest.first;
		rep(i, bpost+1) s[i] = rest.second[i];
	}
	return (memo[m][orgs] = { res, s });
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	memo = vector<unordered_map<string, pair<ll, string>>>(2, unordered_map<string, pair<ll, string>>());
	rep(i, 2) rep(j, n+1) memo[i][string(j,'a')] = { 0LL, string(j,'a') };
	auto res = calc(s);
	cout << res.first << endl;
	return 0;
}
