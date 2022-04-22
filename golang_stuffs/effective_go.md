# Part 1 how to write go code.

## Organizing Go Code

Go programs are organized into packages. Functions types variables and constants defined in one source fire are visible to other files within the same package. 

A repository contains one or more modules. A module is a collection of related Go packages that are released together. A go repository typically contains only one module, locaated at the root of the repository. A file named go.mod there declares teh module path. The import path for all packages within the module. The module contains the packages in the directory containing its go.mod file as well as the subdirectories of that directory, up to the next subdirectory contaning another go.mod file 
