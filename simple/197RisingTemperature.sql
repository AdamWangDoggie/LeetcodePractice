-- https://leetcode-cn.com/problems/rising-temperature/description/

-- Write your MySQL query statement below
SELECT a.Id
FROM Weather as a
LEFT JOIN Weather as b
ON to_days(a.RecordDate) - 1 = to_days(b.RecordDate)
WHERE a.Temperature > b.Temperature