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
#define N 200005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i&1) {
				if (j&1) printf("W");
				else printf("B");
			} else {
				if (j&1) printf("B");
				else printf("W");
			}
		}
		cout<<endl;
	}
	return 0;
}
