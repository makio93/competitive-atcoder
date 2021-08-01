#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	string x;
	cin >> x;
	bool ng1 = true, ng2 = true;
	rep3(i, 1, 4) if (x[0] != x[i]) ng1 = false;
	if (ng1) {
		cout << "Weak" << endl;
		return 0;
	}
	rep(i, 3) if (((int)(x[i]-'0')+1)%10 != (int)(x[i+1]-'0')%10) ng2 = false;
	if (!ng2) cout << "Strong" << endl;
	else cout << "Weak" << endl;
	return 0;
}
