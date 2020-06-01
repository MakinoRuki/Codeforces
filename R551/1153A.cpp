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
//#include <priority_queue>
#define N 102
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, t;
int s[N], d[N];
int main() {
  cin>>n>>t;
  int wt = 1000000000;
  int id = -1;
  for (int i =1; i <= n; ++i) {
    scanf("%d%d", &s[i], &d[i]);
    if (t < s[i]) {
      if (s[i] - t < wt) {
        wt = s[i]-t;
        id = i;
      }
    } else {
      int rm = d[i] - (t-s[i])%d[i];
      if (rm == d[i]) rm = 0;
      if (rm < wt) {
        wt = rm;
        id = i;
      }
    }
  }
  cout<<id<<endl;
  return 0;
}
