# Challenge - 2 {Crypto} [Sub Chall 1] Intro


**Finding Flags**

```
Flag - crypto{y0ur_f1rst_fl4g}
```

---

**Great Snakes**

```bash
> wget https://cryptohack.org/static/challenges/great_snakes_35381fca29d68d8f3f25c9fa0a9026fb.py

> python3 great_snakes_35381fca29d68d8f3f25c9fa0a9026fb.py
Here is your flag:
crypto{z3n_0f_pyth0n}
```

```
Flag - crypto{z3n_0f_pyth0n}
```

---

**Network Attacks**

```bash
> nc socket.cryptohack.org 11112
Welcome to netcat's flag shop!
What would you like to buy?
I only speak JSON, I hope that's ok.

{"buy": "clothes"}
{"error": "Sorry! All we have to sell are flags."}
{"buy": "flags"}
{"error": "Sorry! All we have to sell are flags."}
{"buy": "flag"}
{"flag": "crypto{sh0pp1ng_f0r_fl4g5}"}
```

Now, let's use the given script as well
```bash
> src
> python3 pwntools_example_72a60ff13df200692898bb14a316ee0b.py
[/] Opening connection to socket.cryptohack.org on port 11112: Trying [+] Opening connection to socket.cryptohack.org on port 11112: Done
b"Welcome to netcat's flag shop!\n"
b'What would you like to buy?\n'
b"I only speak JSON, I hope that's ok.\n"
b'\n'
{'flag': 'crypto{sh0pp1ng_f0r_fl4g5}'}
[*] Closed connection to socket.cryptohack.org port 11112
```
```python
#!/usr/bin/env python3

from pwn import * # pip install pwntools
import json

HOST = "socket.cryptohack.org"
PORT = 11112

r = remote(HOST, PORT)


def json_recv():
    line = r.readline()
    return json.loads(line.decode())

def json_send(hsh):
    request = json.dumps(hsh).encode()
    r.sendline(request)


print(r.readline())
print(r.readline())
print(r.readline())
print(r.readline())

request = {
    "buy": "flag"
}
json_send(request)

response = json_recv()

print(response)

```
Here all I did is change `clothes` to `flag`
```
Flag - crypto{sh0pp1ng_f0r_fl4g5}
```