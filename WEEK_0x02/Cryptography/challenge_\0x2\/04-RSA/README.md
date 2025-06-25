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

the python code and my understanding
```
N = 882564595536224140639625987659416029426239230804614613279163
e = 65537
# N = p*q
c = 77578995801157823671636298847186723593814843845525223303932
# ciphertext ^

'''
c = a^e mod N
or 
c = a^e mod (p*q)

d = e^-1 mod phi(N)

d from prev chall is = 121832886702415731577073962957377780195510499965398469843281

c^d = (a^e)^e^-1 mod phi(N) 

and e*d = 1 mod phi(N) e,d have gcd =1, as d is the modulo inverse of encrypt

so c^d = a mod N

or a = c^d mod N
'''
def encrypt(d,e_,N_):
  return pow(d,e_,N_)
  
def decrypt(d,e,N):
  return pow(d,e,N)
  
def eulers_totient(p_,q_):
  n_totient = (p_-1)*(q_-1)
  return n_totient
  
def phi(P,Q):
  eulers_totient(P,Q)

d_from_prev_chall = 121832886702415731577073962957377780195510499965398469843281
print(decrypt(c,d_from_prev_chall,N))
```

`output - 13371337`

---

**Starter/RSA Signatures**


---
## Public Exponent
---

**Public Exponent/Salty**


---


