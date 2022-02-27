#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int main() {
  int h;
  cin>>n>>h;
  for (int i = 1; i < n; ++i) {
    double res = sqrt((double)h*(double)h*(double)i/(double)n);
    printf("%.10lf", res);
    if (i < n-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
