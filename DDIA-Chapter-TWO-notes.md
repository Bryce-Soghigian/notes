# Chapter 2 Data Models and Query Languages

The way we model our data is one of the most important parts of software development. Most applications are built by layering one data model on top of another. 


## Key Question... If most data models are built on top of each other, how do we represent the next lower level while maintaining a healthly application complexity?
- We need to consider a couple things when thinking about data modeling

1. How can we model the data so each layer of abscraction hides some layer of complexity?
2. How is this data going to be used? Are there a lot of relationships between the data?
3. Will we be frequently searching through? Maybe many more reads than writes? Define a usecase of features before picking a particular technology.

# Relational Model Versus Document Model
The best know data model is that of SQL based on the relational database model proposed by Edgar codd in 1970. Data can be organized into relations(Called tables) where each relation is an unordered collection of **tuples** (Rows in SQL)

## The Birth of NOSQL

In the 2010s Nosql databases attempted to overthrow the relational models dominance. Much like how javascript took advantage of javas popularity, NOSQL did the same thing. It has no real relation with SQL. 

There were several driving forces behind the adoption of NoSQL databases,

1. A need for greater scalablity and larger quantities of data
2. Preference of a free and open source tool over commerical database products.
3. Specialized querys/searching that is not particularly optimized in the SQL model.
4. A more dynamic way of representing data schemas. SQL is very much focused on constraints and doesnt always allow a use to Express themselves.


## Another Problem with The Relational model
Most Application Development in the modern day is Object Oriented. Which tends to lead to issues with the traditional SQL data model. If the data is storied in relational tables, we need to translate the objects in the application code and the database model of tables, rows, and columns. This is known as **impedance mismatch**

### ORMS

Orms like ActiveRecord, KnexJS can reduce the amount of boilerplate code required for the translation of objects to primitive data that a SQL database can store, but they cant completely hide that layer of abscraction. 

Some solutions of that problem include using JSON to directly map the fields into text fields in the database. This allows us to simplify the mapping process, and reduce impedance mismatch. The lack of a schema for representing and storing the data can be seen as an advantage
