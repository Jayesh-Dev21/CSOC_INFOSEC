# MSB

I tired LSB tool online but found nothing 

LSB{least significant bit}
MSB{most significant bit}

while searching for an online msb tool I found a github repo

[Link](https://github.com/Pulho/sigBits) which had a python script that used pillow to find lsb and msb so I cloned it

usage example
```

  python sigBits.py -t=lsb -o=rgb -out=MyOutputFile -e=row MyInputFile.png
  python sigBits.py -t=LSB -o=BGR -e=column SomeImage.jpg
  python sigBits.py --type=Msb --order=GBR --extract=CoLuMn AnotherImage.png
```

I loaded my virtual environment which has all ctf tools and python modules for CTF and 

ran the script

```bash
❯ python3 sigBits/sigBits.py -t=lsb -o=rgb -out=lsb.txt Ninja-and-Prince-Genji-Ukiyoe-Utagawa-Kunisada.flag.png
Done, check the output file!
❯ python3 sigBits/sigBits.py -t=msb -o=rgb -out=msb Ninja-and-Prince-Genji-Ukiyoe-Utagawa-Kunisada.flag.png
Done, check the output file!

❯ ls
 chall-9-steno.md
 lsb.txt.txt
 msb.txt
 Ninja-and-Prince-Genji-Ukiyoe-Utagawa-Kunisada.flag.png
 sigBits
```

and the flag

```bash
❯ cat lsb.txt | tr " " "\n" | grep "picoCTF{"
❯ cat msb.txt | tr " " "\n" | grep "picoCTF{"
offence."picoCTF{15_y0ur_que57_qu1x071c_0r_h3r01c_3a219174}"Thou

❯ cat msb.txt | tr " " "\n" | grep "picoCTF{" | cut -d '"' -f2
picoCTF{15_y0ur_que57_qu1x071c_0r_h3r01c_3a219174}
```

flag     -    picoCTF{15_y0ur_que57_qu1x071c_0r_h3r01c_3a219174}