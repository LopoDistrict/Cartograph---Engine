with open("loc_entity.txt", "r") as file_entity:
     first = file_entity.readline().strip('\n')
     l = [i for i in first.split(";")]

     print(l)
