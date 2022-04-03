// 本番3,未完成

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
	int n;
	cin >> n;
	string c;
	cin >> c;
    int rn = sqrt(n);
    unordered_map<string, char> memo;
    int d = 1;
    while (d <= n) {
        int nd = d + rn;
        if (nd <= n) {
            string nc = c.substr(0, rn);
            // if (memo.find()!=memo.end()) 
            rep3r(i, 2, rn+1) {

            }
        }

    }
    return 0;
}
