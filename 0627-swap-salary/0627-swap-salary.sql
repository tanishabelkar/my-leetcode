# Write your MySQL query statement below
update salary 
set sex = if (salary.sex = 'm', 'f', 'm')