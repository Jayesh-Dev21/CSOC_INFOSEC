# Challenge - 2 {Crypto} [Sub Chall 2] Symmetric Cipher/Working of AES

**Keyed Permutations**

```txt
A "block" just refers to a fixed number of bits or bytes, which may represent any kind of data. AES processes a block and outputs another block. We'll be specifically talking the variant of AES which works on 128 bit (16 byte) blocks and a 128 bit key, known as AES-128.
```

`flag - crypto{bijection}`

---

**Resisting Bruteforce**

Biclique Attack redues the security margin of AES-128 only slightly, from 128 bits to 126.1 bits

`flag - crypto{Biclique}`

---

**Structure of AES**


```python
def bytes2matrix(text):
    """ Converts a 16-byte array into a 4x4 matrix.  """
    return [list(text[i:i+4]) for i in range(0, len(text), 4)]

def matrix2bytes(matrix):
  chhr = ""
  for i in range (0, len(matrix)):
    for b in range (0, len(matrix[i])):
      g = matrix[i][b]
      chhr += chr(g)
  return chhr

matrix = [
    [99, 114, 121, 112],
    [116, 111, 123, 105],
    [110, 109, 97, 116],
    [114, 105, 120, 125]
  ]
  
print(matrix2bytes(matrix))
```

```txt
flag - crypto{inmatrix}
```

---
