
#include <iostream>
#include <sstream>
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
#define N 2000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
const int base=337;

int n, m, q;
int k, w;
int t;
int a[N];
int getbt(int x) {
  int bt=0;
  while((1LL<<bt) <= x) bt++;
  bt--;
  return (1<<bt);
}
int main() {
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);
    int res = n^k;
    vector<int> v;
    v.clear();
    int cnt=0;
    bool ok=true;
    if (res < n) {
    //  cout<<"res="<<res<<endl;
      for (int i = n-1; i >= 0; --i) {
        if (i != res) {
       //   cout<<"i="<<i<<endl;
          a[cnt++] = i;
        }
      }
      a[cnt++] = res;
    } else {
      int bt = getbt(res);
      if (bt < n) {
        int res2 = res ^ bt;
        for (int i = n-1; i >= 0; --i) {
          if ((i != res2) && (i != bt)) {
            a[cnt++] = i;
          }
        }
        a[cnt++] = res2;
        a[cnt++] = bt;
      } else {
        ok = false;
      }
    }
    if (ok) {
      puts("Yes");
      for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
      }
      cout<<endl;
    } else {
      puts("No");
    }
  }
  return 0;
}
