#/bin/bash
#rm -r $(find -name "*.class")
find -name "*.java" > paths.txt
javac -d "." @paths.txt

