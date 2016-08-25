#!/bin/bash
# 195. Tenth Line
# Read from the file file.txt and output the tenth line to stdout.
awk 'NR == 10' file.txt
