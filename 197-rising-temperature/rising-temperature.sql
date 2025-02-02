# Write your MySQL query statement below
SELECT w1.id 
FROM weather as w1
JOIN  weather as w2
ON dateDiff(w1.recorddate, w2.recorddate) = 1 
WHERE w1.temperature > w2.temperature;
