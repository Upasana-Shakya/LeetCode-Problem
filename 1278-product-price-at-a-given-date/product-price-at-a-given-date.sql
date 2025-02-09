# Write your MySQL query statement below
SELECT distinct product_id,  10 as price
FROM products
GROUP BY product_id
HAVING min(change_date) > "2019-08-16"

UNION

SELECT product_id, new_price
FROM products
WHERE (product_id, change_date) IN (
                                    SELECT product_id, max(change_date) as recent_date
                                    FROM products
                                    WHERE change_date <= "2019-08-16"
                                    GROUP BY product_id
                                    );