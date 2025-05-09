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
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 1000005
#define M 6000000
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int,int> cnt;
    cnt.clear();
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    bool found=false;
    vector<pair<int,int>> v;
    v.clear();
    for (auto itr : cnt) {
        v.push_back(make_pair(itr.first, itr.second));
    }
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].second >= 4) {
            found=true;
            break;
        }
    }
    int i=0;
    while(i < v.size()) {
        if (v[i].second >= 2) {
            int j = i+1;
            while(j < v.size()) {
                if (v[j].first == v[j-1].first+1) {
                    if (v[j].second >= 2) {
                        found=true;
                        break;
                    }
                    j++;
                } else {
                    break;
                }
            }
            if (found) break;
            i = j;
        } else {
            i++;
        }
    }
    if (found) {
        puts("Yes");
    } else {
        puts("No");
    }
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
