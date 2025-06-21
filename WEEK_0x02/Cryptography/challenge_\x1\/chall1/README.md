# Challenge - 1 {Crypto} [Sub Chall 1]

```bash
> echo "01000011 01000011 01010011 01001111 01000011 00110010 00110101  173 61 144 63 156 67 61 146 171  49 110 103 95 100 49  66 66 33 72 33 6e 37 5f 33  bmMwZDFuZzV9" > encoded_string

> cat encoded_string

01000011 01000011 01010011 01001111 01000011 00110010 00110101  173 61 144 63 156 67 61 146 171  49 110 103 95 100 49  66 66 33 72 33 6e 37 5f 33  bmMwZDFuZzV9
> sed 's/  /@/g' encoded_string | cut -d '@' -f1 > encoding1
> sed 's/  /@/g' encoded_string | cut -d '@' -f2 > encoding2
> sed 's/  /@/g' encoded_string | cut -d '@' -f3 > encoding3
> sed 's/  /@/g' encoded_string | cut -d '@' -f4 > encoding4
> sed 's/  /@/g' encoded_string | cut -d '@' -f5 > encoding5
```

I found a very helpful document for convertion, worth reading ---> [link](https://www.cyberciti.biz/faq/bc-convert-octal-to-hexadecimal-number/) used for octal to hex or decimal to hex convertion further ahead.

now its time to decrypt,

```bash
> cat encoding1 | xxd -r -b
CSOC25                                                                  
> cat encoding1 | xxd -r -b > solution
> tr ' ' '\n' < encoding2 | while read -r num; do (echo "obase=16; ibase=8; $num" | bc) done | xxd -r -p >> solution                                                         
> tr ' ' '\n' < encoding3 | while read -r num; do (echo "obase=16; ibase=10; $num" | bc) done | xxd -r -p
1ng_d1                                                                 
> tr ' ' '\n' < encoding3 | while read -r num; do (echo "obase=16; ibase=10; $num" | bc) done | xxd -r -p >> solution
> cat encoding4 | xxd -r -p
ff3r3n7_3                                                               
> cat encoding4 | xxd -r -p >> solution
> cat encoding5 | base64 -d
nc0d1ng5}                                                               
> cat encoding5 | base64 -d >> solution
```

```json
{
	"encoding1": "Binary --> Text",
	"encoding2": "Octal --> Text",
	"encoding3": "Decimal ASCII --> text",
	"encoding4": "Hexadecimal --> Text",
	"encoding5": "Base 64 encoding"
}
```


Now lets concatinate the solution
```bash
> cat solution
CSOC25{1d3n71fy1ng_d1ff3r3n7_3nc0d1ng5}
```