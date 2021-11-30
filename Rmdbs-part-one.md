# Raw SQL Why learn it when orms do all of it for you?
Learning the underlying ideas of what exists for querying and manipulating the database will help you understand how the tools you are using work under the hood. Knowing all of what SQL has to offer will also help you in the case that your ORM doesnt allow you to do some complex/optimized query. Almost all ORMS provide a .RAW() function that will allow you to write your own complex queries.

## What can we do with SQL?

There are a lot of things we can do with SQL
- YOu can create a database
- You can create tables to store data
- You can query or request information into a database
- you can modify or manipulate that data.
- You can set permissions or access control within the database for data security
- You can create views to avoid typing frequently used complex queries.


# Getting Started With SQL

As you already know SQL is used to communicate with the database. It is a query language used to access the database. There are many query languages for accessing Relational Data Models but SQL seems to pair the best. 


## What is a relational database?

A relational database is a database divided into logical units called tables. where the tables are related to one another within the database. Relational database allows data to be broken down into logical smaller and manageable units for easier maintenance and better performance.

With a relational database we can draw connections between information. Relational databases seem to make a lot of sense when information shares a lot of common information.


# SQL Syntax. LETS Learn it together!
Sql like any other programming language has rules and logic you have to follow to get it to run the way you want.

## SQL Statements

Sql statements are very simple and straightforward the same design idea behind python where making it easy for new engineers to read. I personally think you should learn sql even if you can get by without it and just using ORMS. I think its important to understand fundementally how these tools work.

Lets go through some examples of SQL syntax

```sql
SELECT emp_name, hire_date, salary FROM employees WHERE salary > 5000;
```
We can break this SQL into 3 parts 

1. SELECT ...( Used to select certain colums of data)
2. FROM tableName( Used to specify which table we want to execute the precursing clause)
3. WHERE some condition( USed to filter or select data that meets a certain expectation.)

you can break SQL into multiple lines like
```sql
SELECT emp_name, hire_date, salary 
FROM employees 
WHERE salary > 5000;
```

You use semicolons to terminate the end of an SQL statement. Some databases might not require it but its still best practice to include the semi-colon. Certain Lanugages like javascript have semi-colon insertion built into the language. The code will be converted into an abscract syntax tree and will try and evaluate where the semi-colons should be placed. That being said i write semicolons in my javascript to communicate to other engineers where i want a given block of code to end.

# Case Sensitivity
Lets go through some more light syntax and talk about case sensitivity.

```sql
SELECT * FROM employees;
```
VS
```sql
select * from employees;
```
SQL keywords are case insensitive meaning you can use select or SELECT. The database and table names may be case sensitive themselves though. Depends on your os and how the database tool you are using is configured.

# Writing Comments in your SQL code
Part of learning a languages syntax involves this basic step.

SQL supports single line as well as multi line comments.

To write a single line comment start teh line with two consecutive hyphens

```sql
-- I can write whatever i want here! It will not be executed :)
SELECT * FROM bank;
```

Mulitline comments work the same as many other languages. 

```sql
/*
THis
is 
a 
multiline Comment */
SELECT * FROM employees
WHERE salary > 100000;


# Creating a new database

THe first step and best place to go when learning about databases is to create a database on your own local machine. 

The SQL for Doing that is

```sql
create database database_name
```
Notice create and database the keywords are lowercase. Case doesnt matter in most versions of SQL

Now lets create a real testdb

```sql
CREATE DATABASE demo;
```

creating a new datbase does not select it for use on our machine. 

We need to use the USE statement

```sql
USE demo;
``` 
If we want to use a specific database or run something on a specific database.


