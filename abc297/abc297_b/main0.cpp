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

int main() {
	string s;
	cin >> s;
	int n = s.length(), li = 0, ri = n-1;
	while (s[li] != 'B') ++li;
	while (s[ri] != 'B') --ri;
	if (li%2 == ri%2) {
		cout << "No" << endl;
		return 0;
	}
	int id = s.find('R') + 1;
	while (s[id] != 'R') {
		if (s[id] == 'K') {
			cout << "Yes" << endl;
			return 0;
		}
		++id;
	}
	cout << "No" << endl;
	return 0;
}
