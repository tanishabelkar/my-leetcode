# Write your MySQL query statement below
select id from Weather W
where (select temperature from Weather where datediff(W.recordDate, recordDate)=1) < W.temperature
