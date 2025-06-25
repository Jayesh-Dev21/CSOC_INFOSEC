# Challenge - 2 {Crypto} [Sub Chall 2] RSA

```
RSA (Rivest–Shamir–Adleman) algorithm
```

Resources:
1. [blog on RSA and Euler's Totient for a product of relatively co-prime numbers, using the Chinese Remainder Theorem](https://leimao.github.io/article/RSA-Algorithm/)

<hr>

1. [Starter](#starter)
2. [Public Exponent](#public-exponent)

---
## Starter

**Starter/Modular Exponentiation**

using c
```c
#include <stdio.h>

long long func(long long, long long, long long);

int main()
{
  long long a = 101, d, p =22663;
  // d = (a^17) mod p
  d = func(a,17, p);
  
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

in python
```python
print(pow(101,17,22663))
```
`output - 19906`

---

**Starter/Public Keys**

using python
```python
e=65537 
p = 17
q = 23

N = p*q

def encrypt(d,e,N):
  return pow(d,e,N)
  
print(encrypt(12,e,N))
```

and using c
```c
#include <stdio.h>
const long long e=65537, p = 17, q = 23;
long long N = p*q;
long long func(long long, long long, long long);

int main()
{
  long long a = 12, d, p = N;
  // d = (a^e) mod N
  d = func(a,e, N);
  
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

`output - 301`

---

**Starter/Euler's Totient**

python code
```python
e=65537 
p = 857504083339712752489993810777
q = 1029224947942998075080348647219

N = p*q

def encrypt(d,e,N):
  return pow(d,e,N)
  
def eulers_totient(p,q):
  n_totient = (p-1)*(q-1)
  return n_totient


print(eulers_totient(p,q))
```

`output - 882564595536224140639625987657529300394956519977044270821168`

---

**Starter/Private Keys**

python code
```
e=65537 
p = 857504083339712752489993810777
q = 1029224947942998075080348647219
N = p*q

def encrypt(d,e_,N_):
  return pow(d,e_,N_)
  
def decrypt(d,e,N):
  return pow(d,e,N)
  
def eulers_totient(p_,q_):
  n_totient = (p_-1)*(q_-1)
  return n_totient

print(decrypt(e, -1, eulers_totient(p,q)))
```

`output - 121832886702415731577073962957377780195510499965398469843281`


---

**Starter/RSA Decryption**


---

**Starter/RSA Signatures**


---
## Public Exponent
---

**Public Exponent/Salty**


---


