#!/bin/bash

# Create data directory if it doesn't exist
mkdir -p ./data

# Find the next available file name
index=1
while [[ -e "./data/all_files_${index}.txt" ]]; do
    ((index++))
done
output_file="./data/all_files_${index}.txt"

# Search for Makefile, .cpp, .h, and .md files and store their contents
echo "Saving files to $output_file"

find . \( -name "Makefile" -o -name "*.cpp" -o -name "*.h" -o -name "*.md" \) -print0 | while IFS= read -r -d '' file; do
    echo "========= $file =========" >> "$output_file"
    cat "$file" >> "$output_file"
    echo -e "\n" >> "$output_file"
done

# Save directory structure using tree command (if available)
echo "========= Directory Structure =========" >> "$output_file"
command -v tree >/dev/null && tree >> "$output_file" 2>/dev/null || echo "tree command not found" >> "$output_file"

echo "Done!"
