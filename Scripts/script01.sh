#!/bin/bash

# This script  take as arguments the “root name” of the
# executable(s) to build and a list of strictly positive integers.
# ./script01.sh prog01 arg1 arg2 arg3 ...
max=0
# loop arguments from the second (the one after the name of the built program) onward
# max takes the value of the maximum argument
for((i=2;i<=$#;i++)) 
do
    if ((${!i}>$max))
    then 
        max=${!i}
    fi
done

# if max value hasn't changed and is still 0, run the built program without any argument
if(($max!=0))
then
    "./$1v1" $max; echo \ ;
else
    "./$1v1"; echo \ ;
fi

# iterate through the arguments except the first 1 (name of the built program)
uniques=( )
for((i=2;i<=$#;i++)) 
do
    repeated=false
    # for every previous unique arguments already iterated through make sure the current argument is not a repetition
    # set repeated to true and exit the loop for any repeated argument
    for element in ${uniques[@]}
    do
        if (($element==${!i})) 
        then 
            repeated=true
            break
        fi
    done

    # if argument was already seen skip this iteration and go to the next
    if $repeated 
    then 
        continue 
    else 
        uniques[${#uniques[@]}]=${!i}
    fi

    used=( )
    # iterates through following arguments
    for((j=$i+1;j<=$#;j++))
    do
        already=false
        # for every previous unique arguments already iterated through make sure the current argument is not a repetition
        # set already to true and exit the loop for any repeated argument
        for combinedto in "${used[@]}"
        do
            if (($combinedto==${!j})) 
            then 
                already=true
                break
            fi
        done

        # if argument was already seen skip this iteration and go to the next
        if $already 
        then
            continue 
        else 
            used[${#used[@]}]=${!j}
        fi

        # if index i and j are different execute the program
        if (($i!=$j)) 
        then
            "./$1v2" ${!i} ${!j}; echo \ ;
        fi
    done
done