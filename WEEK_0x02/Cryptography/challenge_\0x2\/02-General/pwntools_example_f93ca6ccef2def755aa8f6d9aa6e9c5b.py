from pwn import * # pip install pwntools
import socket
import json
import base64
import codecs

r = remote('socket.cryptohack.org', 13377, level = 'debug')

def json_recv():
    line = r.recvline()
    return json.loads(line.decode())

def json_send(hsh):
    request = json.dumps(hsh).encode()
    r.sendline(request)

def decode(encoded_type, encoded_data):
    if encoded_type == "base64":
        return base64.b64decode(encoded_data).decode()
    elif encoded_type == "hex":
        return bytes.fromhex(encoded_data).decode()
    elif encoded_type == "rot13":
        return codecs.decode(encoded_data, 'rot_13')
    elif encoded_type == "bigint":
        n = int(encoded_data, 16)
        return n.to_bytes((n.bit_length() + 7) // 8, 'big').decode()
    elif encoded_type == "utf-8":
        return ''.join([chr(b) for b in encoded_data])
    else:
        raise ValueError(f"Unsupported encoding type: {encoded_type}")


for i in range(100):
    received = json_recv()

    # print("Received type: ")
    # print(received["type"])
    # print("Received encoded value: ")
    # print(received["encoded"])
    decoded = decode(received["type"], received["encoded"])
    # print(decoded)
    # to_send = {
    #     "decoded": "changeme"
    # }

    to_send = {"decoded": decoded}

    


    json_send(to_send)

print(json_recv())