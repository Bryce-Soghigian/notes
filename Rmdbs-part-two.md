# Learning the Basic Features Of SQL

If you haven't read the article before this we went through the basic ideas of why to use SQL. In this one we will go over a variety of basic features which include

- Creating Table
- Contstraints
- Insert
- Select
- Where
- AND OR
- IN & BETWEEN
- Order By
- Top/Limit
- Distinct
- Update
- Truncate
- DROP

## CReating a table
THis is one of the more useful ideas to understand.

When creating a new table you will define a tablename and columns


### Columns
Columns contain 3 fields

- columnName
- dataType(What will be stored in this column)
- constraints ( pretty self explainitory )

```sql
CREATE TABLE table_name (
    column1_name data_type constraints,
    column2_name data_type constraints,
    ....
);
```

```sql
-- Syntax for MySQL Database 
CREATE TABLE persons (
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50) NOT NULL,
    birth_date DATE,
    phone VARCHAR(15) NOT NULL UNIQUE
);
 
-- Syntax for SQL Server Database 
CREATE TABLE persons (
    id INT NOT NULL PRIMARY KEY IDENTITY(1,1),
    name VARCHAR(50) NOT NULL,
    birth_date DATE,
    phone VARCHAR(15) NOT NULL UNIQUE
);
```

There are a few more constraints called modifiers that define the rules regarding what values are allowed in columns
- NOT NULL
- PRIMARY KEY
- AUTO_INCRMENT
- UNIQUE

# What is a contraint?
A Constraint is simply a restriction placed on one or more columns of a table to limit what can be put into that column. There are several types of constraints

a couple of useful ones are 
- NOT NULL
- PRIMARY KEY
- UNIQUE
-DEFAULT
- FOREIGN KEY
- CHECK

I feel like NOT_NULL, Unique and Default are pretty straight forward. Not null obv means that we have to have a value in that column of the table. Unique means that no other values in the table can match the value we are trying to insert. Often used to make sure you don't sign up twice or something like that. The last super straightforward one is default. With default we just set the value if we dont define it in our insert to default to the default Value.

```sql
-- Example of NOT NULL
CREATE TABLE persons(
	id INT NOT NULL,
	name VARCHAR(30) NOT NULL,
	birth_date DATE,
	phone VARCHAR(15) NOT NULL
);
```

```sql
-- UNIQUE CONSTRAINT 
CREATE TABLE persons(
	id INT NOT NULL PRIMARY KEY,
	name VARCHAR(30), 
	birth_date DATE,
	phone VARCHAR(15) NOT NULL UNIQUE
);
```

The important thing to remember and take away is when defining a table we are concerned with 3 things
1. columnName
2. DataType
3. Constraints

The next two constraints in which we should talk about is Primary Key and Foreign Keys. These are what make SQL Databases Relational in nature. 

### Primary KEY Constraint
The Primary key constraint allows us to identify the column or set of columns that have values that uniquely identify a row in a table. No two rows in a table can have the same primary key value. Also you cannot enter null value in a primary key column.

```sql
CREATE TABLE persons (
    id INT NOT NULL PRIMARY KEY,
    name VARCHAR(30) NOT NULL,
    birth_date DATE,
    phone VARCHAR(15) NOT NULL
);
```

Now lets talk about foreign keys

### Foreign KEY constraint
A foreign key is a column or combination of columns that is used to establish and enforce a relationship between the data in two tables.

```sql
/*
Lets define some example tables. 
A department and employee table should do.
*/

CREATE TABLE departments(
dep_id int(100) PRIMARY KEY NOT NULL,
dep_name VARCHAR(45) NOT NULL,
);

CREATE TABLE employees(
	emp_id INT NOT NULL PRIMARY KEY,
	emp_name VARCHAR(55) NOT NULL,
	hire_date DATE NOT NULL,
	salary INT DEFAULT 5000,
	dep_id INT,
	FOREIGN KEY(dep_id) REFERENCES departments(dep_id)
);
```
We can define a relationship between the data using these two key types. Primary key and Foreign key. 
This is an important concept so you better understand it.

### Check Constraint
The check constraint is used to restrict values that can be placed in a column. 
For example if you work for a company paying employees under minimum wage we want to have a check constraint in our database to make sure that number is never recorded ;). 

#### A more realistic Usecase.
Lets say we are facebook. Each Facebook engineering level has a specific salary range. We can check for each employee type that engineers of a given level can only be inserted into the database if their level meets the level requirements. THe question is what should be responsible for validation? 

Sure we could implement some complicated database schema to enforce this type of thing, but in my experience we should leave more complicated functionality like that to an api/sql query. 


```sql
-- Example of check constraint
CREATE TABLE employees (
	emp_id INT NOT NULL PRIMARY KEY,
	emp_name VARCHAR (55) NOT NULL,
	hire_date DATE NOT NULL,
	salary INT NOT NULL CHECK (salary >= 3000 AND salary <= 10000),
	dep_id INT,
	FOREIGN KEY (dep_id) REFERENCES departments(dep_id)
);

```

Now that we understand the underlying models and concepts behind the tables lets get to querying/modifying data inside the tables.

# Inserting data
How good are these tables we have been learning about if we cant do anything with them. 

```sql
INSERT INTO table_name (column1, column2, ...) VALUES (value1, value2, ...);
```
We can break this statement into 3 parts
1. INSERT INTO(SQL keyword for inserting into a table.
2. () the list of columns we want to add data to
3. VALUES (). the list of values we want to insert.

- We can view the table structure before insertion to test to see if our insert has the right types.

```
DESCRIBE persons;
```

```sql
INSERT INTO persons (name, birth_date, phone)
VALUES ('Peter Wilson', '1990-07-15', '0711-020361');
```
IF we insert into the persons table with these three values the database will
create a new row in the database
```sql
CREATE TABLE persons (
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50) NOT NULL,
    birth_date DATE,
    phone VARCHAR(15) NOT NULL UNIQUE
);
```
You might ask yourself why didnt we have to insert id? Its got a NOT NULL constraint. Notice the AUTO INCREMENT constraint. this constraint will create a new id for each new row we insert into the database automatically based on the previous id.


# SELECT STATEMENT. Querying data

We learned how to insert new data into a database table. We learned write. Now lets learn read.

## Syntax
```sql
SELECT column1_name, column2_name, FROM table_name;
```
Here column1 are the names of the columns and fields of a databse table whose values you want to fetch. However if you just want to fetch all the values from a given table you can just 

```sql
SELECT * FROM persons
```
If we want to just select specific columsn from a table its as simple as 
```sql
SELECT emp_id, emp_name, hire_date, salary
FROM employees;
```

# The WHERE Clause
I mean while selecting entire databse columns has its uses, we often want a much more specific thing from our database. We can select specific data using the WHERE clause.

##### NOTE THE where clause is used with SELECT UPDATE and DELETE. However you will see how we use it in the coming notes.

```sql
SELECT column_list FROM table_name WHERE some_condition;
```

A real example

```sql
SELECT * FROM employees
WHERE salary > 7000;
```

Want the see the first employee?

```sql
SELECT * FROM employees
WHERE emp_id = 1;
```

Find the employee in the database that has an id of 1

## Operators the Where Clause uses.

OPERATOR | description | Example
---|---|---
= | Equals | WHERE id = 2
> | Greater Than | Where salary > 100000
< | Less Than | Where age < 18
>= | Greater than Equal tO | whERE RATING >= 4
<= | Less than or equal | where <= 100 
IN | Check if there is a specific value in a list | WHERE country IN ('USA','Japan')
LIKE | Simple pattern Matching | where name Like 'Dav'
BETWEEN | Check whether a specified value is within a range of values| where rating between 3 AND 5


# AND & OR operator
I feel like this operator is pretty straight forward to most engineers. so im skipping it
