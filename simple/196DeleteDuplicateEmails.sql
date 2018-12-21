-- https://leetcode-cn.com/problems/delete-duplicate-emails/description/

# Write your MySQL query statement below
DELETE FROM Person Where Id not in
(SELECT Id FROM
(SELECT min(Id) as Id
FROM Person
GROUP BY Email) as p);
