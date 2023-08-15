#include <stdio.h>
#include <string.h>

#define LIMIT 170
#define ll long long

ll method_1(ll);
ll method_2(ll);
ll method_3(ll);


ll memoForMethod2[LIMIT + 1];
int main() {
  memset(memoForMethod2, 0, sizeof(memoForMethod2));
  ll n;
  printf("n = ");
  scanf("%lld", &n);

  while(n > LIMIT) {
    printf("If n is greater than 170 the result will be very huge,\nplease insert number less than 170\n");
    printf("n = ");
    scanf("%lld", &n);
  }

  printf("The result when using top-down dynamic programming (Momization) is:\n");
  printf("%lld", method_2(n));
  printf("\n-----------------\n");

  printf("The result when using bottom-up dynamic programming (Iterative) is:\n");
  printf("%lld", method_3(n));
  printf("\n-----------------\n");

  printf("The result when using normal recursion is:\n");
  printf("%lld", method_1(n));
  printf("\n-----------------\n");

  return 0;
}

// Normal recursion method
// Space complexity O(n)
// Time complexity O(2^n)
ll method_1(ll n) {
  if(n <= 2) return n;
  return method_1(n - 2) + method_1(n - 3);
}

// Dynamic programming (top-down) -> Momization
// Space complexity -> O(n + m) where m is the size of memo
// Time complexity -> O(n)
ll method_2(ll n) {
  if(n <= 2) return n;
  if(memoForMethod2[n]) return memoForMethod2[n];
  return memoForMethod2[n] = method_2(n - 2) + method_2(n - 3);
}

// Dynamic programming (bottom-up) -> iterative
ll method_3(ll n) {
  if(n <= 2) return n;
  ll arr[3];
  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 2;
  for(ll i = 3; i <= n; i++) {
    ll newValue = arr[0] + arr[1];
    arr[0] = arr[1];
    arr[1] = arr[2];
    arr[2] = newValue;
  }
  return arr[2];
}
