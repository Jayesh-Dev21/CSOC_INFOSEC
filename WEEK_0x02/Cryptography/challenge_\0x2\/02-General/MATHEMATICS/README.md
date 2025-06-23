# Challenge - 2 {Crypto} [Sub Chall 2] General/MATHEMATICS

**Greatest Common Divisor**

I wrote a simple script

```python
a = 12
b = 8

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
```

works right so now on using it with `a=66528,b=52920`

```python
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
  
print(gcd_(a,b))
```

I got `1512`

or use good old `c`

```c
#include <stdio.h>

const int a = 66528;
const int b = 52920;
// ** By Jayesh ** //
int gcd(int a, int b){
    // ?? The function to find gcd of two numbers ?? //
    while (b != 0)
    {
        int var = b;
        b = a % b;
        a = var;
    }

    return a;
}

int main(){
	int result = gcd(a,b);
	printf("%d\n", result);
	return 0;
}
```

---

**Extended GCD**

First I wrote extended GCD code for the previous chall, I had implemented the same thing in my c program which was form my cso-101 lab
```python
a=66528
b=52920

def extended_gcd_(a, b):
  if(a<b):
    a = a^b
    b = a^b
    a = a^b
  
  if(b==0):
    return a
  
  d = 0
  
  d = a%b
    
  return extended_gcd_(b,d)
  
print(extended_gcd_(a,b))
```

Now, moving further

The script for extended gcd using `Extended Euclidean Algorithm`

```python
# Input integers
a=26513
b=32321

def euclidean_extended_gcd(a, b):
    """
    gcd = ax + by {format}
    """
    if b == 0:
        return (a, 1, 0)
    else:
        d = a%b
        gcd, x1, y1 = euclidean_extended_gcd(b, d)
        x = y1
        y = x1 - (a // b) * y1
        return (gcd, x, y)


def extended_gcd_(a, b):
  if(a<b):
    a = a^b
    b = a^b
    a = a^b
  
  if(b==0):
    return a
  
  d = 0
  
  d = a%b
  return extended_gcd_(b,d)
  
result_gcd, result_v, result_u = euclidean_extended_gcd(a,b)
print(f"the solution in {result_gcd} = {a}*({result_v}) + {b}*({result_u})")

# output - {the solution in 1 = 26513*(10245) + 32321*(-8404)}
```


```
sol - (-8404)
```

---

**Modular Arithmetic - 1**

```python
# a  ≅ b mod m

a1 = 11
m1 = 6

a2 = 8146798528947
m2 = 17
  
def func():
  b1 = a1%m1

  b2 = a2%m2
  
  if(b2<b1):
    return b2
  else: 
    return b1
    
print(func())

# output - {4}
```

---

**Modular Arithmetic - 2**

According to `Fermat's little theorem`,
for a prime number `p` and an integer `a` not divisible by `p` then if we raise `a` to the power of `(p-1)`  and divide by `p` will always leave a remainder `1`. It can be expressed in modulo-arithmetic as `a^(p-1) ≡ 1 mod p`

thus `output - 1`

---

**Modulo Inverting**

So to calculate `a^-1` or modulo inverse of `a` or `a.a^-1 ≡ 1 mod p` let `a^-1` be `d`

and to calculate `d` we can find `a^p-2 mod p` using `Fermant's Little Theorm`

1. Bruteforce
```python
# a.d  ≅ b mod m

a =3
b=1
m=13

for d in range(1,m):
  if((a*d)%m == b):
    print(d)
```
but for large computation, we use `FLT`

```python
# a.d  ≅ b mod m

a =3
b=1
m=13

d = pow(a, m-2, m) # it ressambles a^m-2 mod m

print(d)
```

I wrote the smae code in c as well

```c
#include <stdio.h>

long long func(long long, long long, long long);

int main()
{
  long long a = 3, d, p =13;
  // d = a^-1 = (a^p-2) mod p
  d = func(a,p-2, p);
  
  printf("%lld", d);
}

long long func(long long a , long long m, long long p){
  long long t = a%p;
  if(m==0){
    return 1;
  }
  // (a.b.c)%d
  // ((a%d).(((a%d).(a%d))%d))%d
  return ((t)*(func(a,m-1,p)))%p;
}
```

---