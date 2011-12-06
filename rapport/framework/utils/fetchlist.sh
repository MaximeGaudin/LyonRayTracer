#!/bin/sh
MIRROR="ftp://ctan.mirror.rafal.ca/CTAN/"
FILE_LIST="FILES.byname"

if [[ ! -f filelist.txt ]]; then
  wget $MIRROR$FILE_LIST -O filelist.txt
fi
