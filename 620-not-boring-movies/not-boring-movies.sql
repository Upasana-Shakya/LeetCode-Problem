# Write your MySQL query statement below
SELECT id, movie, description, rating
FROM cinema 
WHERE id%2 = 1 AND description NOT IN ("boring")
ORDER BY rating DESC;