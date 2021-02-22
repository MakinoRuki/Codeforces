#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int x;
int check(int s, int m) {
  if (m==0) return s;
  if (s == 1) {
    if (m==1) return 0;
    if (m==2) return 0;
    if (m==3) return 1;
    if (m==4) return 2;
    if (m==5) return 2;
  } else {
    if (m==1) return 2;
    if (m==2) return 1;
    if (m==3) return 0;
    if (m==4) return 0;
    if (m==5) return 1;
  }
  return s;
}
int main() {
  cin>>n>>x;
  if (check(1, n%6) == x) {
    cout<<1<<endl;
  } else if (check(2, n%6) == x) {
    cout<<2<<endl;
  } else {
    cout<<0<<endl;
  }
  return 0;
}
