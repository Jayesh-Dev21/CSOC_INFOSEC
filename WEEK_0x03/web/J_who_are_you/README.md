# Who are You

link to the chall - [link](https://play.picoctf.org/practice/challenge/142?difficulty=2&page=1&search=who&solved=0)

Guide to [RFC2616](https://tools.ietf.org/html/rfc2616) the protocol to web

---



---

Opened with Burp suite, then we are asked to change the user agent to `PicoBrowser`

After doing that we are told that ` I don't trust users visiting from another site. ` I used - https://developer.mozilla.org/en-US/docs/Web/HTTP/Reference/Headers

and used Referer tag with the same site.

Then the wesite said that `Sorry, this site only worked in 2018.` So I added a date header, with a random date and time from 2018.

Next, we were asked to make ourselves untraceable, I added DNT

Next I added a header to change my ip to that of sweden, and finally added support to accept swedish language in language header


Final Header looks like
```http
GET / HTTP/1.1
Host: mercury.picoctf.net:1270
Accept-Language: en-US,en;q=0.9;sv-SE
Upgrade-Insecure-Requests: 1
User-Agent: PicoBrowser
Referer: mercury.picoctf.net:1270
Date: Sun, 06 Nov 2018 08:49:37 GMT
DNT: 1
X-Forwarded-For: 103.69.158.255
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7
Accept-Encoding: gzip, deflate, br
Connection: keep-alive
```

Which gave the flag - `picoCTF{http_h34d3rs_v3ry_c0Ol_much_w0w_f56f58a5}`