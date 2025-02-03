# Write your MySQL query statement below
SELECT name 
FROM employee as e
WHERE id in (
    SELECT managerid
    FROM employee
    GROUP BY managerid
    HAVING COUNT(managerid) >= 5
);