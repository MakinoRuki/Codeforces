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
#define M 202
#define N 2002
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int m, k, q;
int n;
int t;
int c;
int a[N][N];
string s;
int main() {
  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      cin>>s;
      for (int j =1; j <= n; ++j) {
        a[i][j] = s[j-1]- '0';
        //scanf("%d", &a[i][j]);
      }
    }
    map<int, int> mp;
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (a[i][j]) {
          mp[(i-j+n) % n]++;
          cnt++;
        }
      }
    }
    int x = 0;
    for (auto itr : mp) {
     // cout<<itr.first<<" "<<itr.second<<endl;
      x = max(x, itr.second);
    }
    int y = max(0, n-x) + cnt - x;
    printf("%d\n", y);
  }
  return 0;
}
