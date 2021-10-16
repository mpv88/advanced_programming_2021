
/*- write a function `get_int` that reads from stdin until a valid number is fed
- write a function `get_double` that reads from stdin until a valid number is fed.

*Hints*: 
You can keep reading from stdin using one of two statements
```
while(std::cin >> i)
```
or
```
while(!(std::cin >> i))
```
what is the difference?

After that a wrong input has been parsed, you have to clear the error flag from `std::cin` calling
```
std::cin.clear();
```
and ignore what just read
```
std::cin.ignore();
```
/*
