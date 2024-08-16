USE Practice;

CREATE TABLE
    Employees (
        employee_id INT PRIMARY KEY,
        employee_name VARCHAR(50),
        manager_id INT
    );

INSERT INTO
    Employees (employee_id, employee_name, manager_id)
VALUES
    (1, 'Alice', NULL), -- Alice is the CEO
    (2, 'Bob', 1), -- Bob reports to Alice
    (3, 'Charlie', 1), -- Charlie reports to Alice
    (4, 'David', 2), -- David reports to Bob
    (5, 'Eve', 2) -- Eve reports to Bob
;

-- Q. Find the corresponding manager name of each employee
SELECT
    *
FROM
    Employees AS T2
    INNER JOIN Employees AS T1 ON T2.manager_id = T1.employee_id;