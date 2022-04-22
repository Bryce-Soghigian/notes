# os.exit() vs the Exception Paradigm 





### Why is it important to think about this sort of tradeoff? I'm not designing a language.

WELL DO YOU WRITE CODE????? Understanding common patterns will help you understand and comprehend the reasons intended uses of a particular language. I think how you exit your code is very important and the os.exit and Exception argument is very enthralling. 



#### Ok, you convinced me to read your stupid article but before we can debate which is better for which situation, we need to know what both are.

Ok thats fair let's talk a little bit about OS exit then move onto exceptions.

#### OS EXIT

Os exit will completely shut down the program if it is called. A full stop in the program. os.exit in all languages also takes a non keyword argument , an integer parameter `status_code` which communicates to the person trying to debug our crashing what caused it to crash. This paired with proper logging will help you find exactly where the error occurred.



#### Ok so about the status codes? Are there any particular standards for these? What integer should i use?

Well c and c++ have defined a standard as well as bash. C has a specific set of error variables that are much more specific than the bash standard. Each language has specific issues for example memory errors in C so the exit codes communicate different things in different languages. It can be confusing and its one of the flaws in my opinion.

[C Exit Status Codes](https://gist.github.com/bojanrajkovic/831993)

[Bash Exit Status Codes](https://tldp.org/LDP/abs/html/exitcodes.html)





#### Pros of using OS EXIT

1. Generally there are only 255 types of status codes that can be used and 25ish that are popular. 
2. Instant termination. NO bubbling up it just dies when you tell it to. That is very powerful
3. Very straightforward concept. No need to learn specific patterns or anything it does exactly what you think it would.

#### Cons Of using OS EXIT

1. Generally without logging its impossible to debug in large codebases, as there could be 1000+ os.exit(1) located in your code base
2. Not verbose doesn't directly communicate what actually went wrong. Just very general nudges. "Memory Limit Exceeded". Is it a memory leak? Should i upgrade the box ? Should i optimize the space complexity of my code? You don't really know what specific problem with memory was the issue but at least you know where to look





### Ok so OS exit is super powerful in the sense that when something goes wrong we can instantly terminate our code! I like a kill switch as much as the next guy but you said we were also gonna talk about extensions.

You are correct my dear reader. Lets talk about exceptions.



#### Exceptions

So what are exceptions? Exceptions are this concept in many programming languages that allow us to communicate a specific EXCEPTION. Whether that is an edge case, an error, whatever. SO rather than exit exceptions aim to communicate something.





#### Pros of exceptions

1. you can create custom messages, add data payloads communicate whatever. Error messages are very specific and you can get to the root of the problem quickly.
2. Allows for verbose communication for specific edge cases rather than empty if statements where you can read the condition but it doesnt really explain the logic. Of course you can always put that information in the doc string but it can be nice to not have to jump back and forth when reading through some code

#### Cons of exceptions 

1. Adds a lot of extra code to a module. People generally write a ton of their own exceptions for very specific usecases.
2. Most languages use this keyword `raise` that will raise an exception and sometimes that involves layers of bubbling up the error before you reach some exit state. 



Not really related to pros or cons but one pattern i wanted to mention with exceptions



```python
class S3FileManager(File, MinioBucketStorage):
```

When you are working with a specific type of object please store the exceptions related to it on that object. If i work with you and your exceptions that are directly related to your class aren't stored there i am gonna leave a meanly worded comment on your merge request.





