#!/bin/bash

for i in $(sed -E 's/B|R/1/g;s/F|L/0/g' input.txt|sort);{ [[ $[$p+2] == $[2#$i] ]] && echo $[$p+1]; p=$[2#$i];}
