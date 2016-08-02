fileID=$1
fileName=$2
fileNameOnly=$3
mysql --user=root --password=aa --database=robsrants --execute="SELECT javatext FROM testJAVACtable where id='$fileID';" > $fileName
python cleanJava.py $fileName
javac $fileName
var=$(java $fileNameOnly)
echo $var
mysql --user=root --password=aa --database=robsrants --execute="UPDATE testJAVACtable SET recentOutput = '$var' where id=2;"


