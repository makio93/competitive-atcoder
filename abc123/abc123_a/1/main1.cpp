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

const string YES = "Yay!", NO = ":(";

int main() {
	vector<int> a(5);
	rep(i, 5) cin >> a[i];
	int k;
	cin >> k;
	if (abs(a[0]-a[4]) <= k) cout << YES << endl;
	else cout << NO << endl;
	return 0;
}
