#!/bin/bash

## gen $2 or 100 Random between 0 ~ 1
#  result store in file $1

[[ $1 == "" ]] && file="data.txt" || file=$1
[[ $2 == "" ]] && num=100 || num=$2

for i in `seq $num`
do
  #for j in `seq $(( $num * $num ))`
  for j in `seq $num`
  do
    [[ $(( $RANDOM % 10 )) > 4 ]] && tag="+" || tag="-"
    echo -n -e ${tag}0.$(( ${RANDOM} % 1000 ))\\t >> $file
    #[[ $(( $i % $num)) == 0 ]] && echo >> $file
  done
  echo >> $file
done

