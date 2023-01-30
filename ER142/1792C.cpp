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
#define N 200005
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    if (n % 2) {
      int mid = (n+1)/2;
      int id;
      for (int i = 1; i <= n; ++i) {
        if (a[i] == mid) {
          id = i;
          break;
        }
      }
      int cnt1=0;
      int cur = mid-1;
      for (int i = id-1; i >= 1; --i) {
        if (a[i] == cur) {
          cnt1++;
          cur--;
        }
      }
      cur = mid+1;
      int cnt2=0;
      for (int i = id+1; i <= n; ++i) {
        if (a[i] == cur) {
          cnt2++;
          cur++;
        }
      }
    //  cout<<"id="<<id<<" "<<cnt<<endl;
      printf("%d\n", max(n/2-cnt1, n/2-cnt2));
    } else {
      int id1, id2;
      int mid = n/2;
      for (int i = 1; i <= n; ++i) {
        if (a[i] == mid) id1=i;
        else if (a[i] == mid+1) id2=i;
      }
      if (id1 < id2) {
        int cnt1=0;
        int cur=mid-1;
        for (int i = id1-1; i >= 1; --i) {
          if (a[i] == cur) {
            cnt1++;
            cur--;
          }
        }
        cur = mid+2;
        int cnt2=0;
        for (int i = id2+1; i <= n; ++i) {
          if (a[i] == cur) {
            cnt2++;
            cur++;
          }
        }
       // cnt = n-cnt;
        printf("%d\n", max((n-1)/2-cnt1, (n-1)/2-cnt2));
      } else {
        printf("%d\n", n/2);
      }
    }
  }
  return 0;
}
