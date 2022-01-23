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
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q, p;
int l, r;
int t;
int a[N];
struct node {
  vector<int> ids;
  node* nxt[2];
  node() {
    nxt[0] = NULL;
    nxt[1] = NULL;
    ids.clear();
  }
};
node* root;
void insert(int x, int id) {
  node* cur = root;
  for (int i = 30; i >= 0; --i) {
    int d = 0;
    if ((1<<i) & x) {
      d = 1;
    }
    if (!cur->nxt[d]) {
      cur->nxt[d] = new node();
    }
    cur=cur->nxt[d];
    cur->ids.push_back(id);
  }
}
vector<int> query(node* cur, int bt) {
  // for (int i = 30; i >= bt; --i) {
  //   int d = 0;
  //   if ((1<<i) & pre) {
  //     d= 1;
  //   }
  //   if (!cur || !cur->nxt[d]) {
  //     return {};
  //   }
  //   cur = cur->nxt[d];
  // }
  // return cur->ids;
  if ((1<<bt)&k) {
    if (cur->nxt[0]) {
      auto idx = cur->nxt[0]->ids;
      if (!cur->nxt[1]) {
        return {idx[0]};
      } else {
        for (int i = 0; i < idx.size(); ++i) {
          node* cur2 = cur->nxt[1];
          int j;
          for (j = bt-1; j >= 0; --j) {
            int d = 0;
            if ((1<<j) & a[idx[i]]) {
              d = 1;
            }
            if ((1<<j) & k) {
              if (!cur2->nxt[!d]) {
                break;
              }
              cur2 = cur2->nxt[!d];
            } else {
              if (cur2->nxt[!d]) {
                return {idx[i], cur2->nxt[!d]->ids[0]};
              }
              cur2 = cur2->nxt[d];
            }
          }
          if (j < 0) {
            return {idx[i], cur2->ids[0]};
          }
        }
        return {idx[0]};
      }
    } else {
      if (cur->nxt[1]) {
        return {cur->nxt[1]->ids[0]};
      }
      return {};
    }
  } else {
    if (!cur->nxt[0]) {
      if (!cur->nxt[1]) {
        return {};
      }
      return query(cur->nxt[1], bt-1);
    } else {
      auto res1 = query(cur->nxt[0], bt-1);
      if (!cur->nxt[1]) {
        return res1;
      }
      auto res2 = query(cur->nxt[1], bt-1);
      for (int i = 0; i < res2.size(); ++i) {
        res1.push_back(res2[i]);
      }
      return res1;
    }
  }
}
// vector<int> dfs(int k, int cur, int pre) {
//   cout<<"cur="<<cur<<endl;
//   if ((1<<cur) & k) {
//     auto idx = query(cur, pre<<(cur+1));
//     for (int i = 0; i < idx.size(); ++i) {
//       int pre2 = (pre<<1)+1;
//       for (int j = cur-1; j >= 0; --j) {
//         if ((1<<j) & k) continue;
//         int pre3 = pre2;
//         pre3 <<= 1;
//         if ((1<<j)&a[idx[i]]) {
//           if (j) pre3 = pre3 << j;
//           auto res2 = query(j, pre3);
//           if (!res2.empty()) {
//             return {idx[i], res2[0]};
//           }
//         } else {
//           pre3++;
//           if (j) pre3 = pre3<<j;
//           auto res2 = query(j, pre3);
//           if (!res2.empty()) {
//             return {idx[i], res2[0]};
//           }
//         }
//       }
//     }
//     if (!idx.empty()) {
//       return {idx[0]};
//     }
//     auto idx2 = query(cur, ((pre<<1)+1)<<cur);
//     if (!idx2.empty()) {
//       return {idx2[0]};
//     }
//     return {};
//   } else {
//     auto res1 = dfs(k, cur-1, pre<<1);
//     auto res2 = dfs(k, cur-1, (pre<<1)+1);
//     for (int i = 0; i <res2.size(); ++i) {
//       res1.push_back(res2[i]);
//     }
//     return res1;
//   }
// }
int main() {
  cin>>n>>k;
  root = new node();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  if (k == 0) {
    printf("%d\n", n);
    for (int i = 1; i <= n; ++i) {
      printf("%d", i);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    insert(a[i], i);
  }
  vector<int> ans = query(root, 30);
  if (ans.size() <= 1) {
    puts("-1");
    return 0;
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d", ans[i]);
    if (i < ans.size()-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
