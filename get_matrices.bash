#!/bin/bash

awk '/Rank 0 array start/{f=1;next}; /Rank 0 array end/{f=0} f' $1 > M1.txt
awk '/Rank 1 array start/{f=1;next}; /Rank 1 array end/{f=0} f' $1 > M2.txt
awk '/Rank 2 array start/{f=1;next}; /Rank 2 array end/{f=0} f' $1 > M3.txt
awk '/Rank 3 array start/{f=1;next}; /Rank 3 array end/{f=0} f' $1 > M4.txt

grep "Time" $1 > times.txt
