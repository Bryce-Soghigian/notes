# The origin Story: What is KQL ?

Kusto Query Language is a powerful tool to expolore your data and discover patterns, identify anomalies and outlies, create statistical modeling and more. The query uses schema entites that are organized in a hierachy similar to SQLs: databases, tables, columns.

## What is a query Statement? 
There are three kinds of user query statements.
1. A tabular expression statement
2. A let statement
3. A set statement


## WHat is a Kusto Query? 
A kusto query is a read-only request to process data and return results. THe request is stated in plain text thats easy to read, author and automate. A kusto query has one or more query statements and retursn data in a tabular or graph format.


## What is a tabular statement? 
The most common kind of query statement is a tabular expression statement. Both its input and its output consist of tables or tabular datasets.

Tablular statements can contain zero or more operators. Each operator states with a tablular input and returns a tabular output. Operators are sequenced by a PIPe(Not pip we work for microsoft not amazon) Data flows or is piped from one operator to the next the data is filtered or manipulated at each step.


Look at the an example query

```SQL
StormEvents
| where StartTime between( datetime(2007-11-01) .. datetime(2007-12-01))
| where State == "FLORIDA"
| count
```

## Our first example query

```sql
StormEvents
| take 5
| sort by StartTime asc 
```
THe take operator allows us to take an arbitrary number of rows.

THis statement will take 5 items from the storm events table.



## The Project Operator
Not all columns are meaningful for data exploration so kusto provides a way to drop columns you aren't interested in
THe `project` operator serves this purpose. 
```sql
StormEvents
| project EventType, State, DamageProperty, DamageCrops, InjuriesDirect, InjuriesIndirect
| take 10
```
THis query will return a list of tablular objects with the properties stated next to the project operator


### Rename and define new columns by using project
With the project operator you can sum integer values from different columsn and return the results in a new column.
SO lets mess with our previous query.

```sql
StormEvents
| project US_State=State, EventType, Injuries=InjuriesDirect+InjuriesIndirect, Damage=DamageCrops+DamageProperty
| take 10
```

We now get 3 fields. EventType, injuries, and damage. But this just gives us data not sorted by state and a bunch of data of ppl who didn't get hurt. thats not good for news articles so lets just get the tornados where people had damage to their property

```sql
StormEvents
| where EventType == "Tornado"
| project US_State=State, EventType, Injuries=InjuriesDirect+InjuriesIndirect, Damage=DamageCrops+DamageProperty
| where Damage > 0
| sort by Damage desc 
```
Now it seems that the most damage was caused by a tornado in alabama. Its always alabama lol.

### Filtering using has
has in kusto is similar to the terms query in elasticsearch. 
we can filter for a column looking for a specific term. Often this is implemented with a reverse search index. 

```sql
StormEvents
| where EventType has "wind"
| project US_State=State, EventType, Injuries=InjuriesDirect+InjuriesIndirect, Damage=DamageCrops+DamageProperty
| where Damage > 0
| sort by Damage desc 
``` 

With this approach we no longer get tornado data just data with event types that include the word wind in them. 

### Test your knowledge
https://docs.microsoft.com/en-us/learn/modules/write-first-query-kusto-query-language/8-challenge

My solution 

```sql
StormEvents
| where StartTime between ( datetime(2007-04-01) .. datetime(2007-04-30))
| project EventType, State, Damage= DamageCrops + DamageProperty
| sort by Damage desc  
| take 5
```


