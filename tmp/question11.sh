#!usr/bin/env sh
echo "home is : $HOME"
echo "path is : $PATH"
if [ $# = 1 ]
then
    if [ -d $1 ]
    then
        echo "$1 is a directory"
    else
        if [ -f $1 ]
        then
            echo "$1 is a regular file"
        else
            echo "$1 is a unkown file"
        fi
    fi

    if [ -r $1 ]
    then
        echo "$1 has read permission"
    fi

    if [ -w $1 ]
    then
        echo "$1 has write permission"
    fi

    if [ -x $1 ]
    then
        echo "Code has execute permission"
    fi
else
    echo "Invalid Argument!"
fi
