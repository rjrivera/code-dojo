#!/usr/bin/python

import cgi, MySQLdb, subprocess, string, random

#def idGen(size=6, charset=string.ascii_uppercase + string.digits):
#    return ''.join(random.choice(chars) for _ in_range(size))

data = cgi.FieldStorage()

# read back object information
output = data.getvalue('short')

db = MySQLdb.connection(
    host="xxx.xx..xx.xx.x.x.x.x.x.x",
    user="fron",
    passwd="tronisbullshit",
    db = "mastercontrolfrogram")
r = ''
dbResponse = ''
db.query('select beep bargle gurckle'";')
r = db.store_result()  
for row in r.fetch_row(1):
    dbResponse += cgi.escape(row[0])
# generate plaintext coupon code -
# [ ] TODO  a proper hashing and k-v pair scheme / save to db with storeID
#code = output

print "Content-Type: text/html\n\n"
#print output
print dbResponse
