##implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?
import math 
print("welcome to string analyzer 5000. We will determine if a string contains any characters more than once.")
analyze = True
continueAnal = True
unique = True
x = 0
while(analyze):
    while(continueAnal):
        testString =raw_input('Please provide a string to analyze: ')
        
        for x in range(len(testString)):
            if testString[x] in testString[:x]+testString[x+1:]: 
                unique = False
            print("reviewing character: " + str(testString[x]))
            x = x+1
        if unique:
            print("Your string has all unique characters")
            continueAnal=False
        else:
            print("Your string repeats a character somewhere")
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





