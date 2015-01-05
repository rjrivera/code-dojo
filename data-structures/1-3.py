##implement an algorithm to remove duplicate letters from a string without using an additional string object
import math 
print("welcome to string analyzer 5000. We will determine if a string contains any characters more than once.")
analyze = True
continueAnal = True
unique = True
indexList = []
x = 0
while(analyze):
    while(continueAnal):
        testString =raw_input('Please provide a string to analyze: ')
        indexList = []
        for x in range(len(testString)):
            print("reviewing character: " + str(testString[x]))
            if testString[x] in testString[:x]+testString[x+1:]: 
                print("duplicate character detected")
                indexList.append(x)
                unique = False
        indexHelper = 0
        for x in range(len(indexList)):
            ##remove item
            testString = testString[:indexList[x]-int(indexHelper)] + testString[indexList[x]+1-int(indexHelper):]
            indexHelper = indexHelper + 1
        if unique:
            print("Your string has all unique characters")
            continueAnal=False
        else:
            print("Your new string is: " + testString)
            continueAnal=False
    continueAnalysis = raw_input('would you like to continue analyzing? (Y/N)')
    if continueAnalysis == 'Y':
        continueAnal = True
        unique = True
    elif continueAnalysis == 'N':
        analyze = False
    else:
        print('invalid data please reenter')
        continueAnal = False





