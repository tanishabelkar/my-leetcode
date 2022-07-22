# Write your MySQL query statement below
select Distinct(email) from Person P where (select count(email) from Person P2 where P2.email = P.email) > 1;