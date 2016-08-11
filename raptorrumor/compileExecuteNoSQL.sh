fileID=$1
fileName=$2
fileNameOnly=$3
fileText=$4
#mysql --user=root --password=aa --database=robsrants --execute="SELECT javatext FROM testJAVACtable where id='$fileID';" > $fileName
echo $fileText > $fileName
python cleanJava.py $fileName
javac $fileName
java $fileNameOnly > output.txt
var=$(java $fileNameOnly)
echo $var

#mysql --user=root --password=aa --database=robsrants --execute="UPDATE testJAVACtable SET recentOutput = '$var' where id=2;"


