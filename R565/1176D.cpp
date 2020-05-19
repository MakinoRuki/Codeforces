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
#define N 500005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int b[N];
int cnt[N/5*30+5];
int ispr[N/5*30+5];
int pr[N/5*30+5];
bool vis[N/5*30+5];
vector<int> prs;
int main() {
  cin>>n;
  memset(cnt, 0, sizeof(cnt));
  memset(ispr, -1, sizeof(ispr));
  memset(pr, -1, sizeof(pr));
  for (int i = 1; i <= 2*n; ++i) {
    scanf("%d", &b[i]);
    cnt[b[i]]++;
    bool found=false;
    for (int j = 2; j*j <= b[i]; ++j) {
      if (b[i]%j == 0) {
        int res = b[i]/j;
        found=true;
        pr[b[i]] = res;
        break;
      }
    }
    if (!found) ispr[b[i]] = 1;
    else ispr[b[i]] = 0;
  }
  vector<int> ans;
  ans.clear();
  for (int i = 2750131; i >= 2; --i) {
    if (cnt[i]) {
      if (ispr[i]==0) {
        int num=cnt[i];
        for (int j = 1; j <= num; ++j) {
          ans.push_back(i);
          cnt[pr[i]]--;
          cnt[i]--;
        }
      }
    }
  }
  prs.clear();
  memset(vis, false, sizeof(vis));
  for (int i = 2; i * i <= 2750131; ++i) {
    if (!vis[i]) {
      for (int j = 2*i; j <= 2750131; j += i) {
        vis[j] = true;
      }
    }
  }
  for (int i = 2; i <= 2750131; ++i) {
    if (!vis[i]) prs.push_back(i);
  }
  //cout<<"cnt1="<<cnt[3]<<endl;
  for (int i = 2; i <= 2750131; ++i) {
    if (cnt[i]) {
      if (ispr[i]==1) {
      //  cout<<i<<" "<<cnt[i]<<endl;
        int num=cnt[i];
        for (int j = 1; j <= num; ++j) {
          ans.push_back(i);
          cnt[i]--;
          cnt[prs[i-1]]--;
         // cout<<"cnt="<<cnt[3]<<endl;
        }
      }
    }
  }
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d", ans[i]);
    if (i < ans.size()-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
