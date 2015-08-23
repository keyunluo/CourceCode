#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;

const int maxn = 1000 + 10;
int a[maxn], f[maxn];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	f[0] = a[0];
	for (int i = 1; i < n; i++)
		f[i] = max(f[i - 1] + a[i], a[i]);
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, f[i]);
	printf("%d\n",ans);
	return 0;
}