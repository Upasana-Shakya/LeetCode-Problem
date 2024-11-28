# Write your MySQL query statement below
SELECT customers.name as Customers FROM customers 
WHERE id NOT IN (SELECT customerId FROM orders);