#!/usr/bin/python3

id_pass_pairs = {
    200124 : 1234,
    200125 : 2321,
    200126 : 9090
}

class Employee:
    def __init__(self, id, password, name, department, salary, absence):
        self.id = id
        self.password = password
        self.name = name
        self.department = department
        self.salary = salary
        self.absence = absence

Employees = [
    Employee(200124, 1234, "Mohamed Nagy", "Sales", 500, 3),
    Employee(200125, 2321, "Cristiano Ronaldo", "Wing Left", 10000, 0),
    Employee(200126, 9090, "Emam Ashour", "Midfield", 2000, 5)
]

def add_employee():
    print("\n < Adding New Employee >\n")
    while True:
        id = int(input("\nEnter New Employee ID : "))
        
        if id in id_pass_pairs:
            print("\nPre-used ID, Please enter another one.")
            continue
        
        password = int(input("Enter New Employee Password : "))
        name = input("Enter New Employee Name : ")
        department = input("Enter New Employee Department : ")
        salary = int(input("Enter New Employee Salary : "))  # Use float for salary input
        absence = 0
        
        Employees.append(Employee(id, password, name, department, salary, absence))
        id_pass_pairs[id] = password
        
        break


def display_employees():
    print("\n < Displaying All Employee Information >\n")
    for emp in Employees:
        print(f"ID: {emp.id}, Name: {emp.name}, Department: {emp.department}")


def remove_employee():
    print("\n < Removing Employee Information >\n")

    while True:
        id = int(input("\nEnter Employee ID to remove: "))
        found = False
        
        for emp in Employees:
            if emp.id == id:
                Employees.remove(emp)
                found = True
                print(f"Employee with ID {id} removed successfully.")
                break
        
        if not found:
            print(f"Employee with ID {id} not found.")
        
        if found : break

