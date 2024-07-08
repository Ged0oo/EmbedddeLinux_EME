#!/usr/bin/python3

dct = {
    "name"      :   "Mohamed Nagy",
    "age"       :   23,
    "major"     :   "Electronics and Communication" ,
    "Interests" :   ["Python", "Embedded Linux"]
}

x = "Mohamed Nagy"
op = f"My name is \"{dct['name']}\", {dct['major']} Engineering \nI'm {dct['age']}, so I'm not Graduated yet. \nI'm Intersestd in : \n\t{dct['Interests'][0]} \n\t{dct['Interests'][1]}"

print(op)