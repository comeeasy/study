#!/bin/sh

myvar="Joono"

echo $myvar
echo "$myvar"
echo '$myvar'
echo \$myvar
echo "값 입력: "
read myvar
echo '$myvar' = $myvar
exit 0

