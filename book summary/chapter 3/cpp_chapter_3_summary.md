# Chapter 3 Summary — C++ Fundamentals

*Based on Chapter 3 (“Grundlagen”) of Jörg Mielebacher, **Programmieren mit C++ – Ein Einstieg in Beispielen** (2025).*

## Overview

Chapter 3 introduces the core building blocks of simple C++ programs:

- variables and data types
- input and output
- arithmetic expressions and assignments
- conditions and branching
- loops
- constants
- escape sequences
- functions
- value and reference parameters
- local and global variables
- basic problem solving and testing

The chapter develops these ideas step by step, mainly through small programs such as a meter-to-feet converter and a quality-control example.

---

# 1. Variables and Data Types

A variable stores a value under a name.

```cpp
double meter = 0.0;
int count = 0;
bool valid = false;
char letter = 'A';
```

Common data types introduced in the chapter:

| Type | Meaning | Example |
|---|---|---|
| `int` | signed whole number | `42`, `-5`, `0` |
| `unsigned int` | non-negative whole number | `0`, `42` |
| `double` | floating-point number | `3.14`, `-2.5` |
| `bool` | truth value | `true`, `false` |
| `char` | one character | `'A'`, `'5'` |

The data type determines which values are allowed and which operations make sense.

## Variable Names

Names should be meaningful.

Good:

```cpp
double weight_kg = 0.0;
```

Less useful:

```cpp
double x = 0.0;
```

Identifiers may contain letters, digits, and underscores, but they must not start with a digit. Reserved words such as `double` or `switch` cannot be used as variable names.

C++ is case-sensitive:

```cpp
meter
Meter
METER
```

are three different names.

## Initialization

Variables should be initialized when they are declared:

```cpp
double meter = 0.0;
```

instead of:

```cpp
double meter;
```

A local variable without initialization may contain an unpredictable value.

## Scope

A variable is usable from its declaration until the end of the block in which it was declared.

```cpp
{
    int x = 5;
    // x is valid here
}
// x is no longer valid here
```

Keep variable scope as small as practical.

Global variables have a very large scope and should usually be avoided.

---

# 2. Input and Output

## Output with `cout`

```cpp
cout << "Hello" << endl;
```

`cout` writes to standard output.

Values and calculations do not go inside quotation marks:

```cpp
double x = 21.0;

cout << x << endl;
cout << x * 2.0 << endl;
```

Text does:

```cpp
cout << "Result" << endl;
```

## Input with `cin`

```cpp
double meter = 0.0;
cin >> meter;
```

`cin` reads a value from standard input and stores it in a variable.

A common pattern is:

```cpp
cout << "Meter: ";
cin >> meter;
```

No `endl` is used after the prompt, so the user types on the same line.

---

# 3. Arithmetic

Important arithmetic operators:

```cpp
+   // addition
-   // subtraction
*   // multiplication
/   // division
%   // remainder of integer division
```

Example:

```cpp
double feet = meter * 3.2808399;
```

## Integer Division

This is a major beginner pitfall:

```cpp
5 / 2
```

produces:

```text
2
```

because both operands are integers.

This:

```cpp
5.0 / 2.0
```

produces:

```text
2.5
```

Be careful with expressions such as:

```cpp
1 / 2 * (a + b)
```

because `1 / 2` is integer division and becomes `0`.

Use, for example:

```cpp
0.5 * (a + b)
```

## Modulo

`%` means remainder, not percentage.

```cpp
5 % 2
```

gives:

```text
1
```

To calculate 10 percent of `x`:

```cpp
x * 0.1
```

## Operator Precedence

Multiplication and division happen before addition and subtraction.

```cpp
1 + 2 * 3
```

gives `7`.

Use parentheses when needed:

```cpp
(1 + 2) * 3
```

gives `9`.

## Mathematical Functions

Functions such as `sin()` are available through:

```cpp
#include <cmath>
```

Example:

```cpp
cout << sin(angle) << endl;
```

---

# 4. Assignment

The operator:

```cpp
=
```

means assignment, not mathematical equality.

```cpp
x = 5;
```

means:

> Store the value `5` in `x`.

This is valid:

```cpp
x = x + 1;
```

because the right-hand side is calculated first, then assigned to `x`.

Useful shorthand operators:

```cpp
x += 5;
x -= 5;
x *= 2;
x /= 2;

x++;
x--;
```

For example:

```cpp
x++;
```

increases `x` by one.

---

# 5. Conditions and Branching

A condition evaluates to either:

```cpp
true
```

or:

```cpp
false
```

## Comparison Operators

```cpp
<     // less than
<=    // less than or equal
>     // greater than
>=    // greater than or equal
==    // equal
!=    // not equal
```

Important:

```cpp
x = 5;
```

is assignment.

```cpp
x == 5
```

is comparison.

## `if`

```cpp
if (meter <= 0)
{
    cout << "Invalid value" << endl;
}
```

The block runs only if the condition is true.

## `if` / `else`

```cpp
if (x >= 0)
{
    cout << "Non-negative" << endl;
}
else
{
    cout << "Negative" << endl;
}
```

## Logical Operators

```cpp
!     // NOT
&&    // AND
||    // OR
```

Examples:

```cpp
if (x >= 0 && x <= 10)
{
    cout << "Inside range" << endl;
}
```

```cpp
if (x < 0 || x > 10)
{
    cout << "Outside range" << endl;
}
```

Do not write mathematical chained comparisons like:

```cpp
0 < x < 10
```

Instead use:

```cpp
0 < x && x < 10
```

## Conditional Operator

A short conditional assignment can use:

```cpp
condition ? value_if_true : value_if_false
```

Example:

```cpp
int factor = (sum >= 0.0) ? 1 : -1;
```

## `switch-case`

Use `switch` when one integral value can lead to several cases.

```cpp
switch (factor)
{
    case 1:
        cout << "Positive" << endl;
        break;

    case 0:
        cout << "Zero" << endl;
        break;

    case -1:
        cout << "Negative" << endl;
        break;

    default:
        cout << "Unknown" << endl;
        break;
}
```

Without `break`, execution continues into following cases.

---

# 6. `while` and `do-while`

Loops repeat statements.

## `do-while`

```cpp
double meter = 0.0;

do
{
    cout << "Meter (>0): ";
    cin >> meter;
}
while (meter <= 0);
```

A `do-while` loop checks its condition at the end.

Therefore its body runs at least once.

## `while`

```cpp
while (x < 10)
{
    x++;
}
```

A `while` loop checks the condition before each iteration.

Therefore it may run zero times.

## Infinite Loops

```cpp
while (true)
{
    // repeated forever unless explicitly stopped
}
```

The book also shows:

```cpp
while (1)
{
}
```

because non-zero integer values are interpreted as true.

## `break`

`break` immediately leaves a loop.

```cpp
while (true)
{
    double value = 0.0;
    cin >> value;

    if (value <= 0)
    {
        break;
    }
}
```

## `continue`

`continue` skips the rest of the current iteration and starts the next one.

```cpp
if (value < 0)
{
    continue;
}
```

---

# 7. `for` Loops

Use a `for` loop when the number of repetitions is known or controlled by a counter.

```cpp
for (int meter = 1; meter <= 5; meter++)
{
    cout << meter << endl;
}
```

The structure is:

```cpp
for (initialization; condition; update)
```

Example:

```cpp
for (int i = 0; i < 10; i++)
```

means:

1. start with `i = 0`
2. repeat while `i < 10`
3. after each iteration, increase `i`

The loop variable is usually local to the loop.

## Range-based `for`

The chapter also introduces a range-based loop:

```cpp
for (int meter : {1, 2, 3, 5, 10, 50, 100})
{
    cout << meter << endl;
}
```

The loop processes each listed value in order.

This form becomes especially useful later with containers.

---

# 8. Constants

If a value should not change, use `const`.

```cpp
const int NumberOfRows = 5;
```

The value cannot later be changed.

Constants improve readability and maintainability.

Instead of:

```cpp
for (int i = 0; i < 5; i++)
```

you may write:

```cpp
const int NumberOfRows = 5;

for (int i = 0; i < NumberOfRows; i++)
```

If the required number of rows changes, you only update the constant.

The book recommends `const` instead of the older preprocessor style using `#define`.

---

# 9. Escape Sequences

Escape sequences represent special characters and begin with `\`.

Important examples:

```cpp
\t   // tab
\n   // newline
```

Example:

```cpp
cout << "Meter\tFeet\n";
```

A single character can be written in single quotes:

```cpp
'\t'
```

Text strings use double quotes:

```cpp
"Meter\tFeet"
```

---

# 10. Functions

Functions divide a program into reusable named parts.

Example:

```cpp
double meter2feet(double m)
{
    return m * 3.2808399;
}
```

Call it with:

```cpp
double result = meter2feet(2.0);
```

General structure:

```cpp
return_type function_name(parameters)
{
    // statements
    return value;
}
```

Functions improve:

- readability
- reuse
- modularity
- maintainability

They also reduce duplicated code.

---

# 11. Parameters

Parameters provide values to a function.

```cpp
double add(double a, double b)
{
    return a + b;
}
```

Here `a` and `b` are parameters.

The function can be called with:

```cpp
double result = add(4.0, 5.0);
```

Each parameter needs a type and a name.

Functions may also have no parameters:

```cpp
int rollDice()
{
    // ...
}
```

The parentheses are still required.

---

# 12. Return Values

`return` does two things:

1. defines the function's result
2. leaves the function immediately

Example:

```cpp
double square(double x)
{
    return x * x;
}
```

Code after `return` in the same path is not executed.

A function can return at most one value directly through `return`.

---

# 13. `void` Functions

If a function does not return a value, use `void`.

```cpp
void showHelp()
{
    cout << "Help" << endl;
}
```

A `void` function does not need a return value.

It can still be left early with:

```cpp
return;
```

---

# 14. Call-by-Value

Normal parameters are value parameters.

```cpp
void reset(int x)
{
    x = 0;
}
```

Example:

```cpp
int value = 42;
reset(value);

cout << value << endl;
```

The output is still:

```text
42
```

because the function receives a copy of the value.

This is called:

```text
Call-by-Value
```

Changes to the parameter do not affect the original variable.

---

# 15. Reference Parameters

If a function should modify the original variable, use a reference parameter.

```cpp
void reset(int& x)
{
    x = 0;
}
```

Now:

```cpp
int value = 42;
reset(value);

cout << value << endl;
```

prints:

```text
0
```

The `&` marks the parameter as a reference.

This is called:

```text
Call-by-Reference
```

Use reference parameters when changing the caller's variable is actually intended. They are not automatically better than value parameters.

---

# 16. Local and Global Variables

A variable declared inside a function is local.

```cpp
void example()
{
    int x = 5;
}
```

`x` is only available inside `example()`.

Local variables are destroyed when the function ends.

Functions should preferably communicate through:

- parameters
- return values

instead of relying on global variables.

Global variables should generally be avoided because they create strong dependencies and make programs harder to understand.

---

# 17. Problem-Solving Workflow

The chapter uses a quality-control example to show how to solve a small programming task systematically.

A useful workflow is:

```text
Understand the problem
        ↓
Design the solution
        ↓
Implement it in small steps
        ↓
Compile
        ↓
Test
        ↓
Fix errors
        ↓
Test again
```

Before coding, clarify what the program should do.

Possible design tools include:

- examples
- flowcharts
- pseudocode
- comments describing planned steps

Then implement the program incrementally.

---

# 18. Testing

A program that compiles successfully is not automatically correct.

The compiler mainly checks whether the C++ code follows the language rules.

Logical errors can still remain.

Testing checks whether specific inputs produce the expected behavior and output.

Test:

- normal values
- values below expected ranges
- values above expected ranges
- boundary values
- special cases

Boundary and special cases are especially important because they often reveal bugs.

After fixing a bug, run the tests again.

---

# 19. Example: Quality Control

The chapter combines many previous concepts in one program.

The program:

- reads decimal measurement values
- stops when `0` is entered
- counts all values
- counts values outside a valid range
- calculates the percentage of invalid values

Concepts used include:

```text
variables
input/output
while
if
logical operators
break
integer counters
floating-point calculations
type conversion
constants
functions
testing
```

A notable issue is integer division.

If both counters are `int`:

```cpp
invalid / total
```

will use integer division.

A conversion to `double` is required for a proper decimal result:

```cpp
double(invalid) / double(total) * 100.0
```

---

# 20. Improving Code Quality

The chapter emphasizes quality even in small programs.

Useful techniques include:

- meaningful variable names
- small variable scopes
- avoiding global variables
- initializing variables
- using constants instead of repeated literal values
- using functions to separate responsibilities
- consistent formatting
- comments where they add useful information
- testing normal, boundary, and special cases

---

# 21. Finding Help

The chapter also discusses how to find help while learning C++.

Useful sources include:

- books
- documentation
- `cppreference.com`
- programming forums such as Stack Overflow
- generative AI tools

However, answers may be:

- outdated
- incorrect
- unnecessarily complicated
- written for a different C++ standard

So always check whether a solution fits your problem and your C++ version.

C++ exists in different standards, such as:

```text
C++11
C++17
C++23
```

A compiler can be configured for a particular language standard, so code written for a newer standard may not work in an older one.

Generative AI can be useful for:

- explaining code
- explaining compiler errors
- generating example code

but its answers should still be checked critically.

---

# 22. What You Should Know After Chapter 3

You should be able to:

- declare and initialize variables
- choose basic data types
- use meaningful variable names
- understand scope
- read input with `cin`
- write output with `cout`
- calculate with `+`, `-`, `*`, `/`, `%`
- understand integer division
- use assignment operators
- distinguish `=` from `==`
- write conditions
- use `if`, `else`, and basic `switch`
- combine conditions with `&&`, `||`, and `!`
- use `while`, `do-while`, and `for`
- use `break` and `continue`
- use range-based `for`
- define constants with `const`
- use `\t` and `\n`
- write functions
- pass parameters
- return values
- use `void`
- understand Call-by-Value
- understand reference parameters with `&`
- distinguish local and global variables
- test programs systematically

---

# Compact Cheat Sheet

```cpp
#include <iostream>
using namespace std;

double meter2feet(double meter)
{
    return meter * 3.2808399;
}

int main()
{
    const int MaxValues = 5;

    for (int i = 0; i < MaxValues; i++)
    {
        double meter = 0.0;

        cout << "Meter: ";
        cin >> meter;

        if (meter <= 0)
        {
            cout << "Invalid value" << endl;
            continue;
        }

        cout << "Feet: " << meter2feet(meter) << endl;
    }

    return 0;
}
```

This small program already combines many of the chapter's main ideas:

- variable declaration and initialization
- `const`
- `for`
- `cin`
- `cout`
- `if`
- comparison
- `continue`
- a function
- a parameter
- a return value

---

# Final Takeaway

Chapter 3 teaches the essential tools needed to write small but useful C++ programs.

The central idea is that larger programs are built from a few fundamental concepts:

```text
Variables
+ Conditions
+ Loops
+ Functions
= Structured Programs
```

If you can write small programs using these elements without copying everything line by line, you have understood the most important part of the chapter.
