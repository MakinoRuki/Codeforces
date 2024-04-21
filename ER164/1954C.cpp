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
#include <random>
#include <ctime>
#include <list>
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string x,y;
    cin>>x>>y;
    int found=-1;
    for (int i = 0; i < x.size(); ++i) {
      if (x[i] == y[i]) {
        continue;
      }
      if (found<0) {
        if (x[i]>y[i]) found=0;
        else found=1;
      } else {
        if (!found && (x[i]>y[i])) {
          swap(x[i], y[i]);
        } else if (found && (x[i]<y[i])) {
          swap(x[i], y[i]);
        }
      }
    }
    cout<<x<<endl;
    cout<<y<<endl;
  }
  return 0;
}
