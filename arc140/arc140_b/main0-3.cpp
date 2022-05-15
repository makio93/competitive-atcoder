// 

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
	int odd = 0, even = 0;
	rep(i, n-2) {
		if (s.substr(i,3)==string("ARC") && ((i-1<0||s[i-1]!='A') || (i+3>=n||s[i+3]!='C'))) {
			s[i+1] = '.';
			++odd;
		}
	}
	string t;
	rep(i, n) if (s[i] != '.') t.push_back(s[i]);
	swap(s, t);
	n = s.length();
	t.clear();
	rep(i, n) {
		t.push_back(s[i]);
		while ((int)(t.length())>=3 && t.substr((int)(t.length()-3),3)==string("ARC") && even<odd+1) {
			rep(j, 3) t.pop_back();
			t += string("R");
			++even;
		}
	}
	int res = even + odd;
	if (even == odd+1) {
		res = even + odd;
		swap(s, t);
		n = s.length();
		t.clear();
		rep(i, n) {
			t.push_back(s[i]);
			while ((int)(t.length())>=3 && t.substr((int)(t.length()-3),3)==string("ARC")) {
				rep(j, 3) t.pop_back();
				if (res%2 == 1) t += string("AC");
				else t += string("R");
				++res;
			}
		}
	}
	cout << res << endl;
	return 0;
}
