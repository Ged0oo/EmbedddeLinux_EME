###
Main Functionalities
###

##
1. Storing Employee Details:

   - ID (Unique): A unique identifier for each employee.

   - Name: The full name of the employee.

   - Department: The department in which the employee works.

   - Salary: The salary of the employee.

   - Password: Used for user authentication.

   - Days of Absence: The number of days the employee has been absent.
##

##
2. User Authentication:

   - Implement a login system where users authenticate themselves using a password.

   - Allow a maximum of three login attempts before denying access.
##

##
3. User Operations:

   - Display All Info: Show all information about an employee.

   - Calculate Bonus: Calculate and display a bonus based on the employee's salary.

   - Calculate Discount: Calculate and display a discount based on the employee's salary.

   - Remind Legal Holidays: Display the number of remaining legal holidays for the employee.
##

###
Project Implementation Steps
###

##
1. Setup and Initialization:

   - Initialize the project by creating a directory structure and necessary files.

   - Use a list to store employee details, where each employee is represented as a dictionary or tuple.
##

##
2. Employee Data Management:

   - Create functions to add, remove, and update employee details.

   - Ensure the employee ID is unique for each entry.
##

##
3. User Authentication:

   - Implement a function to authenticate users by comparing input passwords with stored passwords.

   - Allow a maximum of three attempts before denying access.
##

##
4. Operations on Employee Data:

   - Display Info: Create a function to display all information about an employee when provided with their ID.

   - Calculate Bonus: Implement a function to calculate a bonus, e.g., 10% of the salary.

   - Calculate Discount: Implement a function to calculate a discount, e.g., 5% of the salary.

   - Remind Legal Holidays: Implement a function to display remaining legal holidays for an employee.
##

##
5. Modularize the Code:

   - Separate different functionalities into modules:

    - employee_data.py : Functions to manage employee data.

    - authentication.py : Functions for user authentication.

    - operations.py : Functions for bonus calculation, discount, and holiday reminders.

    - main.py : Main script to run the CLI or GUI.
##