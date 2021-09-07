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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
ll pw[M];
int getsum(int x) {
  int res = 0;
  while(x) {
    res += x%10;
    x/=10;
  }
  return res;
}
int main() {
  pw[0] = 1;
  for (int i = 1; i <= 10; ++i) {
    pw[i] = pw[i-1] * 10;
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int s;
    scanf("%d%d", &s, &n);
    vector<int> ans;
    ans.clear();
    // while(ans.size() < n) {
    //   if ()
    // }
    while(true) {
      if (getsum(s) >= n) {
        int x = s;
        int cnt=0;
        while(x && n>1) {
          if (x%10 > 0) {
            ans.push_back(pw[cnt]);
            x--;
            n--;
          } else {
            x/=10;
            cnt++;
          }
        }
        ans.push_back(x*pw[cnt]);
        break;
      } else {
        int sum = getsum(s);
        int cnt=0;
        int s2 = s;
        while(s2) {
          if (s2%10) {
            break;
          }
          s2/=10;
          cnt++;
        }
        if (cnt == 0) {
          ans.push_back(1);
          n--;
          s--;
          continue;
        }
        int tot=sum-1;
        int tot2=10;
        cnt--;
        while(cnt > 0) {
          if (tot + tot2 >= n) {
            break;
          }
          tot2 *= 10;
          cnt--;
        }
        ans.push_back(pw[cnt]);
        s -= pw[cnt];
        n--;
        // int x = s%10;
        // for (int i = 0; i <= x; ++i) {
        //   ans.push_back(1);
        //   s--;
        //   n--;
        // }
      }
    }
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d", ans[i]);
      if (i < ans.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
