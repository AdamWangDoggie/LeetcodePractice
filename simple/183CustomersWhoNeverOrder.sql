--https://leetcode-cn.com/problems/customers-who-never-order/

SELECT c.Name as Customers From Customers as c
LEFT JOIN Orders as o ON o.CustomerId = c.Id
WHERE o.Id IS NULL