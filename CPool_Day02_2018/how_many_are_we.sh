#!/bin/bash
# how_many_are_we.sh

if [ $# -eq 0 ]
then
    wc -l
else
    tr -d "tek" | grep ";$1" -ci
fi
