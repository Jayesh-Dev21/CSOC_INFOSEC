```bash
❯ ..folder chall2
❯ wget https://mercury.picoctf.net/static/2978e1270538613cd8181c7b0dabe9bd/dolls.jpg
--2025-06-14 22:14:46--  https://mercury.picoctf.net/static/2978e1270538613cd8181c7b0dabe9bd/dolls.jpg
Loaded CA certificate '/etc/ssl/certs/ca-certificates.crt'
Resolving mercury.picoctf.net (mercury.picoctf.net)... 18.189.209.142
Connecting to mercury.picoctf.net (mercury.picoctf.net)|18.189.209.142|:443... connected.
HTTP request sent, awaiting response... 200 OK
Length: 651622 (636K) [application/octet-stream]
Saving to: ‘dolls.jpg’

dolls.jpg        100%[=========>] 636.35K   259KB/s    in 2.5s    

2025-06-14 22:14:50 (259 KB/s) - ‘dolls.jpg’ saved [651622/651622]

❯ grep -r "picoCTF{"
❯ exiftool dolls.jpg
ExifTool Version Number         : 13.25
File Name                       : dolls.jpg
Directory                       : .
File Size                       : 652 kB
File Modification Date/Time     : 2021:03:16 05:53:04+05:30
File Access Date/Time           : 2025:06:14 22:14:52+05:30
File Inode Change Date/Time     : 2025:06:14 22:14:50+05:30
File Permissions                : -rw-r--r--
File Type                       : PNG
File Type Extension             : png
MIME Type                       : image/png
Image Width                     : 594
Image Height                    : 1104
Bit Depth                       : 8
Color Type                      : RGB with Alpha
Compression                     : Deflate/Inflate
Filter                          : Adaptive
Interlace                       : Noninterlaced
Profile Name                    : ICC Profile
Profile CMM Type                : Apple Computer Inc.
Profile Version                 : 2.1.0
Profile Class                   : Display Device Profile
Color Space Data                : RGB
Profile Connection Space        : XYZ
Profile Date Time               : 2020:06:09 12:08:45
Profile File Signature          : acsp
Primary Platform                : Apple Computer Inc.
CMM Flags                       : Not Embedded, Independent
Device Manufacturer             : Apple Computer Inc.
Device Model                    : 
Device Attributes               : Reflective, Glossy, Positive, Color
Rendering Intent                : Perceptual
Connection Space Illuminant     : 0.9642 1 0.82491
Profile Creator                 : Apple Computer Inc.
Profile ID                      : 0
Profile Description             : Display
Profile Description ML (hr-HR)  : LCD u boji
Profile Description ML (ko-KR)  : 컬러 LCD
Profile Description ML (nb-NO)  : Farge-LCD
Profile Description ML (hu-HU)  : Színes LCD
Profile Description ML (cs-CZ)  : Barevný LCD
Profile Description ML (da-DK)  : LCD-farveskærm
Profile Description ML (nl-NL)  : Kleuren-LCD
Profile Description ML (fi-FI)  : Väri-LCD
Profile Description ML (it-IT)  : LCD colori
Profile Description ML (es-ES)  : LCD color
Profile Description ML (ro-RO)  : LCD color
Profile Description ML (fr-CA)  : ACL couleur
Profile Description ML (uk-UA)  : Кольоровий LCD
Profile Description ML (he-IL)  : ‏LCD צבעוני
Profile Description ML (zh-TW)  : 彩色LCD
Profile Description ML (vi-VN)  : LCD Màu
Profile Description ML (sk-SK)  : Farebný LCD
Profile Description ML (zh-CN)  : 彩色LCD
Profile Description ML (ru-RU)  : Цветной ЖК-дисплей
Profile Description ML (en-GB)  : Colour LCD
Profile Description ML (fr-FR)  : LCD couleur
Profile Description ML (hi-IN)  : रंगीन LCD
Profile Description ML (th-TH)  : LCD สี
Profile Description ML (ca-ES)  : LCD en color
Profile Description ML (en-AU)  : Colour LCD
Profile Description ML (es-XL)  : LCD color
Profile Description ML (de-DE)  : Farb-LCD
Profile Description ML          : Color LCD
Profile Description ML (pt-BR)  : LCD Colorido
Profile Description ML (pl-PL)  : Kolor LCD
Profile Description ML (el-GR)  : Έγχρωμη οθόνη LCD
Profile Description ML (sv-SE)  : Färg-LCD
Profile Description ML (tr-TR)  : Renkli LCD
Profile Description ML (pt-PT)  : LCD a Cores
Profile Description ML (ja-JP)  : カラーLCD
Profile Copyright               : Copyright Apple Inc., 2020
Media White Point               : 0.94955 1 1.08902
Red Matrix Column               : 0.51099 0.23955 -0.00104
Green Matrix Column             : 0.29517 0.69981 0.04224
Blue Matrix Column              : 0.15805 0.06064 0.78369
Red Tone Reproduction Curve     : (Binary data 2060 bytes, use -b option to extract)
Video Card Gamma                : (Binary data 48 bytes, use -b option to extract)
Native Display Info             : (Binary data 62 bytes, use -b option to extract)
Chromatic Adaptation            : 1.04861 0.02332 -0.05034 0.03018 0.99002 -0.01714 -0.00922 0.01503 0.75172
Make And Model                  : (Binary data 40 bytes, use -b option to extract)
Blue Tone Reproduction Curve    : (Binary data 2060 bytes, use -b option to extract)
Green Tone Reproduction Curve   : (Binary data 2060 bytes, use -b option to extract)
Exif Byte Order                 : Big-endian (Motorola, MM)
X Resolution                    : 144
Y Resolution                    : 144
Resolution Unit                 : inches
User Comment                    : Screenshot
Exif Image Width                : 594
Exif Image Height               : 1104
Pixels Per Unit X               : 5669
Pixels Per Unit Y               : 5669
Pixel Units                     : meters
XMP Toolkit                     : XMP Core 5.4.0
Apple Data Offsets              : (Binary data 28 bytes, use -b option to extract)
Warning                         : [minor] Trailer data after PNG IEND chunk
Image Size                      : 594x1104
Megapixels                      : 0.656
❯ binwalk dolls.jpg

/home/wizard/code/CSOC/CSOC_INFOSEC/WEEK_0x01/stenography/chall2/dolls.jpg
-------------------------------------------------------------------
DECIMAL                            HEXADECIMAL                        DESCRIPTION
-------------------------------------------------------------------
0                                  0x0                                PNG image, total size: 272492 bytes
272492                             0x4286C                            ZIP archive, file count: 1, total size: 379130 bytes
-------------------------------------------------------------------

Analyzed 1 file for 85 file signatures (187 magic patterns) in 7.0 milliseconds
❯ binwalk -e dolls.jpg

/home/wizard/code/CSOC/CSOC_INFOSEC/WEEK_0x01/stenography/chall2/extractions/dolls.jpg
-------------------------------------------------------------------
DECIMAL                            HEXADECIMAL                        DESCRIPTION
-------------------------------------------------------------------
0                                  0x0                                PNG image, total size: 272492 bytes
272492                             0x4286C                            ZIP archive, file count: 1, total size: 379130 bytes
-------------------------------------------------------------------
[#] Extraction of png data at offset 0x0 declined
[+] Extraction of zip data at offset 0x4286C completed successfully
-------------------------------------------------------------------

Analyzed 1 file for 85 file signatures (187 magic patterns) in 24.0 milliseconds
❯ cd extractions/dolls.jpg.extracted
❯ ls
 4286C
❯ cd 4286C/q
cd: no such file or directory: 4286C/q
❯ cd 4286C/
❯ ls
 base_images
❯ cd base_images
❯ lds
zsh: command not found: lds
warning: database file for 'warpdotdev' does not exist (use '-Fy' to download)
warning: database file for 'sublime-text' does not exist (use '-Fy' to download)
❯ ls
 2_c.jpg
❯ exiftool 2_c.jpg
ExifTool Version Number         : 13.25
File Name                       : 2_c.jpg
Directory                       : .
File Size                       : 384 kB
File Modification Date/Time     : 2021:03:16 05:53:04+05:30
File Access Date/Time           : 2025:06:14 22:15:55+05:30
File Inode Change Date/Time     : 2025:06:14 22:15:49+05:30
File Permissions                : -rw-r--r--
File Type                       : PNG
File Type Extension             : png
MIME Type                       : image/png
Image Width                     : 526
Image Height                    : 1106
Bit Depth                       : 8
Color Type                      : RGB with Alpha
Compression                     : Deflate/Inflate
Filter                          : Adaptive
Interlace                       : Noninterlaced
Profile Name                    : ICC Profile
Profile CMM Type                : Apple Computer Inc.
Profile Version                 : 2.1.0
Profile Class                   : Display Device Profile
Color Space Data                : RGB
Profile Connection Space        : XYZ
Profile Date Time               : 2020:06:09 12:08:45
Profile File Signature          : acsp
Primary Platform                : Apple Computer Inc.
CMM Flags                       : Not Embedded, Independent
Device Manufacturer             : Apple Computer Inc.
Device Model                    : 
Device Attributes               : Reflective, Glossy, Positive, Color
Rendering Intent                : Perceptual
Connection Space Illuminant     : 0.9642 1 0.82491
Profile Creator                 : Apple Computer Inc.
Profile ID                      : 0
Profile Description             : Display
Profile Description ML (hr-HR)  : LCD u boji
Profile Description ML (ko-KR)  : 컬러 LCD
Profile Description ML (nb-NO)  : Farge-LCD
Profile Description ML (hu-HU)  : Színes LCD
Profile Description ML (cs-CZ)  : Barevný LCD
Profile Description ML (da-DK)  : LCD-farveskærm
Profile Description ML (nl-NL)  : Kleuren-LCD
Profile Description ML (fi-FI)  : Väri-LCD
Profile Description ML (it-IT)  : LCD colori
Profile Description ML (es-ES)  : LCD color
Profile Description ML (ro-RO)  : LCD color
Profile Description ML (fr-CA)  : ACL couleur
Profile Description ML (uk-UA)  : Кольоровий LCD
Profile Description ML (he-IL)  : ‏LCD צבעוני
Profile Description ML (zh-TW)  : 彩色LCD
Profile Description ML (vi-VN)  : LCD Màu
Profile Description ML (sk-SK)  : Farebný LCD
Profile Description ML (zh-CN)  : 彩色LCD
Profile Description ML (ru-RU)  : Цветной ЖК-дисплей
Profile Description ML (en-GB)  : Colour LCD
Profile Description ML (fr-FR)  : LCD couleur
Profile Description ML (hi-IN)  : रंगीन LCD
Profile Description ML (th-TH)  : LCD สี
Profile Description ML (ca-ES)  : LCD en color
Profile Description ML (en-AU)  : Colour LCD
Profile Description ML (es-XL)  : LCD color
Profile Description ML (de-DE)  : Farb-LCD
Profile Description ML          : Color LCD
Profile Description ML (pt-BR)  : LCD Colorido
Profile Description ML (pl-PL)  : Kolor LCD
Profile Description ML (el-GR)  : Έγχρωμη οθόνη LCD
Profile Description ML (sv-SE)  : Färg-LCD
Profile Description ML (tr-TR)  : Renkli LCD
Profile Description ML (pt-PT)  : LCD a Cores
Profile Description ML (ja-JP)  : カラーLCD
Profile Copyright               : Copyright Apple Inc., 2020
Media White Point               : 0.94955 1 1.08902
Red Matrix Column               : 0.51099 0.23955 -0.00104
Green Matrix Column             : 0.29517 0.69981 0.04224
Blue Matrix Column              : 0.15805 0.06064 0.78369
Red Tone Reproduction Curve     : (Binary data 2060 bytes, use -b option to extract)
Video Card Gamma                : (Binary data 48 bytes, use -b option to extract)
Native Display Info             : (Binary data 62 bytes, use -b option to extract)
Chromatic Adaptation            : 1.04861 0.02332 -0.05034 0.03018 0.99002 -0.01714 -0.00922 0.01503 0.75172
Make And Model                  : (Binary data 40 bytes, use -b option to extract)
Blue Tone Reproduction Curve    : (Binary data 2060 bytes, use -b option to extract)
Green Tone Reproduction Curve   : (Binary data 2060 bytes, use -b option to extract)
Exif Byte Order                 : Big-endian (Motorola, MM)
X Resolution                    : 144
Y Resolution                    : 144
Resolution Unit                 : inches
User Comment                    : Screenshot
Exif Image Width                : 526
Exif Image Height               : 1106
Pixels Per Unit X               : 5669
Pixels Per Unit Y               : 5669
Pixel Units                     : meters
XMP Toolkit                     : XMP Core 5.4.0
Apple Data Offsets              : (Binary data 28 bytes, use -b option to extract)
Warning                         : [minor] Trailer data after PNG IEND chunk
Image Size                      : 526x1106
Megapixels                      : 0.582
❯ binwalk 2_c.jpg ]
error: unexpected argument ']' found

Usage: binwalk [OPTIONS] [FILE_NAME]

For more information, try '--help'.
❯ binwalk 2_c.jpg

/home/wizard/code/CSOC/CSOC_INFOSEC/WEEK_0x01/stenography/chall2/extractions/dolls.jpg.extracted/4286C/base_images/2_c.jpg
-------------------------------------------------------------------
DECIMAL                            HEXADECIMAL                        DESCRIPTION
-------------------------------------------------------------------
0                                  0x0                                PNG image, total size: 187707 bytes
187707                             0x2DD3B                            ZIP archive, file count: 1, total size: 196119 bytes
-------------------------------------------------------------------

Analyzed 1 file for 85 file signatures (187 magic patterns) in 5.0 milliseconds
❯ binwalk -e 2_c.jpg

/home/wizard/code/CSOC/CSOC_INFOSEC/WEEK_0x01/stenography/chall2/extractions/dolls.jpg.extracted/4286C/base_images/extractions/2_c.jpg
-------------------------------------------------------------------
DECIMAL                            HEXADECIMAL                        DESCRIPTION
-------------------------------------------------------------------
0                                  0x0                                PNG image, total size: 187707 bytes
187707                             0x2DD3B                            ZIP archive, file count: 1, total size: 196119 bytes
-------------------------------------------------------------------
[#] Extraction of png data at offset 0x0 declined
[+] Extraction of zip data at offset 0x2DD3B completed successfully
-------------------------------------------------------------------

Analyzed 1 file for 85 file signatures (187 magic patterns) in 21.0 milliseconds
❯ cd /home/wizard/code/CSOC/CSOC_INFOSEC/WEEK_0x01/stenography/chall2/extractions/dolls.jpg.extracted/4286C/base_images/extractions/2_c.jpg.extracted/2DD3B/base_images
❯ binwalk -e 3_c.jpg

/home/wizard/code/CSOC/CSOC_INFOSEC/WEEK_0x01/stenography/chall2/extractions/dolls.jpg.extracted/4286C/base_images/extractions/2_c.jpg.extracted/2DD3B/base_images/extractions/3_c.jpg
-------------------------------------------------------------------
DECIMAL                            HEXADECIMAL                        DESCRIPTION
-------------------------------------------------------------------
0                                  0x0                                PNG image, total size: 123606 bytes
123606                             0x1E2D6                            ZIP archive, file count: 1, total size: 77838 bytes
-------------------------------------------------------------------
[#] Extraction of png data at offset 0x0 declined
[+] Extraction of zip data at offset 0x1E2D6 completed successfully
-------------------------------------------------------------------

Analyzed 1 file for 85 file signatures (187 magic patterns) in 13.0 milliseconds
❯ /home/wizard/code/CSOC/CSOC_INFOSEC/WEEK_0x01/stenography/chall2/extractions/dolls.jpg.extracted/4286C/base_images/extractions/2_c.jpg.extracted/2DD3B/base_images/extractions/3_c.jpg.extracted/1E2D6/base_images/
❯ binwalk -e 4_c.jpg

/home/wizard/code/CSOC/CSOC_INFOSEC/WEEK_0x01/stenography/chall2/extractions/dolls.jpg.extracted/4286C/base_images/extractions/2_c.jpg.extracted/2DD3B/base_images/extractions/3_c.jpg.extracted/1E2D6/base_images/extractions/4_c.jpg
-------------------------------------------------------------------
DECIMAL                            HEXADECIMAL                        DESCRIPTION
-------------------------------------------------------------------
0                                  0x0                                PNG image, total size: 79578 bytes
79578                              0x136DA                            ZIP archive, file count: 1, total size: 228 bytes
-------------------------------------------------------------------
[#] Extraction of png data at offset 0x0 declined
[+] Extraction of zip data at offset 0x136DA completed successfully
-------------------------------------------------------------------

Analyzed 1 file for 85 file signatures (187 magic patterns) in 11.0 milliseconds
❯ cd extractions/4_c.jpg.extracted/136DA
❯ ls
 flag.txt
❯ cat flag.txt
picoCTF{4cf7ac000c3fb0fa96fb92722ffb2a32}
```
