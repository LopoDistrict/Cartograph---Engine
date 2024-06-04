import hashlib
import mysql.connector

"""
@author: Nashou
encrypte inventory for the first time
md5 encryption
"""

#initiating inventory


"""
line = inventory_file.readlines()
for i in range(len(line)):
    val = line[i].split(";")
"""

md5_hash = hashlib.md5()
md5_hash.update("3_woods; 1_rock".encode("utf-8"))
final_hash = md5_hash.hexdigest()
final_file = open("inventory.lhhdd", "a")
    
print(final_hash)
final_file.write(final_hash)
final_file.close()


final_file2 = open("skills.lhhdd", "r")
final_file2.close()

