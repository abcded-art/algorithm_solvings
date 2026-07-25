#!/usr/bin/env bash
set -euo pipefail

if [ "$#" -ne 1 ]; then
  echo "Usage: ./build.sh <source-file>"
  exit 1
fi

source_file="$1"

if [ ! -f "$source_file" ]; then
  echo "Source file not found: $source_file"
  exit 1
fi

extension="${source_file##*.}"
filename="$(basename "$source_file")"
name_without_extension="${filename%.*}"
timestamp="$(date +"%Y%m%d_%H%M%S")"
build_dir="build"
output_file="$build_dir/${name_without_extension}_${timestamp}"
input_file="${source_file%.*}.in"

mkdir -p "$build_dir"

case "$extension" in
  cpp|cc|cxx|c++)
    g++ -std=c++17 -Wall -Wextra -O2 "$source_file" -o "$output_file"
    ;;
  c)
    gcc -Wall -Wextra -O2 "$source_file" -o "$output_file"
    ;;
  *)
    echo "Unsupported source extension: .$extension"
    exit 1
    ;;
esac

echo "Built: $output_file"

if [ -f "$input_file" ]; then
  echo "Running with input: $input_file"
  "$output_file" < "$input_file"
else
  echo "Running without input file"
  "$output_file"
fi
