# Write your MySQL query statement below
SELECT name
FROM customer
WHERE customer.referee_id IS null OR customer.referee_id != 2;