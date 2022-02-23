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
#define N 200
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int main() {
  int x;
  cin>>n>>k>>x;
  for (int i=  1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  int tot=0;
  for (int i = 1; i <= n-k; ++i) {
    tot += a[i];
  }
  tot += k * x;
  cout<<tot<<endl;
  return 0;
}
