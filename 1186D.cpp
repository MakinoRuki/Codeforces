#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#define N 300005
using namespace std;
typedef long long ll;
int n;
double a[N];
int main() {
  cin>>n;
  vector<double> b;
  double tot = 0.0;
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &a[i]);
    if (a[i] >= 0) tot += floor(a[i]);
    else tot += ceil(a[i]);
  }
  ll cnt = (ll)abs(tot);
  for (int i = 0; i < n; ++i) {
    if (a[i] == floor(a[i])) {
      b.push_back(a[i]);
    } else {
      b.push_back(a[i] >= 0 ? floor(a[i]) : ceil(a[i]));
      if (cnt) {
        if (tot > 0 && a[i] < 0) {b.back()--; cnt--;}
        else if (tot < 0 && a[i] > 0) {b.back()++; cnt--;}
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (b[i] == -0) {
      printf("0\n");
    } else {
      printf("%d\n", (int)b[i]);
    }
    //cout<<(b[i] == -0 ? 0 : b[i])<<endl;
  }
  return 0;
}
