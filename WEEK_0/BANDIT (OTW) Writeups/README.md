# OverTheWire - Bandit Challenges 

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
