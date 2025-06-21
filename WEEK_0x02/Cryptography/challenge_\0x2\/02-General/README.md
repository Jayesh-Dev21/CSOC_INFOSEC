# Challenge - 2 {Crypto} [Sub Chall 2] General

**ASCII**

```python
nums = [99, 114, 121, 112, 116, 111, 123, 65, 83, 67, 73, 73, 95, 112, 114, 49, 110, 116, 52, 98, 108, 51, 125]

s = ""
for n in nums:
	s += chr(n)

print(s)
```

```bash
> python3 ascii.py
crypto{ASCII_pr1nt4bl3}
```

```
flag -- crypto{ASCII_pr1nt4bl3}
```

---

**Hex**

```bash
> echo "63727970746f7b596f755f77696c6c5f62655f776f726b696e675f776974685f6865785f737472696e67735f615f6c6f747d" | xxd -r -p
crypto{You_will_be_working_with_hex_strings_a_lot}
```

or we can write a py script as well

```python
string = "63727970746f7b596f755f77696c6c5f62655f776f726b696e675f776974685f6865785f737472696e67735f615f6c6f747d"

s = bytes.fromhex(string)
g = s.decode(encoding="utf-8")
print(g)
```

```
flag - crypto{You_will_be_working_with_hex_strings_a_lot}
```
---


**Base 64**

```python
st = "72bca9b68fc16ac7beeb8f849dca1d8a783e8acf9679bf9269f7bf"

import base64

sst = bytes.fromhex(st)


sst = base64.b64encode(sst).decode()

print(sst)
```
```bash
> python3 base.py
crypto/Base+64+Encoding+is+Web+Safe/
```

```
flag - crypto/Base+64+Encoding+is+Web+Safe/
```

---

**Bytes and Big Integers**

```python
from Crypto.Util.number import *

iiti = 11515195063862318899931685488813747395775516287289682636499965282714637259206269 

itii = long_to_bytes(iiti)

itii = itii.decode(encoding='utf-8')
print(itii)
```

```bash
> python3 bytes.py
crypto{3nc0d1n6_4ll_7h3_w4y_d0wn}
```

```
flag - > crypto{3nc0d1n6_4ll_7h3_w4y_d0wn}
```

---

**Encoding Challenge**

```bash
> python3 pwntools_example_f93ca6ccef2def755aa8f6d9aa6e9c5b.py
[x] Opening connection to socket.cryptohack.org on port 1337
[▘] Opening connection to socket.cryptohack.org on port 1337
[▝] Opening connection to socket.cryptohack.org on port 1337
[+] one
{'flag': 'crypto{3nc0d3_d3c0d3_3nc0d3}'}
[*] Closed connection to socket.cryptohack.org port 13377
```

after 100 attpets of successful guesses

```python
from pwn import * # pip install pwntools
import socket
import json
import base64
import codecs

r = remote('socket.cryptohack.org', 13377, level = 'debug')

def json_recv():
    line = r.recvline()
    return json.loads(line.decode())

def json_send(hsh):
    request = json.dumps(hsh).encode()
    r.sendline(request)

def decode(encoded_type, encoded_data):
    if encoded_type == "base64":
        return base64.b64decode(encoded_data).decode()
    elif encoded_type == "hex":
        return bytes.fromhex(encoded_data).decode()
    elif encoded_type == "rot13":
        return codecs.decode(encoded_data, 'rot_13')
    elif encoded_type == "bigint":
        n = int(encoded_data, 16)
        return n.to_bytes((n.bit_length() + 7) // 8, 'big').decode()
    elif encoded_type == "utf-8":
        return ''.join([chr(b) for b in encoded_data])
    else:
        print("Unsupported encoding type: {encoded_type}")


for i in range(100):
    received = json_recv()

    # print("Received type: ")
    # print(received["type"])
    # print("Received encoded value: ")
    # print(received["encoded"])
    decoded = decode(received["type"], received["encoded"])
    # print(decoded)
    # to_send = {
    #     "decoded": "changeme"
    # }

    to_send = {"decoded": decoded}

    


    json_send(to_send)

print(json_recv())
```

```
flag - crypto{3nc0d3_d3c0d3_3nc0d3}
```

---