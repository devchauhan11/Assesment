CREATE TABLE Bank (
    branch_id INT PRIMARY KEY,
    branch_name VARCHAR(100) NOT NULL,
    branch_city VARCHAR(50) NOT NULL
);

CREATE TABLE Account_Holder (
    account_holder_id INT PRIMARY KEY,
    account_no BIGINT UNIQUE NOT NULL,
    account_holder_name VARCHAR(100) NOT NULL,
    city VARCHAR(50) NOT NULL,
    contact VARCHAR(15),
    account_created_date DATE NOT NULL,
    account_status VARCHAR(20) CHECK (account_status IN ('Active', 'Terminated')),
    account_type VARCHAR(20),
    balance DECIMAL(12,2) CHECK (balance >= 0)
);

CREATE TABLE Loan (
    loan_no INT PRIMARY KEY,
    branch_id INT,
    account_holder_id INT,
    loan_amount DECIMAL(12,2) NOT NULL,
    loan_type VARCHAR(50),
    FOREIGN KEY (branch_id) REFERENCES Bank(branch_id),
    FOREIGN KEY (account_holder_id) REFERENCES Account_Holder(account_holder_id)
);

BEGIN TRANSACTION;

-- Debit Account A
UPDATE Account_Holder
SET balance = balance - 100
WHERE account_no = 111111
AND balance >= 100;

-- Credit Account B
UPDATE Account_Holder
SET balance = balance + 100
WHERE account_no = 222222;

COMMIT;

SELECT city, account_holder_name, account_no
FROM Account_Holder
WHERE city IN (
    SELECT city
    FROM Account_Holder
    GROUP BY city
    HAVING COUNT(*) > 1
);

SELECT account_no, account_holder_name
FROM Account_Holder
WHERE EXTRACT(DAY FROM account_created_date) > 15;

SELECT branch_city, COUNT(*) AS Count_Branch
FROM Bank
GROUP BY branch_city;

SELECT 
    ah.account_holder_id,
    ah.account_holder_name,
    l.branch_id,
    l.loan_amount
FROM Loan l
INNER JOIN Account_Holder ah
ON l.account_holder_id = ah.account_holder_id;
