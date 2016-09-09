#!/usr/bin/python

import cgi, MySQLdb, subprocess, string, random

#def idGen(size=6, charset=string.ascii_uppercase + string.digits):
#    return ''.join(random.choice(chars) for _ in_range(size))

data = cgi.FieldStorage()

# read back object information
output = data.getvalue('url')

db = MySQLdb.connection(
    host="xxx.xxx.xx.xx",
    user="user",
    passwd="zehpasswerd",
    db = "xxxxxxxx")
r = ''
dbResponse = ''
code = ''
charset = string.ascii_uppercase + string.digits 
duplicate = True
while duplicate:
    for i in range(0,5):
        code += random.choice(list(charset))
   
    dbResponse = ''
    db.query('select id from url_shortener where short_url="' + code + '";')
    r = db.store_result()  
    for row in r.fetch_row(1):
        dbResponse += cgi.escape(row[0])
    if not dbResponse:
        duplicate = False
    #duplicate = False
db.query('insert into url_shortener (url, short_url) values ("' + output + '", "' + code + '");')
code = 'http://www.raptorrumor.com/s/' + code
# generate plaintext coupon code -
# [ ] TODO  a proper hashing and k-v pair scheme / save to db with storeID
#code = output

print "Content-Type: text/html\n\n"
print output
print "\n YOUR SHORT URL:\n"
print code
print "\n"
