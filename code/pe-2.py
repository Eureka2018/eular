k0 = 1
k = 1
s = 0
while k < 4000000:
  if 0 == k % 2:
    s += k
  tmp = k
  k = k + k0
  k0 = tmp

print (s)


limit=4000000
sum=0
a=1
b=1
c=a+b
while c<limit:
  sum=sum+c
  a=b+c
  b=c+a
  c=a+b

print (sum)


limit=4000000
a = 2
b = 8
s = 2
while b < limit:
  s += b
  c = 4 * b + a
  a = b
  b = c

print (s)


