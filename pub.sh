if [ "$1" == "" ] || [ "$2" == "" ]; then 
    echo "USAGE: ./pub.sh <file> <commit message>"
    exit 0
fi

git add $1
#echo "git commit -m \"$2\""
git commit -m \"$2\"
git push