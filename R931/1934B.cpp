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
int n, m, k, q;
int t;
int a[N];
int dp[40];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
   // vector<vector<int>> cs={{1,1},{2,2},{3,1},{4,2},{5,3},{6,1},{7,2},{8,3},{9,2},{10,1},{11,2},{12,2},{13,2},{14,3},{15,1},{16,2},{17,3},{18,2},{19,3},{20,2},{21,2},{22,3},{23,3},{24,3},{25,2},{26,3},{27,3},{28,3},{29,4},{30,2}};
    vector<int>cs={1,3,6,15};
    int ans=n;
    for (int i = 0; i <= 2; ++i) {
      int dt = n-i*10;
      if (dt >= 0) {
        int sum=i;
        for (int j = 3; j >= 0; --j) {
          sum += dt/cs[j];
          dt%=cs[j];
        }
        if (dt==0) {
          ans=min(ans, sum);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
