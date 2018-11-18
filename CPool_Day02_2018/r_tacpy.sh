#!/bin/bash
# r_tacpy.sh

sed -n "2~2p" | cut -d\: -f 1 | rev | sort -r | head -n "$MY_LINE2" | tail -n $(($MY_LINE2-$MY_LINE1+1)) | sort -r | tr '\n' ',' | sed -r 's/,/, /g' | sed --regexp-extended "s/, $/\.\n/g"
