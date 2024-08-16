USE practice;

CREATE TABLE
	Customer (
		customer_id INT PRIMARY KEY,
		first_name VARCHAR(20),
		last_name VARCHAR(20),
		address_id INT
	);

CREATE TABLE
	Payment (
		customer_id INT,
		payment_mode ENUM (
			'Credit Card',
			'UPI',
			'NEFT',
			'Cash',
			'PayPal',
			'Bank Transfer',
			'Debit Card'
		),
		amount DECIMAL(10, 2),
		payment_date DATE,
		FOREIGN KEY (customer_id) REFERENCES Customer (customer_id)
	);

INSERT INTO
	Customer (customer_id, first_name, last_name, address_id)
VALUES
	(1, 'John', 'Doe', 101),
	(2, 'Jane', 'Smith', 102),
	(3, 'Alice', 'Johnson', 103),
	(4, 'Bob', 'Brown', 104),
	(5, 'Charlie', 'Davis', 105);

INSERT INTO
	Customer
VALUES
	('6', 'Hello', 'World', 106),
	('7', 'New', 'Programmer', 107);

INSERT INTO
	Payment (customer_id, payment_mode, amount, payment_date)
VALUES
	(1, 'Credit Card', 100.00, '2024-08-01'),
	(2, 'PayPal', 200.00, '2024-08-03'),
	(3, 'Debit Card', 150.00, '2024-08-05'),
	(6, 'Bank Transfer', 300.00, '2024-08-07'),
	(7, 'Cash', 50.00, '2024-08-09');

-- INNER JOIN
SELECT
	C.first_name,
	C.customer_id,
	P.payment_mode,
	P.payment_mode
FROM
	CUSTOMER as C
	INNER JOIN PAYMENT as P ON C.customer_id = P.customer_id;

-- LEFT JOIN
SELECT
	C.first_name,
	C.customer_id,
	P.payment_mode
FROM
	CUSTOMER as C
	LEFT JOIN Payment as P ON C.customer_id = P.customer_id;

select
	*
from
	customer;

-- RIGHT JOIN
SELECT
	C.first_name,
	C.customer_id,
	P.payment_mode
FROM
	CUSTOMER as C
	RIGHT JOIN Payment as P ON C.customer_id = P.customer_id;

-- Did you know there is nothing like OUTER JOIN or FULL OUTER JOIN in MySQL 🤯? You need to make UNION of LEFT AND RIGHT JOIN to emulate the same
SELECT
	*
FROM
	Customer as C
	LEFT JOIN Payment as P ON C.customer_id = P.customer_id
UNION
SELECT
	*
FROM
	Customer as C
	RIGHT JOIN Payment as P ON C.customer_id = P.customer_id