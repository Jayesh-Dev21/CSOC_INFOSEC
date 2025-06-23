a=66528
b=52920

def gcd_(a, b):
  if(a<b):
    a = a^b
    b = a^b
    a = a^b
  elif(a==b):
    return 1
  sol = 1 
  for t in range(b):
    i = t+1
    if(a%i==0 and b%i ==0):
      sol = i
    
  return sol
  
print(gcd_(a, b))