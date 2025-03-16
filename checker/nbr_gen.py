import random

def generate_unique_numbers(x, y, z):
    if x > (z - y + 1):
        raise ValueError("Cannot generate more unique numbers than the range allows.")
    numbers = random.sample(range(y, z + 1), x)
    return " ".join(map(str, numbers))

# Get input from the user
try:
    x = int(input("Enter the number of unique numbers to generate (x): "))
    y = int(input("Enter the start of the range (y): "))
    z = int(input("Enter the end of the range (z): "))
    
    # Generate and print the unique numbers
    print(generate_unique_numbers(x, y, z))
except ValueError as e:
    print(f"Error: {e}")

