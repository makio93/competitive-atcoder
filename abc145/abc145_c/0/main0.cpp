// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

double d[8][8];

int main(){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    rep(i, n) rep(j, n) {
        double d1 = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        d[i][j] = d1;
        d[j][i] = d1;
    }
    double sum = 0.0;
    int count = 0;
    vector<int> p(n);
    rep(i, n) p[i] = i;
    do {
        double dist = 0.0;
        rep(i, n-1) dist += d[p[i]][p[i+1]];
        sum += dist;
        ++count;
    } while (next_permutation(all(p)));
    sum /= count;
    printf("%f\n", sum);
    return 0;
}
