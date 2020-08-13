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
#define N 5005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//const ll mod2 = 999999937LL;
int n, a, b;
string s;
int dp[N];
int pos[N][N];
// struct node {
// 	int id;
// 	node* next[26];
// 	node() {
// 		id = 5002;
// 		for (int i = 0; i < 26; ++i) {
// 			next[i] = NULL;
// 		}
// 	}
// };
// void insert(node* root, int id) {
// 	for (int i = id; i < n; ++i) {
// 		if (root->next[s[i]-'a'] == NULL) {
// 			root->next[s[i]-'a'] = new node();
// 		}
// 		root = root->next[s[i]-'a'];
// 		root->id = min(root->id, id+1);
// 	}
// }
int main() {
	cin>>n>>a>>b;
	cin>>s;
	for (int i = 0; i <= n+1; ++i) {
		dp[i] = inf;
	}
	dp[0] = 0;
	memset(pos, 0, sizeof(pos));
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i] = min(dp[i], dp[i-1]+a);
			if (j == 0) {
				continue;
			} else {
				if (s[i-1]==s[j-1]) {
					pos[i][j] = pos[i-1][j-1]+1;
				}
				if (pos[i][j] > 0) {
					dp[i] = min(dp[i], dp[i-min(pos[i][j], i-j)]+b);
				}
			}
			// if (i==3) {
			// 	cout<<"j="<<j<<" "<<pos[i][j]<<" "<<dp[i]<<endl;
			// }
		}
	}
	//cout<<dp[3]<<endl;
	cout<<dp[n]<<endl;
	return 0;
}
