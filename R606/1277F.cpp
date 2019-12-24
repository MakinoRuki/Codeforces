#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 400005
using namespace std;
typedef long long ll;
int n;
int a[N];
int main() {
  cin>>n;
  unordered_map<int, int> cnt;
  unordered_map<int, int> cnt2;
  cnt.clear();
  cnt2.clear();
  for (int i= 0; i < n; ++i) {
    scanf("%d", a+i);
    cnt[a[i]]++;
  }
  for (auto v : cnt) {
    cnt2[v.second]++;
  }
  ll tot=cnt.size();
  ll sum=0;
  ll ans=0;
  int ansh = -1;
  int answ = -1;
  for (int h = 1; h <= n; ++h) {
    sum += tot;
    int w = sum / h;
    if (w >= h) {
      if (w * h > ans) {
        ans = w*h;
        ansh = h;
        answ = w;
      }
    }
    tot -= cnt2[h];
  }
  vector<pair<int, int>> rk;
  rk.clear();
  for (auto v : cnt) {
    rk.push_back(make_pair(v.second, v.first));
  }
  sort(rk.begin(), rk.end());
  reverse(rk.begin(), rk.end());
  int cur=0;
  int num=0;
  vector<vector<int>> mat(ansh, vector<int>(answ, 0));
  for (int j = 0; j < answ; ++j) {
    int j2 = j;
    for (int i = 0; i < ansh; ++i) {
      mat[i][j2] = rk[cur].second;
      num++;
      if (num >= rk[cur].first || num >= ansh) {
        cur++;
        num=0;
      }
      j2 = (j2+1)%answ;
    }
  }
  cout<<ans<<endl;
  cout<<ansh<<" "<<answ<<endl;
  for (int i= 0;i<ansh; ++i) {
    for (int j = 0; j <answ; ++j) {
      printf("%d", mat[i][j]);
      if (j < answ-1) cout<<" ";
    }
    cout<<endl;
  }
  return 0;
}
