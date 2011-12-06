#!/bin/sh
MIRROR="ftp://ctan.mirror.rafal.ca/CTAN/"

if which gsed 2>&1 >/dev/null; then
  SED=`which gsed`
else
  SED=`which sed`
fi

URL=`grep "$1.zip" filelist.txt | grep "contrib" | $SED 's/^.* //g'`

wget $MIRROR$URL -O package.zip
unzip -o package.zip

if [[ -e $1/$1.ins ]]; then
  cd $1/
  latex $1.ins >/dev/null
  cd ../
fi

cp $1/*.sty . && rm -r $1

rm package.zip
