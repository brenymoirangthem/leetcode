# Write your MySQL query statement below
select name ,bonus from Employee Left join Bonus on Employee.empid = Bonus.empid where bonus < 1000 Or bonus is null;