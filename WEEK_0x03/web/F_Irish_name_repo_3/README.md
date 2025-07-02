# Irish name Repo - 3

link to the chall - [link](https://play.picoctf.org/practice/challenge/8?page=1&search=Irish)

---

[vid.webm](https://github.com/user-attachments/assets/0e9f6b97-b745-45c4-88f3-c238f2f058b4)


---

I opened the website, and on opennig the admin login page I swa that we only had to put the password, 

I tried password - `password` and got a openned in burp, saw the string to be strange, I saw an option of debug-`0` it made it true `1` which showed me the SQL, and I tried `' OR '1'='1' --` which became `' BE '1'='1' --` 

I saw that it was a rot cipher - `ROT-13`

so I reversed it 

and I got the flag!

flag - `picoCTF{3v3n_m0r3_SQL_06a9db19}`
