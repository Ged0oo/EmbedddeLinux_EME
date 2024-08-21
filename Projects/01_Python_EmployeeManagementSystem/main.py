#!/usr/bin/python3

import os
import authentication as auth
import employee_data as emp
import operations as opr

os.system('clear')

print("\n*****************************************")
print("Welcome to Employee Managment System")
print("Please Log in to Continue")
print("*****************************************\n")

count = 3
state = False

while count:
    id = int(input("Enter Your ID : "))
    password = int(input("Enter Your Password : "))
    state = auth.check_user(id, password)

    if state==False : 
        count-=1
        if count==0 : 
            print("\n*****************************************")
            print("Authontication Failed \n")
            print("*****************************************\n")
            exit(0)
        else :
            print("\nReenter Your Cidentiols")

    else :
        print("\nAuthontication Succesusfully")
        break


while True :
    print("\nSelect Option : ")
    print("\t1. Display Imployee Information.")
    print("\t2. Display Imployee Bonus.")
    print("\t3. Display Imployee Discount.")
    print("\t4. Display Imployee Holydays.")
    print("\t5. Display All Imployees.")
    print("\t6. Add Imployee.")
    print("\t7. Remove Imployee.")
    print("\t8. Exit.")

    option = int(input("\nEnter Your Choice : "))
    os.system('clear')

    if   option == 1 : opr.display_info(id)
    elif option == 2 : opr.calculate_bonus(id)
    elif option == 3 : opr.calculate_discount(id)
    elif option == 4 : opr.calculate_holydays(id)
    elif option == 5 : emp.display_employees()
    elif option == 6 : emp.add_employee()
    elif option == 7 : emp.remove_employee()
    elif option == 8 : break
    else : print("Wrong Choice !!")


