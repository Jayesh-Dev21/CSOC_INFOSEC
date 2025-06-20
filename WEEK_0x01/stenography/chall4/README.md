# MacroHard WeakEdge

I downloaded the ppt, and got a pop up that macros were disabled so I checked them and found one

but it was not of any use 
```
Rem Attribute VBA_ModuleType=VBAModule
Sub Module1
Rem Sub not_flag()
Rem     Dim not_flag As String
Rem     not_flag = "sorry_but_this_isn't_it"
Rem End Sub
Rem 
End Sub
```

and one of the slides had `not the flag`, I tried grep but showed nothig as they migh have used some encryption like base64,

I tried strings and got

```text
docProps/core.xmlPK
docProps/app.xmlPK
sWQON
ppt/slideMasters/hiddenPK
```

so

```bash

❯ binwalk -e Forensics\ is\ fun.pptm

/home/wizard/code/CSOC/CSOC_INFOSEC/WEEK_0x01/stenography/chall4/extractions/Forensics is fun.pptm
-----------------------------------------------------------------------------------------
DECIMAL                            HEXADECIMAL                        DESCRIPTION
-----------------------------------------------------------------------------------------
0                                  0x0                                ZIP archive, file 
                                                                      count: 153, total 
                                                                      size: 100093 bytes
-----------------------------------------------------------------------------------------
[+] Extraction of zip data at offset 0x0 completed successfully
-----------------------------------------------------------------------------------------

Analyzed 1 file for 85 file signatures (187 magic patterns) in 25.0 milliseconds
❯ cd extractions/Forensics\ is\ fun.pptm.extracted/0/ppt/slideMasters
❯ ls -llah
Permissions Size User   Date Modified Name
drwxr-xr-x     - wizard 20 Jun 08:13   _rels
.rw-r--r--    99 wizard 23 Oct  2020   hidden
.rw-r--r--   14k wizard  1 Jan  1980  󰗀 slideMaster1.xml
❯ strings hidden
Z m x h Z z o g c G l j b 0 N U R n t E M W R f d V 9 r b j B 3 X 3 B w d H N f c l 9 6 M X A 1 f Q
❯ strings hidden | strings
Z m x h Z z o g c G l j b 0 N U R n t E M W R f d V 9 r b j B 3 X 3 B w d H N f c l 9 6 M X A 1 f Q
❯ strings hidden | tr -d ' '
ZmxhZzogcGljb0NURntEMWRfdV9rbjB3X3BwdHNfcl96MXA1fQ
❯ strings hidden | tr -d ' ' | base64 -d
flag: picoCTF{D1d_u_kn0w_ppts_r_z1p5}
```

flag     -  picoCTF{D1d_u_kn0w_ppts_r_z1p5}