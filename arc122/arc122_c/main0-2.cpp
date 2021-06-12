#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番中、未完成、わからない

int main() {
    ll n;
    cin >> n;
    vector<int> lens;
    while (n > 0) {
        ll sum = 0, p1 = 0, p2 = 0, now = 1;
        int len = 0;
        while (sum+(now+p1) <= n) {
            p2 = p1;
            p1 = now;
            now = p1 + p2;
            sum += now;
            ++len;
        }
        lens.push_back(len);
        n -= sum;
    }
    vector<int> res;
    int li = lens.front();
    int li2 = li;
    if (li2%2==1) {
        res.push_back(1);
        --li2;
        rep(i, li2) {
            if (i%2==0) res.push_back(4);
            else res.push_back(3);
        }
    }
    else {
        res.push_back(2);
        --li2;
        rep(i, li2) {
            if (i%2==0) res.push_back(3);
            else res.push_back(4);
        }
    }
    int llen = lens.size();
    int k = (int)(res.size()) + (llen - 1);
    cout << k << endl;

    res.push_back()
    return 0;
}
