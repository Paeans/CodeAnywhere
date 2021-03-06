#!/bin/bash

cppfilelist=""
mainfilelist=""
for filename in $( ls *.cpp 2> /dev/null )
do
   #if ! grep "int main()" ${filename} 2>&1 > /dev/null
    if [[ $( grep "int main\(\)" ${filename} 2> /dev/null ) == "" ]]
    then
        cppfilelist+=${filename}" "
    else
        [[ $1 == "" || $1 == ${filename%.cpp} ]] && mainfilelist+=${filename}" "
    fi 
done
[[  ${mainfilelist} == "" ]] && echo "No main file found" && exit 1

for mainfile in ${mainfilelist}
do
    mainname=${mainfile%.cpp}
    echo "Compile" ${mainfile};
    g++ -std=c++11 -o ${mainname}.out ${mainfile} ${cppfilelist} && (     
            echo "Excute"  ${mainname}.out; 
            echo "**************************************";
            ./${mainname}.out;
            echo "**************************************" )    
    echo
done

## NOTE
# ${MYVAR#pattern}       # delete shortest match of pattern from the beginning
# ${MYVAR##pattern}      # delete longest match of pattern from the beginning
# ${MYVAR%pattern}       # delete shortest match of pattern from the end
# ${MYVAR%%pattern}      # delete longest match of pattern from the end

# 