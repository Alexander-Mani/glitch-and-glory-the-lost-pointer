import sys

if len(sys.argv) != 3:
    print("Usage: python script.py <input_file> <output_file>")
    sys.exit(1)

input_file, output_file = sys.argv[1], sys.argv[2]

try:
    with open(input_file, "r") as infile, open(output_file, "w") as outfile:
        for line in infile:
            outfile.write(line[::-1])
        outfile.write("\n")
except FileNotFoundError:
    print(f"Error: File '{input_file}' not found.")
    sys.exit(1)
except Exception as e:
    print(f"An error occurred: {e}")
    sys.exit(1)

