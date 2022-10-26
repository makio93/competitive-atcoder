// 

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int a[3][3];
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++)
      cin >> a[i][j];
  }
  int n;
  cin >> n;
  int b;
  for (int k=0; k<n; k++) {
    cin >> b;
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++)
        if (a[i][j] == b) a[i][j] = 0;
    }
  }
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      if (a[i][j] != 0) break;
      if (j == 2) {
        cout << "Yes";
        return 0;
      }
    }
  }
  for (int j=0; j<3; j++) {
    for (int i=0; i<3; i++) {
      if (a[i][j] != 0) break;
      if (i == 2) {
        cout << "Yes";
        return 0;
      }
    }
  }
  for (int k=0; k<3; k++) {
    if (a[k][k] != 0) break;
    if (k == 2) {
      cout << "Yes";
      return 0;
    }
  }
  for (int k=0; k<3; k++) {
    if (a[k][2-k] != 0) break;
    if (k == 2) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
