-- https://leetcode-cn.com/problems/second-highest-salary/submissions/

SELECT IFNULL (
    (SELECT Salary 
     FROM Employee 
     GROUP BY Salary
     ORDER BY -Salary LIMIT 1, 1), NULL) AS SecondHighestSalary;