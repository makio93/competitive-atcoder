// 自力AC

#include <iostream>
#include <cstdio>
using namespace std;

int pow10(int);

int main()
{
  int n, m;
  int d[3];
  cin >> n >> m;
  for (int i=0; i<3; i++) d[i] = -1;
  int s, c;
  for (int i=0; i<m; i++) {
    cin >> s >> c;
    if (d[(3-n)+s-1] == -1) d[(3-n)+s-1] = c;
    else {
      if (d[(3-n)+s-1] != c) {
        cout << -1;
        return 0;
      }
    } 
  }
  if (d[3-n] == -1) {
    if (n == 1) d[3-n] = 0;
    else d[3-n] = 1;
  }
  int min = 0;
  for (int i=0; i<3; i++) {
    if (d[i] == -1) d[i] = 0;
    min += pow10(2-i) * d[i];
  }
  if (min >= pow10(n-1)) cout << min;
  else if (n == 1 && min == 0) cout << 0;
  else cout << -1;
  return 0;
}

int pow10(int n)
{
  int sum = 1;
  for (int i=0; i<n; i++) sum *= 10;
  return sum;
}
