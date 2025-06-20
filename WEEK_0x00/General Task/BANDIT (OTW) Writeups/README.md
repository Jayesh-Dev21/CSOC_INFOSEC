# OverTheWire - Bandit Challenges 

**https://jayeshpuri.me**

To connect use
```bash
ssh bandit-level-@bandit.labs.overthewire.org -p 2220
```

---

## Bandit 0

**Command:**

```bash
ssh bandit0@bandit.labs.overthewire.org -p 2220
```

**Explanation:**

* For level 0 Connect to the Bandit game server over SSH on port 2220.

**Password:** `Achived`
---

## Bandit 0➔1

**Steps:**

```bash
ls
cat readme
```

**Explanation:**

* `ls`: Lists files in the directory.
* `cat`: Concatenate the contents of ther files.

**Password:** `Achived`

---

## Bandit 1➔2

**Steps:**

```bash
ls -la
cat < -
```
or use `cat ./-`

**Explanation:**

* `ls -llah`: Shows all files (including Hidden) and with size in long listing form
* Both `cat ./-` or `cat < -`: `-` can be used.

**Password:** `Achived`

---

## Bandit 2➔3

**Steps:**

```bash
ls
cat spaces\ in\ this\ filename
```

**Explanation:**

* Filename has spaces. Escape them using `\` to read it with `cat`.

**Password:** `Achived`

---
## Bandit 3➔4

**Steps:**

```bash
ls
cd inhere
ls -llah
cat .hidden-file-name
```

**Explanation:**

* The flag is inside `inhere` directory. Access using `cd`
* `ls -llah` to see hidden files `...Hiding-From-You`.
* Use `cat` concatenate

**Password:** `Achived`

---

## Bandit 4➔5

**Steps:**

```bash
cd inhere
ls -llah
cat ~/inhere/-file07
```

**Explanation:**

* Can be accessed using absoluten adderss to the file

**Password:** `Achived`

---

## Bandit 5➔6

**Steps:**

```bash
find ~/inhere -type f -size 1033c -print
```

**Explanation:**

* `maybehere07` had the file called `.file2`
* Access using `cat`

**Password:** `Achived`

---

## Bandit 6➔7

**Steps:**

```bash
find / -user bandit7 -group bandit6 -size 33c 2>/dev/null
or 
find / -user bandit7 -group bandit6 -size 33c -print
```

**Explanation:**

* Search `/` for ther required file owned by `bandit7` and group `bandit6`, of size 33 bytes with allowed permissions.
* Suppress errors with `2>/dev/null`. Only shows files with allowed permissions.
* File was `var/lib/dpkg/bandit.password`

**Password:** `Achived`

---

## Bandit 7➔8

```bash
grep -r millionth .
```

**Explanation:**

* `-r` searchs recurssively for the string "millionth" in the current directory.

**Password:** `Achived`

---

## Bandit 8➔9

```bash
sort Data.txt | uniq -c | sort -nr
```

**Explanation:**

* `sort Data.txt` - all lines are arranged in alphabetic order
* `Uniq -c` - Counts each ouccrrnce
* `sort -nr` - arranges in numeric order (accending) and `-r` to reverse to make it inverted (decending),

**Password:** `Achived`

---
## Bandit 9➔10

**Steps:**

```bash
ls -llah
grep -a ==== data.txt
```

**Explanation:**

* `-a` - for binary files to be proccessed as a text file.  `data.txt`

**Password:** `Achived`

---

## Bandit 10➔11

**Steps:**

```bash
strings data.txt
strings data.txt | base64 -d
```

**Explanation:**

* `-d` - to decode base64 encoded contents of `data.txt`.

**Password:** `Achived`

---

## Bandit 11➔12

```bash
file data.txt => ASCII TEXT
strings data.txt
```
Then using `rot13.com` to get the flag.

**Explanation:**

* ROT13 cipher is a type of Caesar shift. Used for encryption in the past days.

**Password:** `Achived`

---

## Bandit 12➔13

```bash
mktemp -d => `/tmp/tmp.4C3plgulef`
cd /tmp/tmp.4C3plgulef
cp ~/data.txt ./bot.txt
mv bot.txt data.txt

xxd -r data.txt data1.txt
file data1.txt => `gzip`

cp data1.txt data2.gz
gzip -d data2.gz => `data2`

file data2 => `bzip2`
cp data2 data3.bz2 && ls

bzip2 -d bata3.bz2 => `data3`
file data3 => `gzip`\

cp data3 4data.gz
gzip -d 4data.gz => `4data`
file 4data => `tar`

xxd 4data | head -50
cp 4data 5data.tar

tar -xf 5data.tar => data5.bin
ls -llah
file data5.bin => `tar`

xxd data5.bin | head -50
cp data5.bin 6data.tar
tar -xf 6data.tar => `data6.bin`
ls -llah
file data6.bin => `bzip2`

cp data6.bin 7data.bz2
bzip2 -d 7data.bz2 => 7data
file 7data => `tar`

cp 7data 8data.tar
tar -xf 8data.tar => data8.bin
ls -llah
file data8.bin => `Gzip`
cp data8.bin 9data.gz

gzip -d 9data.gz => 9data
ls && file 9data => `ASCII` `TEXT`

cp 9data final_password

strings final_password
```

**Password:** `Achived`

---

## Bandit 13➔14

After logging in 
```bash
cat /ect/bandit_pass/bandit14 => `permission_denied`
ls -llah => `SSHkey.private`

ssh -i sshkey.private bandit14.localhost -p 2220


@bandit14~> cat /ect/bandit_pass/bandit14
```

**Password:** `Achived`
---

## Bandit 14➔15


```bash
nc localhost 30000
```

**Explanation:**

* `nc` (netcat) connects to a local TCP service to read the next password.

**Password:** `Achived`

---

## Bandit 15➔16

**Steps:**

```bash
openssl s_client -connect localhost:30001
```
OR 

```bash
ncat -ssl localhost 30001
```

**Explanation:**

* TLS-encrypted service - a secure network connection protocol that encrypts data to protect privacy, authentication, and data integrity.

**Password:** `Achived`

---

## Bandit 16➔17

```bash
nmap localhost -p 31000-32000
```

Gave 5 open ports
```json
-31046
-31518
-31691
-31790
-31960
```
Out of which

```json
-31790
-31518
```
Gave the Private key

```
-----BEGIN CERTIFICATE-----
MIIFBzCCAu+gAwIBAgIUBLz7DBxA0IfojaL/WaJzE6Sbz7cwDQYJKoZIhvcNAQEL
BQAwEzERMA8GA1UEAwwIU25ha2VPaWwwHhcNMjQwNjEwMDM1OTUwWhcNMzQwNjA4
MDM1OTUwWjATMREwDwYDVQQDDAhTbmFrZU9pbDCCAiIwDQYJKoZIhvcNAQEBBQAD
ggIPADCCAgoCggIBANI+P5QXm9Bj21FIPsQqbqZRb5XmSZZJYaam7EIJ16Fxedf+
jXAv4d/FVqiEM4BuSNsNMeBMx2Gq0lAfN33h+RMTjRoMb8yBsZsC063MLfXCk4p+
09gtGP7BS6Iy5XdmfY/fPHvA3JDEScdlDDmd6Lsbdwhv93Q8M6POVO9sv4HuS4t/
jEjr+NhE+Bjr/wDbyg7GL71BP1WPZpQnRE4OzoSrt5+bZVLvODWUFwinB0fLaGRk
GmI0r5EUOUd7HpYyoIQbiNlePGfPpHRKnmdXTTEZEoxeWWAaM1VhPGqfrB/Pnca+
vAJX7iBOb3kHinmfVOScsG/YAUR94wSELeY+UlEWJaELVUntrJ5HeRDiTChiVQ++
wnnjNbepaW6shopybUF3XXfhIb4NvwLWpvoKFXVtcVjlOujF0snVvpE+MRT0wacy
tHtjZs7Ao7GYxDz6H8AdBLKJW67uQon37a4MI260ADFMS+2vEAbNSFP+f6ii5mrB
18cY64ZaF6oU8bjGK7BArDx56bRc3WFyuBIGWAFHEuB948BcshXY7baf5jjzPmgz
mq1zdRthQB31MOM2ii6vuTkheAvKfFf+llH4M9SnES4NSF2hj9NnHga9V08wfhYc
x0W6qu+S8HUdVF+V23yTvUNgz4Q+UoGs4sHSDEsIBFqNvInnpUmtNgcR2L5PAgMB
AAGjUzBRMB0GA1UdDgQWBBTPo8kfze4P9EgxNuyk7+xDGFtAYzAfBgNVHSMEGDAW
gBTPo8kfze4P9EgxNuyk7+xDGFtAYzAPBgNVHRMBAf8EBTADAQH/MA0GCSqGSIb3
DQEBCwUAA4ICAQAKHomtmcGqyiLnhziLe97Mq2+Sul5QgYVwfx/KYOXxv2T8ZmcR
Ae9XFhZT4jsAOUDK1OXx9aZgDGJHJLNEVTe9zWv1ONFfNxEBxQgP7hhmDBWdtj6d
taqEW/Jp06X+08BtnYK9NZsvDg2YRcvOHConeMjwvEL7tQK0m+GVyQfLYg6jnrhx
egH+abucTKxabFcWSE+Vk0uJYMqcbXvB4WNKz9vj4V5Hn7/DN4xIjFko+nREw6Oa
/AUFjNnO/FPjap+d68H1LdzMH3PSs+yjGid+6Zx9FCnt9qZydW13Miqg3nDnODXw
+Z682mQFjVlGPCA5ZOQbyMKY4tNazG2n8qy2famQT3+jF8Lb6a4NGbnpeWnLMkIu
jWLWIkA9MlbdNXuajiPNVyYIK9gdoBzbfaKwoOfSsLxEqlf8rio1GGcEV5Hlz5S2
txwI0xdW9MWeGWoiLbZSbRJH4TIBFFtoBG0LoEJi0C+UPwS8CDngJB4TyrZqEld3
rH87W+Et1t/Nepoc/Eoaux9PFp5VPXP+qwQGmhir/hv7OsgBhrkYuhkjxZ8+1uk7
tUWC/XM0mpLoxsq6vVl3AJaJe1ivdA9xLytsuG4iv02Juc593HXYR8yOpow0Eq2T
U5EyeuFg5RXYwAPi7ykw1PW7zAPL4MlonEVz+QXOSx6eyhimp1VZC11SCg==
-----END CERTIFICATE-----
```
* It can be save in a tmp folder
```bash
mktemp -d
cd /tmp/tmp.NA9YDpZ0Mz
vim private.key <= `paste_the_private_key`
```
and the give the key by
```bash
ssh -i private.key bandit17@bandit.labs.overthewire.org -p 2220
```
To get the password.
---
