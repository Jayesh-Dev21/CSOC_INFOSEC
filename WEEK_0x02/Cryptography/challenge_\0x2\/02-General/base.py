st = "72bca9b68fc16ac7beeb8f849dca1d8a783e8acf9679bf9269f7bf"

import base64

sst = bytes.fromhex(st)


sst = base64.b64encode(sst).decode()

print(sst)
