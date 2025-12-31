
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
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 50
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x,y;
    scanf("%d%d", &x, &y);
    int bx=0,by=0;
    while((1<<bx) <= x) {
      bx++;
    }
    bx--;
    while((1<<by) <= y) {
      by++;
    }
    by--;
    if (by > bx) {
      puts("-1");
      continue;
    }
    vector<int> v;
    v.clear();
    for (int i = 0; i <= bx; ++i) {
      int rx = ((1<<i)&x)>0;
      int ry = ((1<<i)&y)>0;
      if (rx != ry) {
        v.push_back(1<<i);
      } 
    }
    printf("%d\n", (int)v.size());
    for (int i = 0; i < v.size(); ++i) {
      printf("%d ", v[i]);
    }
    cout<<endl;
  }
  return 0;
}
