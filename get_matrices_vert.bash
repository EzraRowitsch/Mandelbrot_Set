#!/bin/bash

awk '/Rank 0 array start/{f=1;next}; /Rank 0 array end/{f=0} f' $1 > M1_vert.txt
awk '/Rank 1 array start/{f=1;next}; /Rank 1 array end/{f=0} f' $1 > M2_vert.txt

grep "Time" $1 > Times_vert.txt
