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
	int x;
	cin >> x;
	if (x < 40) cout << (40-x) << endl;
	else if (x < 70) cout << (70-x) << endl;
	else if (x < 90) cout << (90-x) << endl;
	else cout << "expert" << endl;
	return 0;
}
