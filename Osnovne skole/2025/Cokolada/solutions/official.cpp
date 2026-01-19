#include <cstdio>

int main() {
  int n, k, d;
  scanf("%d", &n);
  k = n & -n;
  for( d = 0; k < n; k <<= 1 ) ++d;
  printf("%d\n%d", k, d);
  return 0;
}
