#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <deque>
#define N 200005
using namespace std;
typedef long long ll;
int n;
int a[N];
int ind[N]; int outd[N];
int main() {
  //ios_base::sync_with_stdio(0);
  //cin.tie(nullptr);
  // freopen("data.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  cin>>n;
  memset(ind, 0, sizeof(ind));
  memset(outd, 0, sizeof(outd));
  for (int i = 1; i <= n; ++i) {
    cin>>a[i];
    if (a[i]) {
      ind[a[i]]++;
      outd[i]++;
    }
  }
  vector<int> q1;
  q1.clear();
  vector<int> q2;
  q2.clear();
  for (int i = 1; i <= n; ++i) {
    if (ind[i] == 0) {
      if (a[i] == 0) {
        q1.push_back(i);
      } else {
        q2.push_back(i);
      }
    }
  }
  if (q1.size() == 1) {
    a[q1[0]] = q2.back();
    q2.pop_back();
    q2.push_back(q1[0]);
    q1.clear();
  }
  int cnt=0;
  int cnt2=0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 0) {
      if (cnt<q1.size() && i == q1[cnt]) {
        a[i] = q1[(cnt+1)%q1.size()];
        cnt++;
      } else {
        a[i] = q2[cnt2++];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout<<a[i];
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
