# Write your MySQL query statement below
select id from Weather as cur where Temperature > (select Temperature from Weather as yest where timestampdiff(DAY, yest.recordDate, cur.recordDate) = 1);
