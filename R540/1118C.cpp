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
#define N 502
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int ans[N/10][N/10];
int cnt[N*2];
int main() {
  cin>>n;
  memset(ans, 0, sizeof(ans));
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n*n; ++i) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
 // cout<<cnt[1]<<" "<<cnt[8]<<endl;
  int c0=0, c1=0,c2=0,c3=0;
  for (int i = 1; i <= 1000; ++i) {
    if (cnt[i] > 0) {
      if (cnt[i] % 4 == 0) c0++;
      else if (cnt[i]% 4 == 1) c1++;
      else if (cnt[i] % 4 == 2) {c2++;}
      else c3++;
    }
  }
  if (n % 2 == 0) {
  //  cout<<c3<<" "<<c1<<" "<<c2<<endl;
    if (c3 > 0 || c1 > 0 || c2 > 0) {
      puts("NO");
    } else {
      int cur = 1;
      for (int i = 1; i <= n/2; ++i) {
        for (int j = 1; j <= n/2; ++j) {
          while(cnt[cur] <= 0) {
            cur++;
          }
          ans[i][j] = cur;
          ans[n-i+1][j] = cur;
          ans[i][n-j+1] = cur;
          ans[n-i+1][n-j+1] = cur;
          cnt[cur] -= 4;
        }
      }
      puts("YES");
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          printf("%d", ans[i][j]);
          if (j < n) cout<<" ";
          else cout<<endl;
        }
      }
    }
  } else {
    if (c1 + c3 > 1) {
      puts("NO");
      return 0;
    }
    int i;
    for (i = 1; i <= 1000; ++i) {
      if ((cnt[i] % 4 == 1) || (cnt[i] % 4 == 3)) {
        break;
      }
    }
    ans[(n+1)/2][(n+1)/2] = i;
    cnt[i]--;
    vector<int> tmp;
    tmp.clear();
    for (int i = 1; i <= 1000; ++i) {
      if (cnt[i] %4 == 2) {
        tmp.push_back(i);
      }
    }
    int cur = 0;
    int x = (n+1)/2;
    for (int i = 1; i <= n/2; ++i) {
      if (cur >= tmp.size()) break;
      ans[i][x] = tmp[cur];
      ans[n-i+1][x] = tmp[cur];
      cnt[tmp[cur]] -= 2;
      cur++;
      ans[x][i] = tmp[cur];
      ans[x][n-i+1] = tmp[cur];
      cnt[tmp[cur]] -= 2;
      cur++;
    }
    if (cur < tmp.size()) {
      puts("NO");
      return 0;
    }
    cur = 1;
    for (int i = 1; i <= n/2; ++i) {
      if (ans[i][(n+1)/2] <= 0) {
        while(cnt[cur] == 0) cur++;
        int x = (n+1)/2;
        ans[i][x] = cur;
        ans[n-i+1][x] = cur;
        ans[x][i] = cur;
        ans[x][n-i+1] = cur;
        cnt[cur] -= 4;
      }
    }
    cur = 1;
    for (int i = 1; i <= n/2; ++i) {
      for (int j = 1; j <= n/2; ++j) {
        while(cnt[cur] <= 0) cur++;
        ans[i][j] = cur;
        ans[n-i+1][j] = cur;
        ans[i][n-j+1] = cur;
        ans[n-i+1][n-j+1] = cur;
        cnt[cur] -= 4;
      }
    }
    puts("YES");
    for (int i = 1; i <= n; ++i) {
      for (int j =1; j <= n; ++j) {
        printf("%d", ans[i][j]);
        if (j < n) cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
