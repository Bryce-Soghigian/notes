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

## Many to One and Many to Many Relationships

Why are regions represented as Ids and not plain text fields on linkedin?

- By making these Keys instead of plain text fields we can have
1. Constistent syyle and spelling across profiles
2. Avoid ambiguity
3. Easy and Simple Updating
4. When site is translated into other languages, the region and industry can be displayed in the users language.
5. Better and Faster Search.

WHen you store an id or a text string it is a question of duplication. When you use an id the information is meaningful to humans is stored in only one place, everything that refers to it uses an id(which is database readable due to the way data indexing works :) 

When you use an ID the information that is meaningful is duplciated in every record that uses it. If we use an id we can simply create a link to that data and it is only built once in the database.

Unfortunately normalizing data can require many-to-one relationships. There are many regionsbut many people only work in one industry, which deosnt fist nicely into our document model. 

Relational databases operate on this concept of relations, so its esay to refer to rows in other schemas/tables by ID because joins are easy. In document databases joins are not needed for one-to-many tree structures and support for joins is often weak.


IF athe database itself does not support joins, you have to emulate a join in the application code with multiple queries to the database. Even if an application starts out with  a join free document model, data has a tendency of becoming more interconnected as features are added. One of the mjany reasons SQL is so widely adopted.Unlike OOP SQL databases make sense in many usecases.'''



### Recommendations :)
Say you want to add a new feature to your application. A user can werite a recommendation for another user . That recomendation is shown on the resume of the user who was recommended. Together with the name and photo. If the data isnt related directly via a relationship, every time we update the data we have to udate everyone that user had reccomended. Its kind of a pain to go through and manually change all of those and its expensive. 


### Are document databases repeating history? 

In history we try and solve this problem of related data. Document databases handle one to many relationships fine, but many to many relationships have proven to be much more tricky. In the 1970s IBM wrote a solution called IMS originally developed for stock keeping in the apollo space program. The design relied on A hierarchical model which when i hear that i think trees. It representd all data as a tree of records nested within records much like JSON is represented. 

There are various limitations to this type of data model in terms of representing many to many relationships. Two prominent data models that were proposed to solve that issue were the relational model and the network model.

### The Network Model
The network is similar to the tree model, except its more so a graph model. Where we can have directed edges and connections. This allows much more intricate connection models. 

### Comparison to document databases
Document databased have reverted back to a hierarchical model in the aspect of storing nested data. Modern day document databases support document reference in the document model that allows a user to perform joins or followup queries. 

## Relational Versus Document Databases Today
 
