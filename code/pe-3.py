import numpy
import math

'''
https://projecteuler.net/thread=3
https://www.alpertron.com.ar/ECM.HTM
https://www.alpertron.com.ar/ECMREC.HTM
https://github.com/alpertron/calculators
https://www.alpertron.com.ar/
'''

s = set()
primes = numpy.array([])

def primesfrom2to(n):
    """ Input n>=6, Returns a array of primes, 2 <= p < n """
    sieve = numpy.ones(n/3 + (n%6==2), dtype=numpy.bool)
    for i in xrange(1,int(n**0.5)/3+1):
        if sieve[i]:
            k=3*i+1|1
            sieve[       k*k/3     ::2*k] = False
            sieve[k*(k-2*(i&1)+4)/3::2*k] = False
    return numpy.r_[2,3,((3*numpy.nonzero(sieve)[0][1:]+1)|1)]

def get_factor(m):
    if m == 1:
        return 1

    for p in primes:
        if m % p == 0:
           # print m, p
           s.add(p)
           get_factor(m / p)

    return m

def find_factor(n):
    global primes, s
    s = set()
    primes = primesfrom2to(int(math.sqrt(n)))
    get_factor(n)
    print s

