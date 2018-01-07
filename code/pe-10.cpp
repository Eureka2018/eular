/*
import numpy as np

def primesfrom2to(n):
    # https://stackoverflow.com/questions/2068372/fastest-way-to-list-all-primes-below-n-in-python/3035188#3035188
    """ Input n>=6, Returns a array of primes, 2 <= p < n """
    sieve = np.ones(n/3 + (n%6==2), dtype=np.bool)
    sieve[0] = False
    for i in xrange(int(n**0.5)/3+1):
        if sieve[i]:
            k=3*i+1|1
            sieve[      ((k*k)/3)      ::2*k] = False
            sieve[(k*k+4*k-2*k*(i&1))/3::2*k] = False
    return np.r_[2,3,((3*np.nonzero(sieve)[0]+1)|1)]

n = 2000000
p = primesfrom2to(n)
print sum(p)
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

static inline void ones(std::vector<char>& v, uint64_t size) {
  v.resize(size, 1);
}

int prime_2_to_n(uint64_t n, std::vector<uint64_t>& prime) {
  std::vector<char> sieve;
  ones(sieve, n / 3 + (n % 6 == 2));
  sieve[0] = 0;

  for (uint64_t i = 0; i < (uint64_t)(std::sqrt(n))/3 + 1; ++i) {
    if (sieve[i]) {
      uint64_t k = (3 * i + 1) | 1;
      for (uint64_t p = k*k/3; p < sieve.size(); p += 2*k)
        sieve[p] = 0;
      for (uint64_t p = (k*k+4*k-2*k*(i&1))/3; p < sieve.size(); p += 2*k)
        sieve[p] = 0;
    }
  }

  prime.clear();
  prime.emplace_back(2);
  prime.emplace_back(3);
  for (uint64_t i = 0; i < sieve.size(); ++i) {
    if (sieve[i])
      prime.emplace_back((3 * i + 1)|1);
  }

  return (0);
}

int main(int argc, char* argv[]) {
  uint64_t n = 1000;
  if (argc > 1)
    n = std::atoi(argv[1]);

  std::vector<uint64_t> prime;

  prime_2_to_n(n, prime);

  std::cout << prime.size() << " primes:\n";
  for (auto& p : prime)
    std::cout << p << ',';
  std::cout << '\n';

  return 0;
}
