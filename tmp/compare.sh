read -p "Please enter a filename: " filename
if [ -d Code ]
then
    echo "Code is a directory"
else
    echo "Code is not a directory"
fi

if [ -f compare.sh ]
then
    echo "compare.sh is a regular file"
else
    echo "compare.sh is not a regular file"
fi

if [ -r compare.sh ]
then
    echo "compare.sh has read permission"
else
    echo "compare.sh does not have read permission"
fi

if [ -w compare.sh ]
then
    echo "compare.sh has write permission"
else
    echo "compare.sh does not have write permission"
fi

if [ -x cppdir ]
then    echo "cppdir has execute permission"
else
    echo "cppdir does not have execute permission"
fi
