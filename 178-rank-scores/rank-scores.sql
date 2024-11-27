# Write your MySQL query statement below
SELECT s.score, DENSE_RANK() over (order by score DESC) as 'rank' 
FROM Scores as s
ORDER BY score DESC;