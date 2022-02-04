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
#define M 500005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int cnt[N];
int l[N], r[N];
int main() {
  cin>>n;
  memset(l, -1, sizeof(l));
  memset(cnt, 0, sizeof(cnt));
  for (int i =1; i <= n; ++i) {
    scanf("%d", &a[i]);
 //  a[i] = rand()%n+1;
   // cout<<a[i]<<" ";
    cnt[a[i]]++;
    if (l[a[i]] <0) {
      l[a[i]] = i;
      r[a[i]] = i;
    } else {
      r[a[i]] = i;
    }
  }
//  cout<<endl;
  int tot=0;
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] > 2) {
      tot += cnt[i] - 2;
    }
  }
  vector<int> rk;
  rk.clear();
  for (int i = 1; i <= n; ++i) {
    // if (l[i] > 0) {
    //   rk.push_back(make_pair(l[i],-1));
    //   rk.push_back(make_pair(r[i], 1));
    // }
    if (cnt[i] == 1) {
      rk.push_back(l[i]);
    } else if (cnt[i] >= 2) {
      rk.push_back(l[i]);
      rk.push_back(r[i]);
    }
  }
 // cout<<"tot="<<tot<<endl;
  sort(rk.begin(), rk.end());
  set<int> ss;
  ss.clear();
  vector<pair<int,int>> rk2;
  rk2.clear();
  for (int i = 0; i < rk.size(); ++i) {
    int idx = rk[i];
    if (idx == l[a[idx]]) {
      if (!ss.empty() && (*ss.rbegin()) > r[a[idx]]) {
        tot += (cnt[a[idx]] == 1 ? 1 : 2);
      } else {
        if (cnt[a[idx]] > 1) {
          rk2.push_back(make_pair(l[a[idx]], a[idx]));
        }
      }
      ss.insert(r[a[idx]]);
    } else {
      ss.erase(r[a[idx]]);
    }
  }
//  cout<<"tot="<<tot<<endl;
  sort(rk2.begin(), rk2.end());
  int cur= 0;
  while(cur < rk2.size()) {
    int i = cur+1;
    while(i < rk2.size() && rk2[i].first < r[rk2[cur].second]) {
      i++;
    }
    i--;
    int det = i-cur;
    if (det > 0) {
      tot += (det-1) * 2;
    }
    if (i == cur) {
      cur = i+1;
    } else {
      cur = i;
      tot++;
    }
  }
 //  vector<int> stk;
 //  stk.clear();
 //  for (int i = 0; i < rk2.size(); ++i) {
 //    int idx = rk2[i];
 // //   cout<<i<<" "<<idx<<endl;
 //   // cout<<"i="<<i<<" "<<idx<<" "<<rk[i].second<<endl;
 //    if (idx == l[a[idx]]) {
 //      stk.push_back(idx);
 //    } else {
 //      while(!stk.empty() && stk.back() > l[a[idx]]) {
 //        tot++;
 //    //    cout<<"x="<<stk.back()<<endl;
 //        stk.pop_back();
 //      }
 //      if (!stk.empty() && stk.back() == l[a[idx]]) {
 //        stk.pop_back();
 //      //   if (!stk.empty() && r[a[stk.back()]] > r[a[idx]]) {
 //      // //    cout<<"y="<<stk.back()<<endl;
 //      //     if (cnt[a[idx]] > 1) tot+=2;
 //      //     else tot++;
 //      //   }
 //      }
 //    }
 //  }
//  cout<<"XX"<<endl;
  cout<<tot<<endl;
//  cout<<"??"<<endl;
  return 0;
}
