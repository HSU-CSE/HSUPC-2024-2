N = int(input())
    
n = 1
m = 1
    
while n * m < N:
  if n > m:
    m += 1
  else:
    n += 1
    
print(n + m)
