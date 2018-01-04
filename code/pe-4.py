def is_palindrome(olds):
    s = str(olds)
    for i in range(0, len(s)/2):
        if s[i] != s[-i-1]:
            return False
    return True
 

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

r = range(100, 1000)
mp = find_palindrome_1(r)
print mp

r = range(316, 1000)
mp = find_palindrome_1(r)
print mp

