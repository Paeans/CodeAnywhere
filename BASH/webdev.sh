#!/bin/bash

[ -f .devcounter ] && read -a counter < .devcounter || counter='1' 
while [ 1 -eq 1 ]
do
    echo ********THE ${counter}th UPDATE********    
    sudo ./google_appengine/appcfg.py update app4webdev/
    echo ************UPDATE COMPLETE************
    
    counter=$((counter + 1))
    echo $counter > .devcounter
    
    read -n 1    
    clear
done
