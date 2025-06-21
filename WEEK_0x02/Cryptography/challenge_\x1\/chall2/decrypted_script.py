with open('flag.txt', 'r') as f :
    flag = f.read()

s = ''.join(format(ord(i), '02x') for i in flag)
e = ""

for i in range(0,len(s),4) :
    e += format(int(s[i:i+2],16), '02x')+format(int(s[i:i+2],16)^int(s[i+2:i+4],16), '02x')

with open('output.txt', 'w') as f :
    f.write(e)