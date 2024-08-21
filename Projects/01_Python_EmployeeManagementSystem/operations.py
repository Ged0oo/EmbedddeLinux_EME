#!/usr/bin/python3

from employee_data import Employees

def display_info(id) :
    print("\n < Display Employee Information >\n")
    for emp in Employees :
        if emp.id == id :
            print("\n*****************************************")
            print(f"ID : {emp.id}")
            print(f"Name : {emp.name}")
            print(f"Departement : {emp.department}")
            print(f"Salary : {emp.salary}")
            print(f"Absense Days : {emp.absence}")
            print("*****************************************\n")

def calculate_bonus(id) :
    print("\n < Display Employee Bonus >\n")
    for emp in Employees :
        if emp.id == id :
            bonus = emp.salary * 0.1
            print(f"Your bonus : {bonus}$")


def calculate_discount(id) :
    print("\n < Display Employee Discount >\n")
    for emp in Employees :
        if emp.id == id :
            dis = emp.salary * 0.05
            print(f"Your Discount : {dis}$")


def calculate_holydays(id) :
    print("\n < Display Employee Holydays >\n")
    for emp in Employees :
        if emp.id == id :
            holydays = 7 - emp.absence
            print(f"Your Available Holydays : {holydays}")