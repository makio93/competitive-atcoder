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
	int x, y;
	cin >> x >> y;
	int z = -1;
	if (x == y) {
		rep(i, 3) if (x == i) {
			z = i;
			break;
		}
	}
	else {
		rep(i, 3) if (x!=i && y!=i) {
			z = i;
			break;
		}
	}
	cout << z << endl;
	return 0;
}
