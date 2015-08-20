#!/bin/bash

[[ $1 == "" ]] && msg="Update" || msg=$1
cd $HOME/workspace/CodeAnywhere
remotelist="origin bucket"

for remote in $remotelist
do
    git pull $remote master
    [[ $? == 0 ]] || (
        echo "ERROR between local and $remote"
        echo "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
        echo 
        exit 1
    )
    echo "**************************************"
    echo 
done

git add -A
git commit -m "${msg}" && (
echo 
for remote in $remotelist
do
    git push $remote master
    echo
done ) || echo 
