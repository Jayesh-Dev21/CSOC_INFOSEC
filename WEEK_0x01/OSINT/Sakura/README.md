# Sakura Room - OSINT

[Room Link](https://tryhackme.com/r/room/sakura)

---

To start, I typed `Let's GO!` as it was the Task - 1 and began solving the room.

The whole room had 5 Tasks, so lets start.

---

**Task 2**

So I downloaded the svg and ran some metadata checks

```bash
❯ exiftool sakurapwnedletter.svg | tail -n 7 | head -n 1 | cut -d ' ' -f19
/home/SakuraSnowAngelAiko/Desktop/pwnedletter.png
❯ exiftool sakurapwnedletter.svg | tail -n 7 | head -n 1 | cut -d ' ' -f19 | cut -d "/" -f3
SakuraSnowAngelAiko
```

as in unix operating systems the current user directory ot `~/` is `/home/username/`

---

**Task 3**

I used the username and searched it on google found a github and twitter.

I used sherlock as well and got 
```bash
❯ sherlock SakuraSnowAngelAiko
[*] Checking username SakuraSnowAngelAiko on:

[+] ArtStation: https://www.artstation.com/SakuraSnowAngelAiko
[+] Freelance.habr: https://freelance.habr.com/freelancers/SakuraSnowAngelAiko
[+] GNOME VCS: https://gitlab.gnome.org/SakuraSnowAngelAiko
[+] GitHub: https://www.github.com/SakuraSnowAngelAiko
[+] kaskus: https://www.kaskus.co.id/@SakuraSnowAngelAiko
[+] Linktree: https://linktr.ee/SakuraSnowAngelAiko
[+] Mydramalist: https://www.mydramalist.com/profile/SakuraSnowAngelAiko
[+] NationStates Nation: https://nationstates.net/nation=SakuraSnowAngelAiko
[+] NationStates Region: https://nationstates.net/region=SakuraSnowAngelAiko
[+] Reddit: https://www.reddit.com/user/SakuraSnowAngelAiko
[+] Weblate: https://hosted.weblate.org/user/SakuraSnowAngelAiko/
[+] YandexMusic: https://music.yandex/users/SakuraSnowAngelAiko/playlists
[+] mastodon.cloud: https://mastodon.cloud/@SakuraSnowAngelAiko
[+] threads: https://www.threads.net/@SakuraSnowAngelAiko

[*] Search completed with 14 results
```

on the twitter page on digging a bit I got 

his [twitter or X](https://x.com/SakuraLoverAiko/)
![img](./task-3/name.png)

So I guessed the name to be `Aiko Abe` which was correct

and then I went on digging more about this person from sherlock's responses

I saw that out of the 9 public repos 6 were forked, that meant that his details can not be in those 6 repos

I did some more research and found the IO use just a hello world programm and ETH was some ethrium port and connection stuff but when I search what PGP keys was I found that 

PGP is 
```
PGP (Pretty Good Privacy) keys are used to encrypt and decrypt data, primarily emails, files, and messages, ensuring confidentiality and authenticity.
```

this was his [public key](./task-3/publickey)

and then I got

```bash
❯ gpg --list-packets publickey
# off=0 ctb=99 tag=6 hlen=3 plen=397
:public key packet:
	version 4, algo 1, created 1611377670, expires 0
	pkey[0]: [3072 bits]
	pkey[1]: [17 bits]
	keyid: ECDD0FD294110450
# off=400 ctb=b4 tag=13 hlen=2 plen=32
:user ID packet: "SakuraSnowAngel83@protonmail.com"
# off=434 ctb=89 tag=2 hlen=3 plen=468
:signature packet: algo 1, keyid ECDD0FD294110450
	version 4, created 1611377670, md5len 0, sigclass 0x13
	digest algo 10, begin of digest ff fd
	hashed subpkt 33 len 21 (issuer fpr v4 A6519F273BF88E9126B0F4C5ECDD0FD294110450)
	hashed subpkt 2 len 4 (sig created 2021-01-23)
	hashed subpkt 27 len 1 (key flags: 03)
	hashed subpkt 9 len 4 (key expires after 1y364d15h5m)
	hashed subpkt 11 len 4 (pref-sym-algos: 9 8 7 2)
	hashed subpkt 21 len 5 (pref-hash-algos: 10 9 8 11 2)
	hashed subpkt 22 len 3 (pref-zip-algos: 2 3 1)
	hashed subpkt 30 len 1 (features: 01)
	hashed subpkt 23 len 1 (keyserver preferences: 80)
	subpkt 16 len 8 (issuer key ID ECDD0FD294110450)
	data: [3069 bits]
# off=905 ctb=b9 tag=14 hlen=3 plen=397
:public sub key packet:
	version 4, algo 1, created 1611377670, expires 0
	pkey[0]: [3072 bits]
	pkey[1]: [17 bits]
	keyid: 56F0B4AEE3F26C46
# off=1305 ctb=89 tag=2 hlen=3 plen=444
:signature packet: algo 1, keyid ECDD0FD294110450
	version 4, created 1611377670, md5len 0, sigclass 0x18
	digest algo 10, begin of digest 42 df
	hashed subpkt 33 len 21 (issuer fpr v4 A6519F273BF88E9126B0F4C5ECDD0FD294110450)
	hashed subpkt 2 len 4 (sig created 2021-01-23)
	hashed subpkt 27 len 1 (key flags: 0C)
	hashed subpkt 9 len 4 (key expires after 1y364d15h5m)
	subpkt 16 len 8 (issuer key ID ECDD0FD294110450)
	data: [3071 bits]
```

on playing with some commands 

I got 

```bash
❯ gpg --list-packets publickey | grep @ | tr -d ' ' | cut -d '"' -f2
SakuraSnowAngel83@protonmail.com
```
 task 3 solved

 ---

 **Task 4**

 `Ethereum` from ETH repo discussed in prev part

 on checking the commit history I found two things

 1. his original commit with it walllet details 
```
stratum://0xa102397dbeeBeFD8cD2F73A89122fCdB53abB6ef.Aiko:pswd@eu1.ethermine.org:4444
```

2. Funny comments


I found out that 

| **Component**                                | **Meaning**                                                       |
| -------------------------------------------- | ----------------------------------------------------------------- |
| `stratum://`                                 | Protocol used for mining communication (Stratum protocol)         |
| `0xa102397dbeeBeFD8cD2F73A89122fCdB53abB6ef` | **Ethereum wallet address** — destination for mining rewards      |
| `.Aiko`                                      | **Worker name** — identifier for your mining device or session    |
| `:pswd`                                      | **Worker password** — optional, often set to `x` or left empty    |
| `@eu1.ethermine.org`                         | **Mining pool server** — Ethermine's European node                |
| `:4444`                                      | **Port** — port used for Stratum mining (typically 4444 or 14444) |



I then used [Etherscan](https://etherscan.io/) with the given wallet address and found that the transaction was made to `Tether`

![img](./task-4/scan.png)

![img](./task-4/solve.png)

so I solved task 4 as well

---

**Task 5**

They are asking about hacker's twitter handle which I found in task 2 

link - https://x.com/SakuraLoverAiko/
handle - SakuraLoverAiko


Now they want BSSID

which is 
```
BSSID, which stands for Basic Service Set Identifier, is a unique identifier for a specific Wi-Fi access point (AP)
```

<h2>Hint:</h2>

```Hint
When you have found the site to search for the BSSID, register an account and use the Advanced Search.
```

![img](./task-5/wigle.png)

searching for wigle bssid gave me `wigle.net`


Then I read the chall description and it said we need to go from twitter to dark web, so on reading the posts by the hacker I found about `DEEP Paste` which is like pastebin but on the dark web


so I installed tor-browser and opened it 
![img](./task-5/dark-web.png)



md5 = b2b37b3c106eb3f86e2340a3050968e2 

I searched for a bit with both new and old md5 but found nothing


then I found out that it was deleted on a reddit post


then I did find a link to screenshot of the paste which was on the dark web

![img](./task-5/deeppaste.png)


Then I went back to wigle to solve the challange

But I tried various values and exhausted my quries




I am getting thousands of responses while searching for BSSID even though I have specified the co ordinates in advanced search, so I guess it is not possible to complete the task - 5 and thus the room as the image from dark web is also removed.


---

**Task 6**

From the images uploaded on X.com we get to know that prior to boarding the flight the hacker was in Bethesda which is in USA, 

so the nearest airport to Bethesda is `DCA` I found this from a simple google search
```
Ronald Reagan Washington National Airport (DCA), Washington Dulles International Airport (IAD), and Baltimore/Washington International Thurgood Marshall Airport (BWI). DCA is generally the closest,
```

Attacker had posted an image stating `My final layover, time to relax!`

so we just need to identify that place

and from the image found of the dark web we also know that he is heading towards `Hirosaki`

I also found the lake using maps
![img](./task-6/lake.png)

Name of the lake is `Lake Inawashiro`


![img](./task-6/la.png)

For the lounge I did google lens and found out a link

https://everybodyhatesatourist.net/japan-airlines-jal-first-class-lounge-tokyo-haneda-hnd-review/

So the lounge was at Haneda Airtpot

I searched its 3 digit airport code which was `HND`


---


And so I completed this room except one chall from task 5