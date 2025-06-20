import sys
import pyfiglet


def print_banner(text):
    banner = pyfiglet.figlet_format(text)
    print("---------------------------------------------------------------------")
    print(banner)
    print("---------------------------------------------------------------------")