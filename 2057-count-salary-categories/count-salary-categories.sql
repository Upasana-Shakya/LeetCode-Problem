# Write your MySQL query statement below
SELECT "Low Salary" as category, SUM(income < 20000) as accounts_count
FROM accounts

UNION

SELECT "Average Salary" as category, SUM(income BETWEEN 20000 AND 50000) as accounts_count
FROM accounts

UNION

SELECT "High Salary" as category, SUM(income > 50000) as accounts_count
FROM accounts;