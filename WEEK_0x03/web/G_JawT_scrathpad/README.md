# JaWT Scratchpad

link to the chall - [link](https://play.picoctf.org/practice/challenge/25?difficulty=2&page=1&search=jawt&solved=0)

---

[vid.webm](https://github.com/user-attachments/assets/d7860ef8-fb6a-4b5c-aa23-a73a797cb971)

---

on visting the website, i encountered a url pointing to john the ripper, which gave me a hint of secrect hash used in a jwt token, as the name of chall is JaWT and capital letters are `jwt`.

So, moving on, I regestered as `john` and got my cookie, then I first checked the cookie using `jwt.io`. I perefer the old one hosted at `https://jwt.lannysport.net/`, old ui much better, cleaner and easy to use.

Then I save the token in a file, and then run john to crack the password.

In my case, it was giving some error and showed no hash matched.

so I used hashcat with rockyou wordlist and the jwt token.
```bash
~/code/CSOC/CSOC_INFOSEC/WEEK_0x03/web/G_JawT_scrathpad (main*) » hashcat -a 0 -m 16500 jwt.txt path/to/rockyou --show

eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJ1c2VyIjoiam9obiJ9._fAF3H23ckP4QtF1Po3epuZWxmbwpI8Q26hRPDTh32Y:ilovepico
```

Then I got the secret `ilovepico` 

Then, I edited the JWT token as admin with the secret.

Then changed the cookies on the site and reloaded it

And I got the flag!

flag - `picoCTF{jawt_was_just_what_you_thought_f859ab2f}`
