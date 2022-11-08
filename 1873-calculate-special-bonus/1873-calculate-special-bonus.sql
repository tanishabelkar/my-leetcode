# Write your MySQL query statement below
select employee_id, if (employee_id %2 != 0 and name not regexp '^M', E.salary, 0) as bonus
from Employees E
order by employee_id