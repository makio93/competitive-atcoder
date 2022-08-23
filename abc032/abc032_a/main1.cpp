// 解説AC

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

int gcd(int a, int b) { return (b ? gcd(b, a%b) : a); }
int lcm(int a, int b) { return (a / gcd(a, b) * b); }

int main() {
	int a, b, n;
	cin >> a >> b >> n;
	while (n%a!=0 || n%b!=0) ++n;
	cout << n << endl;
	return 0;
}
