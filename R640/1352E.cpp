#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#define N 8002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int a[N];
bool vis[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      vis[i] = false;
    }
    for (int i = 1; i <= n; ++i) {
      int sum=a[i];
      for (int j = i+1; j <= n; ++j) {
        sum += a[j];
        if (sum >= 1 && sum <= n) {
          vis[sum] = true;
        } else if (sum > n) {
          break;
        }
      }
    }
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      if (vis[a[i]]) cnt++;
    }
    cout<<cnt<<endl;
  }
  return 0;
}
