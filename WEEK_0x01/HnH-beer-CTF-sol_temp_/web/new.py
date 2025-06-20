import hashlib

target_hash = input("Enter target hash: ")
epoch = input("enter epoch ")


rockyou_path = "./rockyou.txt"

try:
    with open(rockyou_path, "r", encoding="latin1") as file:
        for line in file:
            password = line.strip()
            candidate = password + epoch
            hashed = hashlib.sha256(candidate.encode()).hexdigest()
            
            if hashed == target_hash:
                print(f"\nPassword found: {password}")
                break
        else:
            print("\nNo match found in rockyou.txt.")
except FileNotFoundError:
    print(f"[!] Could not find rockyou.txt at: {rockyou_path}")
