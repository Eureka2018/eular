def is_palindrome(olds):
    s = str(olds)
    for i in range(0, len(s)/2):
        if s[i] != s[-i-1]:
            return False
    return True

def is_palindrome_2(num):
  r = 0
  n = num
  while n > 0:
    r = r * 10 + n % 10
    n = n / 10
  return r == num


def find_palindrome_1(r):
    mp = 0     
    for i in r:  
        for j in r:         
            p = i * j       
            if is_palindrome(p):
                if mp < p:      
                    mp = p
                    # print i, j
    return mp 


def find_palindrome_2(a, b):
  mp = 0
  i = b
  while i >= a:
    j = b
    while j >= i:
      p = i * j
      if is_palindrome_2(p):
        # print p, i, j
        if mp < p:
          mp = p
      j -= 1
    i -= 1
  return mp

r = range(100, 1000)
mp = find_palindrome_1(r)
print mp

r = range(316, 1000)
mp = find_palindrome_1(r)
print mp

mp = find_palindrome_2(900, 999)
print mp
