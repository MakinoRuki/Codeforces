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
#define N 100005
#define M 602
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int a[N];
int b[M];
vector<pair<int,int>> sg;
int minv[M], maxv[M]; 
int cnt;
int main() {
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  sg.clear();
  cnt=0;
  for (int i =1; i <= m; ++i) {
    int l,r;
    scanf("%d%d", &l, &r);
    sg.push_back(make_pair(l, r+1));
    b[++cnt] = l;
    b[++cnt] = r+1;
  }
  b[++cnt] = 1;
  b[++cnt] = n+1;
  sort(b+1, b+cnt+1);
  cnt = unique(b+1, b+cnt+1)-(b+1);
  for (int i = 1; i <= m; ++i) {
    int l = sg[i-1].first;
    int r = sg[i-1].second;
    l = lower_bound(b+1, b+cnt+1, l)-b;
    r = lower_bound(b+1, b+cnt+1, r)-b;
    sg[i-1] = make_pair(l, r);
  }
  int maxv2, minv2;
  for (int i = 1; i < cnt; ++i) {
    minv[i] = a[b[i]];
    maxv[i] = a[b[i]];
    for (int j = b[i]+1; j < b[i+1]; ++j) {
      minv[i] = min(minv[i], a[j]);
      maxv[i] = max(maxv[i], a[j]);
    }
    if (i==1) {
      maxv2 = maxv[i];
      minv2 = minv[i];
    } else {
      maxv2 = max(maxv2, maxv[i]);
      minv2 = min(minv2, minv[i]);
    }
  }
  int ans=maxv2-minv2;
  vector<int> v1;
  v1.clear();
  for (int i = 1; i < cnt; ++i) {
    vector<int> v2;
    v2.clear();
    int c[N];
    for (int j = 1; j <= cnt; ++j) {
      c[j] = 0;
    }
    for (int j = 0; j < m; ++j) {
      if (sg[j].first <= i && sg[j].second > i) {
        continue;
      }
      // if (i == 3) {
      //   cout<<"j="<<j<<" "<<sg[j].first<<" "<<sg[j].second<<endl;
      // }
      v2.push_back(j+1);
      c[sg[j].first]++;
      c[sg[j].second]--;
    }
    int maxv1 = maxv[i];
    int det=0;
    //if (i==3) cout<<"i="<<i<<" "<<maxv[i]<<endl;
    for (int j = 1; j < cnt; ++j) {
      det += c[j];
      int minv1 = minv[j] - det;
      if (minv1 <= maxv1) {
        if (maxv1 - minv1 > ans) {
          ans = maxv1-minv1;
          v1 = v2;
        }
      }
    }
  }
  cout<<ans<<endl;
  cout<<v1.size()<<endl;
  for (int i = 0; i < v1.size(); ++i) {
    printf("%d", v1[i]);
    if (i < v1.size()-1) cout<<" ";
  }
  cout<<endl;
  return 0;
}
