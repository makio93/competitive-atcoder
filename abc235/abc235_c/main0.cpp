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
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	unordered_map<int, vector<int>> acnt;
	rep(i, n) acnt[a[i]].push_back(i+1);
	rep(i, q) {
		int xi, ki;
		cin >> xi >> ki;
		if (acnt.find(xi)==acnt.end() || (acnt.find(xi)!=acnt.end()&&(int)(acnt[xi].size())<ki)) cout << -1 << endl;
		else cout << acnt[xi][ki-1] << endl;
	}
	return 0;
}
