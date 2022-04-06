// 自力2,TLE

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

class Bucket {
    int n, sqrtN, B;
    vector<int> val;
    vector<unordered_map<int, int>> bucket;
public:
    Bucket(int n_) : Bucket(vector<int>(n_)) {}
    Bucket(vector<int> a) : n(a.size()), val(a) {
        sqrtN = ceil(sqrt(n));
        B = (n + sqrtN-1) / sqrtN;
        bucket.resize(B, unordered_map<int, int>(0));
        for (int i=0; i<B; ++i) {
            for (int j=sqrtN*i; j<sqrtN*(i+1); ++j) {
                if (j >= n) break;
                bucket[i][val[j]]++;
            }
        }
    }
    int find(int l, int r) {
        int L = (l + sqrtN-1) / sqrtN, R = r / sqrtN;
        unordered_map<int, int> scnt;
        if (L < R) {
            for (int i=l; i<sqrtN*L; ++i) scnt[val[i]]++;
            for (int i=L; i<R; ++i) for (auto pi : bucket[i]) scnt[pi.first] += pi.second;
            for (int i=sqrtN*R; i<r; ++i) scnt[val[i]]++;
        }
        else {
            for (int i=l; i<r; ++i) scnt[val[i]]++;
        }
        int res = 0;
        for (auto pi : scnt) res += pi.second / 2;
        return res;
    }
};

int main() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    Bucket bc(a);
    cin >> q;
    rep(i, q) {
        int li, ri;
        cin >> li >> ri;
        --li;
        cout << bc.find(li, ri) << endl;
    }
    return 0;
}
