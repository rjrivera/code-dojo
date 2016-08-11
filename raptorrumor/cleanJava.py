import csv, glob, os, argparse, string

# updateJava.py reads outstanding requested java files and cleanses of '\n' artifacts from the MySQL db. 

parser = argparse.ArgumentParser(description='cleanse requested java files')
parser.add_argument('strings', metavar='N', type=str, nargs='+', help='a file for the program')
args = parser.parse_args()
print(args.strings)

path = "/home/ubuntu"
print "Current path directory %s" % path
#fileCandidateInfo = ["0","0","0","0","0","0", "0", "0","0","0","0","0","0"]
os.chdir(path)

for file in args.strings:
    fpath = path + '/' + file
    print("doing stuff in file: " + file)
    try:
        myFile = open(fpath).read()
    except:
        print("Sorry, cannot find file" + fpath)
    try:
        myFile = string.replace(myFile, r"\n", " ")
        myFile = string.replace(myFile, "javatext", " ", 1)
        print(myFile)
    except:
        print("sorry, " + file + " couldn't replace the strings.")
   
    try:
        with open(fpath, 'w') as javafile:
            javafile.write(myFile)
        print("Successfully rewrote java file " + file + "to exclude unwanted regex expressions")
    except:
        print("failed to write to file")
"""	    spamwriter = csv.writer(csvfile, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
	    spamwriter.writerow([fileCandidateInfo[0]] + [fileCandidateInfo[1]] + [fileCandidateInfo[2]] + [fileCandidateInfo[3]] + [fileCandidateInfo[4]] + [fileCandidateInfo[5]] + [fileCandidateInfo[6]] + [fileCandidateInfo[7]] + [fileCandidateInfo[8]] + [fileCandidateInfo[9]] + [fileCandidateInfo[10]] + [fileCandidateInfo[11]])
"""
