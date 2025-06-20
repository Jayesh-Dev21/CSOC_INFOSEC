import base64
import json
import codecs
import hashlib
import ast

# --- Simulated MD5 reverse dictionary ---
md5_lookup = {
    hashlib.md5("hello".encode()).hexdigest(): "hello",
    hashlib.md5("admin".encode()).hexdigest(): "admin",
    hashlib.md5("password".encode()).hexdigest(): "password",
    # Add more known hashes as needed
}

def load_config(config_b64: str):
    try:
        decoded = base64.b64decode(config_b64).decode('utf-8')
        config = json.loads(decoded)
        print("[*] Loaded Config:", config)
        return config
    except Exception as e:
        print("[!] Failed to parse base64 config:", e)
        exit(1)

def decode_string(data: str, method: str) -> str:
    method = method.strip().lower()
    try:
        if method == "base64":
            return base64.b64decode(data.encode()).decode()
        elif method == "base32":
            return base64.b32decode(data.encode()).decode()
        elif method == "base16":
            return base64.b16decode(data.encode()).decode()
        elif method == "hex":
            return bytes.fromhex(data).decode()
        elif method == "rot13":
            return codecs.decode(data, 'rot_13')
        elif method == "reverse":
            return data[::-1]
        elif method == "md5":
            if data in md5_lookup:
                return md5_lookup[data]
            else:
                raise ValueError(f"MD5 hash '{data}' not found in lookup table.")
        else:
            raise ValueError(f"Unsupported decoding method: {method}")
    except Exception as e:
        raise ValueError(f"[!] Error decoding with {method.upper()}: {e}")

def apply_decoding(encoded_string: str, steps: list):
    current = encoded_string
    for step in steps:
        print(f"\n[*] Decoding with: {step}")
        try:
            current = decode_string(current, step)
            print(f"[+] Intermediate Result: {current}")
        except Exception as err:
            print(err)
            exit(1)
    return current

def parse_to_dict(json_like_string: str) -> dict:
    s = json_like_string.replace('true', 'True').replace('false', 'False').replace('null', 'None')
    try:
        return ast.literal_eval(s)
    except Exception as e:
        print("[!] Failed to parse final string to dictionary:", e)
        exit(1)

# === Main Execution ===

# Step 1: Load and parse config
config_b64 = input("Enter the first step (base64-encoded config): ").strip()
config = load_config(config_b64)

# Step 2: Get decoding steps and reverse them
decode_steps = config.get("cookie_encoding_methods", [])[::-1]

# Step 3: Input the encoded string
encoded_string = input("\nEnter the encoded string: ").strip()

# Step 4: Decode step-by-step
final_result = apply_decoding(encoded_string, decode_steps)

# Step 5: Parse final result into dictionary
data = parse_to_dict(final_result)

# Step 6: Output password
print("\nFinal Decoded String:\n", final_result)
print("\nExtracted Password:\n", data.get("password"))
