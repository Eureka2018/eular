#include <iostream>
#include <vector>
#include <stdio.h>
#include <cmath>

int get_factor_number(int n) {
  //std::vector<int> factor;
  int count = 0;
  int m = (int)std::sqrt(n);
  for (int k = 1; k <= m; ++k)
    if (n % k == 0)
      count += 2;

  if (m * m == n) --count;

  return count;
}


int main(int argc, char* argv[]) {
  int i = 3;
  int n = 3;
  int limit = 5;

  if (argc > 1) limit = std::atoi(argv[1]);

  while(get_factor_number(n) < limit)
    n += i++;

  printf("%d\n", n);
  return 0;
}
