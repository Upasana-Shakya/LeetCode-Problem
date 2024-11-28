# Write your MySQL query statement below
SELECT customers.name as Customers FROM customers 
WHERE id NOT IN (SELECT c.id FROM customers as c
JOIN orders AS o
ON c.id = o.customerId);