# Write your MySQL query statement below
SELECT e1.name as Employee
FROM employee as e1
INNER JOIN employee as e2
ON e2.id = e1.managerId
WHERE e1.salary > e2.salary