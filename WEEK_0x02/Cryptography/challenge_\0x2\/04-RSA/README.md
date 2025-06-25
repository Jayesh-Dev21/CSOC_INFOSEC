# Challenge - 2 {Crypto} [Sub Chall 2] RSA

```
RSA (Rivest–Shamir–Adleman) algorithm
```

Resources:
1. [blog on RSA and Euler's Totient for a product of relatively co-prime numbers, using the Chinese Remainder Theorem](https://leimao.github.io/article/RSA-Algorithm/)
2. [Signing your message in RSA, a good read on stack exchange](https://crypto.stackexchange.com/questions/12090/using-the-same-rsa-keypair-to-sign-and-encrypt/12138#12138)

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
```python
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

The Python code and my understanding
```python
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

python code

```python
def encrypt(d,e_,N_):
  return pow(d,e_,N_)
  
def decrypt(d,e,N):
  return pow(d,e,N)
  
def eulers_totient(p_,q_):
  n_totient = (p_-1)*(q_-1)
  return n_totient
  
def phi(P,Q):
  eulers_totient(P,Q)

e = 65537
# from private.key
N = 15216583654836731327639981224133918855895948374072384050848479908982286890731769486609085918857664046075375253168955058743185664390273058074450390236774324903305663479046566232967297765731625328029814055635316002591227570271271445226094919864475407884459980489638001092788574811554149774028950310695112688723853763743238753349782508121985338746755237819373178699343135091783992299561827389745132880022259873387524273298850340648779897909381979714026837172003953221052431217940632552930880000919436507245150726543040714721553361063311954285289857582079880295199632757829525723874753306371990452491305564061051059885803
d = 11175901210643014262548222473449533091378848269490518850474399681690547281665059317155831692300453197335735728459259392366823302405685389586883670043744683993709123180805154631088513521456979317628012721881537154107239389466063136007337120599915456659758559300673444689263854921332185562706707573660658164991098457874495054854491474065039621922972671588299315846306069845169959451250821044417886630346229021305410340100401530146135418806544340908355106582089082980533651095594192031411679866134256418292249592135441145384466261279428795408721990564658703903787956958168449841491667690491585550160457893350536334242689

from Crypto.Util.number import bytes_to_long
from hashlib import sha256

message = b"crypto{Immut4ble_m3ssag1ng}"

'''
c = m^e mod N
and S = H(m)^d mod N
where H(m) is the hash of m
'''

def H(message_given):
    hashed_message_bytes = sha256(message_given).digest()
    hashed_message_int = bytes_to_long(hashed_message_bytes)
    return hashed_message_int

'''S = H(message)^d mod N '''

S = encrypt(H(message), d, N)

print(S)
```

`output - 13480738404590090803339831649238454376183189744970683129909766078877706583282422686710545217275797376709672358894231550335007974983458408620258478729775647818876610072903021235573923300070103666940534047644900475773318682585772698155617451477448441198150710420818995347235921111812068656782998168064960965451719491072569057636701190429760047193261886092862024118487826452766513533860734724124228305158914225250488399673645732882077575252662461860972889771112594906884441454355959482925283992539925713424132009768721389828848907099772040836383856524605008942907083490383109757406940540866978237471686296661685839083475`

---
## Public Exponent
---

**Public Exponent/Salty**

`Given`

-> output.txt
```txt
n = 110581795715958566206600392161360212579669637391437097703685154237017351570464767725324182051199901920318211290404777259728923614917211291562555864753005179326101890427669819834642007924406862482343614488768256951616086287044725034412802176312273081322195866046098595306261781788276570920467840172004530873767                                                                  
e = 1
ct = 44981230718212183604274785925793145442655465025264554046028251311164494127485
```

-> salty.py
```python
#!/usr/bin/env python3

from Crypto.Util.number import getPrime, inverse, bytes_to_long, long_to_bytes

e = 1
d = -1

while d == -1:
    p = getPrime(512)
    q = getPrime(512)
    phi = (p - 1) * (q - 1)
    d = inverse(e, phi)

n = p * q

flag = b"XXXXXXXXXXXXXXXXXXXXXXX"
pt = bytes_to_long(flag)
ct = pow(pt, e, n)

print(f"n = {n}")
print(f"e = {e}")
print(f"ct = {ct}")

pt = pow(ct, d, n)
decrypted = long_to_bytes(pt)
assert decrypted == flag
```

python code
```python
'''
n = 110581795715958566206600392161360212579669637391437097703685154237017351570464767725324182051199901920318211290404777259728923614917211291562555864753005179326101890427669819834642007924406862482343614488768256951616086287044725034412802176312273081322195866046098595306261781788276570920467840172004530873767                                                                  
e = 1
ct = 44981230718212183604274785925793145442655465025264554046028251311164494127485
'''


from Crypto.Util.number import getPrime, inverse, bytes_to_long, long_to_bytes

# e = 1

# n = p * q

# flag = b"XXXXXXXXXXXXXXXXXXXXXXX"
# pt = bytes_to_long(flag)
# ct = pow(pt, e, n)
n = 110581795715958566206600392161360212579669637391437097703685154237017351570464767725324182051199901920318211290404777259728923614917211291562555864753005179326101890427669819834642007924406862482343614488768256951616086287044725034412802176312273081322195866046098595306261781788276570920467840172004530873767                                                                  
e = 1
d = pow(e,-1,n)
ct = 44981230718212183604274785925793145442655465025264554046028251311164494127485


pt = pow(ct, 1, n)
decrypted = long_to_bytes(pt)
print(decrypted.decode(encoding='latin-1'))
```

`output - crypto{saltstack_fell_for_this!}`

---


