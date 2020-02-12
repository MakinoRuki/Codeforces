#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 2002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int mat[N][N];
int lo[N], lz[N];
int ro[N], rz[N];
int lm[N], rm[N];
int main() {
	string s;
	cin>>s;
	int n = s.size();
	int i = n-1;
	int z = 0;
	int o = 0;
	while (i >= 0) {
		if (s[i] == '0') {
			while(i >= 0 && s[i] == '0') {
				z++;
				i--;
			}
		} else {
			int j;
			for (j = i; j >= 0; --j) {
				if (s[j] == '0') break;
			}
			if (o + i-j > z) {
				int det = o+i-j-z;
				for (int k = 1; k <= det; ++k) {
					s[j+k] = '0';
				}
				o += i-j-det;
				// 这部分0不计数。确切地说，这部分多余的1被改成0，则前面多余的1也必须改成0。
				// 否则原先由所有1组成的序列就会变短。
				// 比如11+11+00+11+111+000 
				// z += det;
			} else {
				o += i-j;
			}
			i = j;
		}
	}
	cout<<s<<endl;
	return 0;
}
