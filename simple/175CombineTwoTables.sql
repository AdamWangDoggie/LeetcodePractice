-- https://leetcode-cn.com/problems/combine-two-tables/submissions/

SELECT a.FirstName, a.LastName, b.City, b.State 
FROM Person as a 
LEFT JOIN Address as b 
ON b.PersonId = a.PersonId;