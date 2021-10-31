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

// 本番WA

const vector<string> tar = { "ABC", "BCA", "CAB" };
const vector<string> rtar = { "CBA", "ACB", "BAC" };
const string ctar = "ABC";

int main() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	string sval = s, tval = t;
	sort(all(sval)); sort(all(tval));
	if (sval != tval) {
		cout << "NO" << endl;
		return 0;
	}
	string sst, tst;
	vector<int> scnt(5), tcnt(5);
	rep(i, n) {
		sst.push_back(s[i]);
		if ((int)(sst.length()) >= 3) {
			bool ok1 = false;
			string stmp = sst.substr(sst.length()-3, 3);
			rep(j, 3) if (stmp == tar[j]) {
				ok1 = true;
				break;
			}
			if (ok1) {
				scnt[0]++;
				rep(j, 3) sst.pop_back();
				continue;
			}
			rep(j, 3) if (stmp == rtar[j]) {
				ok1 = true;
				break;
			}
			if (ok1) {
				scnt[1]++;
				rep(j, 3) sst.pop_back();
				continue;
			}
		}
	}
	while (!sst.empty()) {
		if ((int)(sst.length()) >= 3) {
			bool ok1 = false;
			string stmp = sst.substr(sst.length()-3, 3);
			rep(j, 3) if (stmp == tar[j]) {
				ok1 = true;
				break;
			}
			if (ok1) {
				scnt[0]++;
				rep(j, 3) sst.pop_back();
				continue;
			}
			rep(j, 3) if (stmp == rtar[j]) {
				ok1 = true;
				break;
			}
			if (ok1) {
				scnt[1]++;
				rep(j, 3) sst.pop_back();
				continue;
			}
			rep(j, 3) if (sst.back() == ctar[j]) {
				scnt[2+j]++;
				sst.pop_back();
				break;
			}
			continue;
		}
		else {
			rep(j, 3) if (sst.back() == ctar[j]) {
				scnt[2+j]++;
				sst.pop_back();
				break;
			}
		}
	}
	rep(i, n) {
		tst.push_back(t[i]);
		if ((int)(tst.length()) >= 3) {
			bool ok1 = false;
			string ttmp = tst.substr(tst.length()-3, 3);
			rep(j, 3) if (ttmp == tar[j]) {
				ok1 = true;
				break;
			}
			if (ok1) {
				tcnt[0]++;
				rep(j, 3) tst.pop_back();
				continue;
			}
			rep(j, 3) if (ttmp == rtar[j]) {
				ok1 = true;
				break;
			}
			if (ok1) {
				tcnt[1]++;
				rep(j, 3) tst.pop_back();
				continue;
			}
		}
	}
	while (!tst.empty()) {
		if ((int)(tst.length()) >= 3) {
			bool ok1 = false;
			string ttmp = tst.substr(tst.length()-3, 3);
			rep(j, 3) if (ttmp == tar[j]) {
				ok1 = true;
				break;
			}
			if (ok1) {
				tcnt[0]++;
				rep(j, 3) tst.pop_back();
				continue;
			}
			rep(j, 3) if (ttmp == rtar[j]) {
				ok1 = true;
				break;
			}
			if (ok1) {
				tcnt[1]++;
				rep(j, 3) tst.pop_back();
				continue;
			}
			rep(j, 3) if (tst.back() == ctar[j]) {
				tcnt[2+j]++;
				tst.pop_back();
				break;
			}
			continue;
		}
		else {
			rep(j, 3) if (tst.back() == ctar[j]) {
				tcnt[2+j]++;
				tst.pop_back();
				break;
			}
		}
	}
	if (scnt == tcnt) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
