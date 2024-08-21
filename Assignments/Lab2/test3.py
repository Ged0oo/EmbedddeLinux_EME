#1/usr/bin
import calendar

year  = int(input("Enter the Year  : "))
month = int(input("Enter the Month : "))

cal = calendar.TextCalendar()
print(cal.formatmonth(year, month))