#!/bin/sh
if which gecho 2>&1 >/dev/null; then
  ECHO=`which gecho`
else
  ECHO=`which echo`
fi

$ECHO ""
$ECHO -n "[SPArticle] $1"
