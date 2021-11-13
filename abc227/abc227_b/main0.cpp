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

// 本番AC

int main() {
	int n;
	cin >> n;
	vector<int> s(n);
	rep(i, n) cin >> s[i];
	vector<int> scnt(1001);
	rep(i, n) scnt[s[i]]++;
	int rcnt = 0;
	rep3(a, 1, 200) rep3(b, 1, 200) {
		int val = 4*a*b + 3*a + 3*b;
		if (val <= 1000) {
			rcnt += scnt[val];
			scnt[val] = 0;
		}
	}
	cout << (n-rcnt) << endl;
	return 0;
}
