#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
int t,n,p,k;
int a[N];
int main() {
  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    cin>>n>>p>>k;
    for (int i = 0; i < n; ++i) {
      scanf("%d",&a[i]);
    }
    sort(a, a+n);
    int sum=0;
    int i=0;
    while(i + k - 1< n) {
      if (sum + a[i+k-1] <= p) {
        sum += a[i+k-1];
        i+=k;
      } else {
        break;
      }
    }
    int ans=i;
    sum=0;
    for (int i = 0; i < k-1; ++i) {
      int cnt=i+1;
      sum += a[i];
      int tmp = sum;
      if (sum > p) break;
      for (int j = i + 1; j < n; j += k) {
        if (j + k-1 < n && tmp + a[j+k-1] <= p) {
          cnt += k;
          tmp += a[j+k-1];
        } else {
          break;
        }
      }
      ans = max(ans, cnt);
    }
    cout<<ans<<endl;
  }
  return 0;
}
