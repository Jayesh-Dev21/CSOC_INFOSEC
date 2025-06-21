with open('output.txt', 'r') as file:
    encrypted_flag = file.read()

s = ""
c = ""

for i in range(0, len(encrypted_flag), 4):
    s += format(int(encrypted_flag[i:i+2],16), '02x') + format(int(encrypted_flag[i:i+2], 16) ^ int(encrypted_flag[i+2:i+4], 16), '02x')

flag = bytes.fromhex(s).decode()

with open('flag.txt', 'w') as f :
    f.write(flag)