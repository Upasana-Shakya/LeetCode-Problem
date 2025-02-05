# Write your MySQL query statement below
SELECT distinct l1.num as consecutivenums
FROM logs as l1
JOIN logs as l2 
ON l1.id = l2.id - 1
JOIN logs as l3
ON l1.id = l3.id - 2
WHERE l1.num = l2.num AND l2.num = l3.num;