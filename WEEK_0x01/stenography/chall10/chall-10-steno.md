# extentions

I ran 

```bash

❯ file flag.txt
flag.txt: PNG image data, 1697 x 608, 8-bit/color RGB, non-interlaced
❯ exiftool flag.txt
ExifTool Version Number         : 13.25
File Name                       : flag.txt
Directory                       : .
File Size                       : 10.0 kB
File Modification Date/Time     : 2020:10:27 00:00:20+05:30
File Access Date/Time           : 2025:06:20 10:39:02+05:30
File Inode Change Date/Time     : 2025:06:20 10:38:55+05:30
File Permissions                : -rw-r--r--
File Type                       : PNG
File Type Extension             : png
MIME Type                       : image/png
Image Width                     : 1697
Image Height                    : 608
Bit Depth                       : 8
Color Type                      : RGB
Compression                     : Deflate/Inflate
Filter                          : Adaptive
Interlace                       : Noninterlaced
SRGB Rendering                  : Perceptual
Gamma                           : 2.2
Pixels Per Unit X               : 5669
Pixels Per Unit Y               : 5669
Pixel Units                     : meters
Image Size                      : 1697x608
Megapixels                      : 1.0
```

and did

```bash
mv flag.txt flag.png
```


and viewed the img

![img](./flag.png)

flag    -  picoCTF{now_you_know_about_extensions}