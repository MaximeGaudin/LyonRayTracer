#!/bin/sh
if which gecho 2>&1 >/dev/null; then
  ECHO=`which gecho`
else
  ECHO=`which echo`
fi

$ECHO ""
$ECHO -n "[SPArticle] Checking for $1..."

if which kpsewhich 2>&1 >/dev/null; then
  KPSEWHICH=`which kpsewhich`
  until [ -z "$1" ]  
  do
    if [[ `$KPSEWHICH $1.sty` == "" ]]; then
      $ECHO -n "Not found."
      exit 1
    else
      $ECHO -n "OK."
    fi
    shift
  done
else
  echo "Error : Could not find kpsewhich utility."
  exit 2
fi
exit 0
