#!/bin/sh
if which gecho 2>&1 >/dev/null; then
  ECHO=`which gecho`
else
  ECHO=`which echo`
fi

$ECHO ""
$ECHO -n "[SPArticle] Checking for $1..."
if which $1 2>&1 >/dev/null; then
  $ECHO -n "OK."
  exit 0
else
  echo "Error : Could not find $1."
  exit 1
fi
