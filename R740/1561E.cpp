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
#define N 3000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int t;
int a[N];
void getrev(int x) {
  int l = 1, r = x;
  while(l < r) {
    swap(a[l], a[r]);
    l++;
    r--;
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int i;
    for (i = 1; i <= n; ++i) {
      if ((i%2) != (a[i]%2)) {
        break;
      }
    }
    if (i <= n) {
      puts("-1");
    } else {
      vector<int> ans;
      ans.clear();
      for (int i = n; i > 1; i -= 2) {
        int id1=0;
        int id2=0;
        for (int j = 1; j <= n; ++j) {
          if (a[j] == i) {
            id1=j;
            break;
          }
        }
        ans.push_back(id1);
        getrev(id1);
        for (int j = 1; j < n; ++j) {
          if (a[j+1] == i-1) {
            id2=j;
            break;
          }
        }
        ans.push_back(id2);
        getrev(id2);
        ans.push_back(i);
        getrev(i);
        for (int j = 1; j <= n; ++j) {
          if (a[j] == i) {
            id1=j;
            break;
          }
        }
        ans.push_back(id1);
        getrev(id1);
        ans.push_back(i);
        getrev(i);
      }
      printf("%d\n", (int)ans.size());
      for (int i = 0; i < ans.size(); ++i) {
        printf("%d", ans[i]);
        if (i < ans.size()-1) cout<<" ";
        else cout<<endl;
      }
    }
  }
 return 0;
}
