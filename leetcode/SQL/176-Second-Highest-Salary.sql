-- Employee, Salary, SecondHighestSalary
SELECT max(Salary) AS SecondHighestSalary FROM Employee WHERE Salary < (SELECT max(Salary) FROM Employee);