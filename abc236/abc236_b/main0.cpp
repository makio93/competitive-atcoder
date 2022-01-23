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
	vector<int> acnt(n+1);
	rep(i, 4*n-1) {
		int ai;
		cin >> ai;
		acnt[ai]++;
	}
	int res = 0;
	rep3(i, 1, n+1) if (acnt[i] == 3) res = i;
	cout << res << endl;
	return 0;
}
