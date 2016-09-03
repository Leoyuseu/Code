#encoding=UTF-8
import MySQLdb
db = MySQLdb.connect("localhost","root","920520","world",charset="utf8" )
cursor = db.cursor()
cursor.execute("select * from world.city")
#cursor.execute("SET NAMES utf8")
data = cursor.fetchone()
while data!=None:
    print data[1]
    data = cursor.fetchone()
db.close
