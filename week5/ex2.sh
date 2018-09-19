#!/bin/bash

for i in {0..99}
    do
        if ! ln ex2.txt ex2.txt.lock 
		then
				sleep 15
        else
			count=$(tail -n 1 "ex2.txt")
            echo "$(($count + 1))" >> "ex2.txt"
            rm "ex2.txt.lock"
            break
        fi
    done
done	