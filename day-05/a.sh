#!/bin/bash

echo $((2#$(sed -E 's/B|R/1/g;s/F|L/0/g' input.txt|sort|tail -1)))
