mysql --user=root --password=aa --database=robsrants --execute="SELECT javatext FROM testJAVACtable where id=1;" > helloWorld.java
python cleanJava.py helloWorld.java
javac helloWorld.java
var=$(java helloWorld)
echo $var
mysql --user=root --password=aa --database=robsrants --execute="UPDATE testJAVACtable SET recentOutput = '$var' where id=1;"


