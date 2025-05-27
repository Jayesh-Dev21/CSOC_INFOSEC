import sys
import pyfiglet

if len(sys.argv) < 2:
    print("Usage: banner.py 'Your Text Here'")
else:
    text = " ".join(sys.argv[1:])
    print(pyfiglet.figlet_format(text))