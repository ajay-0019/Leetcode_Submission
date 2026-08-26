# Write your MySQL query statement below
UPDATE Salary
SET SEX =
    CASE
        WHEN SEX='f' THEN 'm'
        ELSE 'f'
    END;
