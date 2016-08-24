#!/usr/bin/python

import cgi, MySQLdb, subprocess

data = cgi.FieldStorage()

# read back object information
output = data.getvalue('amt')
discType = data.getvalue('type')
minPurch = data.getvalue('minPurch')
storeID = data.getvalue('storeID')

# generate plaintext coupon code -
# [ ] TODO  a proper hashing and k-v pair scheme / save to db with storeID
code = (int(discType)*10000000) + (int(output) * 10000) + (int(minPurch))

print "Content-Type: text/html\n\n"
print output
print "\n discount type is: " 
print discType
print "\n min Purchase for discount is: " 
print minPurch
print "\n plaintext coupon code is: "
print code
print "\n storeID coupon code is for: " 
print storeID

