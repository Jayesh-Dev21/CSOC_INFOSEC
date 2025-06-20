# File Types

I read the hint then

```bash
❯ grep -r "picoCTF{"
❯ xxd Flag.pdf | head -n 2
00000000: 2321 2f62 696e 2f73 680a 2320 5468 6973  #!/bin/sh.# This
00000010: 2069 7320 6120 7368 656c 6c20 6172 6368   is a shell arch
❯ subl Flag.pdf
❯ cp Flag.pdf script.sh
❯ subl script.sh
```


then I ran the part of script that created the flag
```bash
❯ >....                                                                
M-`>D-&C1H&C0T>4&3)IY&)#H9#3(&0T:#(Q``T]$TR&$!D`/4:#(,FFF$-``
M`/29&F0T!H#1ZC1H-!H&0%5/U(#30T`R`9`#$-``T,(T`831ID`:``#)IH&@
M8@#0`TTR:#)@@T9-`(`@`$Y`O(#0;.-IP&'H0%,$"M*(":A.ZM:B\SK&P]U]
❯ bash -c "$(${echo} "x - extracting flag (text)"
  sed 's/^X//' << 'SHAR_EOF' | uudecode &&
begin 600 flag
M(3QA<F-H/@IF;&%G+R`@("`@("`@("`@,"`@("`@("`@("`@,"`@("`@,"`@
M("`@-C0T("`@("`Q,#(T("`@("`@8`K'<>H`,I*D@0`````!````$F2!<P4`
M``#^`69L86<``$)::#DQ05DF4UD'O9@<```@______OS^>+_/=OO_73W_^[Y
M\0O]#?]_;L\W^WS?WPEJB[`!&VH(-#3$#0`!DR`&0T````,@`&F0`-&@9!HR
M-`>D-&C1H&C0T>4&3)IY&)#H9#3(&0T:#(Q``T]$TR&$!D`/4:#(,FFF$-``
M`/29&F0T!H#1ZC1H-!H&0%5/U(#30T`R`9`#$-``T,(T`831ID`:``#)IH&@
M8@#0`TTR:#)@@T9-`(`@`$Y`O(#0;.-IP&'H0%,$"M*(":A.ZM:B\SK&P]U]
M_(Q+>RNUWW_)RZN#W7YT.1Q?M@S$UK+:D]79/DD9>RTD?>'QO?>C:";TN$KN
MHIZZ!B1CJX9+7+?@3X?+BO7.Z!6L)D'TK$$R17C2N-6Z[`4I2;[=>.X!XOE1
MD@%0%*U</^:9QX5`YS/6]>D(USMFZCD2P10!L4VP=!Q5.<0)0O8#`!&H.,B*
MO#5Z[0`/'<'WV=S`02\FL(V^%!*T'L,T"-U!V(*)Q(,XVS#\/Z_32>+L^HPK
M/]G@&IZTI--JV+&EV$'BO$-@"!M&&SG$E1V[28@9I&0*+._^NC2)1*,EHF:[
MLZ#4-%6OPRG$06".S1LD(@I@-J*3,KAA"P9V8;'ADW&D0D#S?2,C$F]Z[998
MPX&P$M-1_KERJ@$+F0_Q=R13A0D`>]F!P,=Q``````````````$`````````
M"P``````5%)!24Q%4B$A(0``````````````````````````````````````
M````````````````````````````````````````````````````````````
M````````````````````````````````````````````````````````````
M````````````````````````````````````````````````````````````
M````````````````````````````````````````````````````````````
M````````````````````````````````````````````````````````````
M````````````````````````````````````````````````````````````
M````````````````````````````````````````````````````````````
M````````````````````````````````````````````````````````````
M````````````````````````````````````````````````````````````
,````````````````
`
end
SHAR_EOF
  (set 20 23 03 16 01 40 17 'flag'
   eval "${shar_touch}") && \
  chmod 0644 'flag')"
warning: database file for 'warpdotdev' does not exist (use '-Fy' to download)
warning: database file for 'sublime-text' does not exist (use '-Fy' to download)
bash: -c: line 1: syntax error near unexpected token `('
bash: -c: line 1: `zsh: command not found: x - extracting flag (text)'
```


and got a file `flag` of type current archive

when I opened it, it had many files and as the hint suggested i used binwalk
```bash
❯ binwalk -e flag

/home/wizard/code/CSOC/CSOC_INFOSEC/WEEK_0x01/stenography/chall7/extractions/flag
-----------------------------------------------------------------------
DECIMAL                            HEXADECIMAL                        DESCRIPTION
-----------------------------------------------------------------------
100                                0x64                               bzip2 
                                                                      compressed 
                                                                      data, 
                                                                      total 
                                                                      size: 
                                                                      510 
                                                                      bytes
-----------------------------------------------------------------------
[+] Extraction of bzip2 data at offset 0x64 completed successfully
-----------------------------------------------------------------------

Analyzed 1 file for 85 file signatures (187 magic patterns) in 3.0 milliseconds
```

```bash
❯ cd extractions/flag.extracted/64
❯ ls
 decompressed.bin
```


```bash
❯ cat decompressed.bin
�sdflagG��LZIP
              	O�'6�?O��n�X�C�ڱM����;"��i�?�(;Y&�F9&IG�"_�!�~x`���T�y�
 �C-�
��-�G��Zfm��p������>����(�_��:ѓ�K@���6�VN�)<m��@R�K0�6�ؤk
�\�-���9�3#��{b;51��d�e۬䦳ܑx���pSQ���� ���Ʃ4Z���-E��MC����ҭq�
                                                           �uY�'�C��jt��C�G��i�O\���mdo�<�2�j
                      h�g-B���H��uTO��F`2\�wGz/wG%                     
❯ file decompressed.bin
	decompressed.bin: gzip compressed data, was "flag", last modified: Thu Mar 16 01:40:17 2023, from Unix, original size modulo 2^32 327
❯ exiftool decompressed.bin
ExifTool Version Number         : 13.25
File Name                       : decompressed.bin
Directory                       : .
File Size                       : 355 bytes
File Modification Date/Time     : 2025:06:20 09:49:35+05:30
File Access Date/Time           : 2025:06:20 09:49:43+05:30
File Inode Change Date/Time     : 2025:06:20 09:49:35+05:30
File Permissions                : -rw-r--r--
File Type                       : GZIP
File Type Extension             : gz
MIME Type                       : application/x-gzip
Compression                     : Deflated
Flags                           : FileName
Modify Date                     : 2023:03:16 07:10:17+05:30
Extra Flags                     : (none)
Operating System                : Unix
Archived File Name              : flag
❯ mv decompressed.bin dd.gz
❯ gzip -d dd.gz
❯ file dd
dd: lzip compressed data, version: 1
❯ lzip -d -k dd
❯ ls
 dd
 dd.out
❯ file dd.out
dd.out: LZ4 compressed data (v1.4+)
❯ lz4 -d dd.out dd2
                                                                       dd.out                         : decoded 265 bytes 
❯ file dd2
dd2: LZMA compressed data, non-streamed, size 254
❯ mv dd2 dd3.lzma
❯ lzma -d -k dd3.lzma
❯ file dd3
dd3: lzop compressed data - version 1.040, LZO1X-1, os: Unix
❯ cp dd3 dd4.lzop
❯ lzop -d -k dd4.lzop -o dd5
❯ file dd5
dd5: lzip compressed data, version: 1
❯ cp dd5 dd6.lzip
❯ lzip -d -k dd6.lzip
❯ file dd6.lzip.out
dd6.lzip.out: XZ compressed data, checksum CRC64
❯ grep -r "picoCTF{"
❯ cp dd6.lzip.out dd7.xz
❯ xz -d -k dd7.xz
❯ file dd7
dd7: ASCII text
❯ cat dd7
7069636f4354467b66316c656e406d335f6d406e3170756c407431306e5f
6630725f3062326375723137795f37396230316332367d0a


❯ cat dd7 | xxd -r -p
picoCTF{f1len@m3_m@n1pul@t10n_f0r_0b2cur17y_79b01c26}
```

flag       -    picoCTF{f1len@m3_m@n1pul@t10n_f0r_0b2cur17y_79b01c26}