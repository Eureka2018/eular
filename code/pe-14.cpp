#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>
#include <array>

void next_step(std::vector<uint64_t>& vec, uint64_t n) {
  if (n != 1) {
    uint64_t m = (n % 2) ? 3 * n + 1 : n / 2;
    vec.emplace_back(m);
    next_step(vec, m);
  }
}

uint64_t next_step_2(uint64_t n, std::map<uint64_t, uint64_t>& i2i) {
  uint64_t m = n, s = 0;
  while(m != 1) {
    m = (m % 2) ? 3 * m + 1 : m / 2;
    if (i2i[m] != 0) {
      s += i2i[m];
      break;
    }
 
    ++s;
  }

  i2i.insert(std::make_pair(n, s));
  return s;
}

uint64_t next_step_3(uint64_t n) {
  uint64_t m = n, s = 0;
  while(m != 1) {
    m = (m % 2) ? 3 * m + 1 : m / 2;
    ++s;
  }
  return s;
}


int main(void) {
  uint64_t maxs = 0, result = 0;
  for (uint64_t i = 500001; i < 1000000; i+=2) {
    uint64_t s = next_step_3(i);
    if (maxs < s)
       maxs = s, result = i;
  }

  printf("%lu => %lu\n", result, maxs);
  return 0;
}


int main_2(void) {
  std::map<uint64_t, uint64_t> i2i;
  uint64_t maxs = 0, result = 0;
  for (uint64_t i = 2; i < 1000000; ++i) {
    uint64_t s = next_step_2(i, i2i);
    if (maxs < s)
       maxs = s, result = i;
  }

  printf("%lu => %lu\n", result, maxs);
  return 0; 
}

int main_1(int argc, char* argv[]) {
  /* 
  n = 13;
  if (argc > 1) n = std::atoll(argv[1]);
  std::vector<uint64_t> vec;
  next_step(vec, n);

  printf("%lu -> ", n);
  for (auto& i : vec)
    printf("%lu -> ", i);

  printf("\n");
  */

  size_t maxs = 0, result = 0;
  std::vector<uint64_t> vec;
  /*
  for (auto iter = p.begin(); iter != p.end(); iter++) {
    vec.clear();
    next_step(vec, (*iter));
    if (maxs < vec.size())
      maxs = vec.size(), result = (*iter);
  }
  */

  for (uint64_t i = 2; i < 1000000; ++i) {
    vec.clear();
    next_step(vec, i);
    if (maxs < vec.size())
      maxs = vec.size(), result = i;
  }

  printf("%lu => %lu\n", result, maxs);
  return 0;
}

