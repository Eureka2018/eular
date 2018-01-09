#include <iostream>
#include <vector>
#include <stdio.h>
#include <cmath>

uint64_t get_factor_number(uint64_t n) {
  //std::vector<int> factor;
  uint64_t count = 1; //from 1
  for (uint64_t k = 2; k <= n / 2 + 1; ++k)
    if (n % k == 0)
      ++count;
  return count;
}


int main(int argc, char* argv[]) {
  uint64_t i = 3;
  uint64_t n = 3;
  uint64_t limit = 5;

  if (argc > 1) limit = std::atoi(argv[1]);

  while(get_factor_number(n) < limit)
    n += i++;

  printf("%lu\n", n);
  return 0;
}
