##implement an algorithm to reverse a string
import math 
print("welcome to string reverser 5000.")
reverse = True
continueReverse = True
index = 0
while(reverse):
    while(continueReverse):
        newString=""
        testString =raw_input('Please provide a string to reverse: ')
        index = len(testString)
        for x in range(len(testString)):
            newString+=testString[index-1]
            print("appending character:  " + str(testString[index-1]))
            index-=1
        print(testString + " reversed is: " + newString)
        continueReverse = False
    continueReverse = raw_input('would you like to continue analyzing? (Y/N)')
    if continueReverse == 'Y':
        continueReverse = True
    elif continueReverse == 'N':
        reverse = False
    else:
        print('invalid data please reenter')
        continueReverse = False



