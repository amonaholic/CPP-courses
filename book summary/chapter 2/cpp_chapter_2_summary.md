# Chapter 2 Summary — The First Steps in C++

*Based on Chapter 2 of Jörg Mielebacher, **Programmieren mit C++ – Ein Einstieg in Beispielen** (2025).*

## What this chapter is about

Chapter 2 introduces the basic structure of a C++ program and explains how C++ source code becomes an executable program.

The main ideas are:

- what C++ is useful for,
- what a very small C++ program looks like,
- how source files are organized,
- how output works,
- how to write readable code,
- what editors and IDEs are,
- how compiling works,
- what the preprocessor, compiler, and linker do,
- how errors and warnings are handled,
- and how to build and run a program.

---

# 2.1 C++ as a Programming Language

## 2.1.1 Background and Typical Uses

C++ has existed since the 1980s and is still widely used.

It is especially useful when a program needs:

- **high performance**, or
- **close access to hardware**.

Typical areas include:

- image processing,
- video processing,
- 3D applications,
- games,
- operating systems,
- device drivers,
- robotics,
- industrial systems,
- and embedded systems.

### Embedded systems

Embedded systems are computers that are built into other machines or devices.

A C++ program in an embedded system may:

- read values from sensors,
- control motors,
- control valves,
- regulate temperature,
- regulate speed,
- or process measurement data.

These systems often have limited memory and processing power.

C++ is useful here because it allows programmers to write efficient programs.

### C++ is not always the best choice

C++ is not the ideal language for every task.

For example, web applications are usually developed with other languages.

So the basic idea is:

> Use C++ when performance and hardware access are important.

---

## Freedom and Risk

C++ gives programmers a lot of control.

For example, C++ allows direct and flexible access to computer memory.

This can make programs very powerful and efficient.

However, this freedom also creates risks.

A program can:

- crash,
- behave unpredictably,
- contain security problems,
- or appear to work even though the code is unsafe.

An important lesson from the chapter is:

> Just because something works does not mean it is correct or good C++.

And:

> Just because C++ allows something does not mean you should use it.

---

## C, C++, and C#

C++ originally developed from the programming language C.

Because of this, C++ still contains many ideas from C.

However, some older C-style techniques can be unsafe or outdated.

Modern C++ often offers safer and clearer alternatives.

C# is a different language. It shares some similarities with C++, but it has developed in a different direction.

---

# 2.1.2 C++ for Beginners and People Coming from Other Languages

Many programming languages use similar concepts, such as:

- variables,
- conditions,
- loops,
- and functions.

If you have never programmed before, the first goal is to understand these basic ideas.

If you already know another language, you will recognize some things.

For example:

- `if` exists in many languages,
- `while` exists in many languages,
- loops and variables are common programming concepts.

C++ may still feel unusual at first.

Some symbols can have different meanings depending on the situation, and some parts of the language may look old-fashioned.

The book also explains that C++ is especially common in technical fields.

People studying or working in areas such as engineering, automation, robotics, or embedded systems often encounter C++.

---

# 2.2 “Hello World” as the Basic Structure

The first example is the traditional **Hello World** program.

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Hallo Welt" << endl;
    return 0;
}
```

This program prints text to the screen and then ends.

Even though it is very small, it already contains several important parts of a C++ program.

---

# 2.2.1 C++ Source Files

C++ source code is stored in text files.

The usual file extension is:

```text
.cpp
```

Example:

```text
hallowelt.cpp
```

Larger programs may also contain files with the extension:

```text
.h
```

These are commonly used for declarations and are discussed later in the book.

A file ending in `.c` normally contains C source code instead of C++ source code.

---

## Good File Names

File names should clearly describe what the file contains.

Good example:

```text
taschenrechner.cpp
```

The book recommends avoiding:

- spaces,
- umlauts,
- special characters,
- and unnecessarily complicated names.

For example, instead of:

```text
Mein schönstes C++-Programm.cpp
```

a safer name would be:

```text
mein_schoenstes_cpp_programm.cpp
```

or simply:

```text
taschenrechner.cpp
```

---

## Uppercase and Lowercase Matter

Operating systems may treat uppercase and lowercase letters differently in file names.

For example, some systems may see these as different files:

```text
hallo.cpp
Hallo.cpp
```

Inside C++ source code, uppercase and lowercase **always matter**.

These are different:

```cpp
cout
```

```cpp
Cout
```

```cpp
COUT
```

Only the correct spelling works.

---

# 2.2.2 The Main Program: `int main()`

Every C++ program needs exactly one main program.

It begins with:

```cpp
int main()
```

The execution of the program starts there.

A minimal C++ program looks like this:

```cpp
int main()
{
    return 0;
}
```

When this program starts, it immediately ends.

---

## Curly Braces

The contents of the main program are placed inside curly braces:

```cpp
{
    // program instructions
}
```

Curly braces create a **block of statements**.

Statements inside the block are executed in order.

Blocks will later be used for:

- loops,
- conditions,
- functions,
- classes,
- and many other C++ structures.

---

## `return 0;`

The line:

```cpp
return 0;
```

ends the `main()` function.

Because `main()` is the main program, this also ends the whole program.

The value `0` normally means:

> The program finished successfully.

A value other than `0` can be used to indicate an error.

Example:

```cpp
return 1;
```

---

# 2.2.3 Statements and Semicolons

A C++ program is made of statements.

Many statements end with a semicolon:

```text
;
```

Example:

```cpp
return 0;
```

Another example:

```cpp
cout << "Hello";
```

A useful beginner rule is:

> Most normal C++ statements end with a semicolon.

However, there are important exceptions.

For example, a preprocessor line does not end with a semicolon:

```cpp
#include <iostream>
```

And the line that starts a block also does not end with one:

```cpp
int main()
{
```

---

# Statement Blocks

Several statements can be grouped inside curly braces:

```cpp
{
    statement1;
    statement2;
    statement3;
}
```

A block can also contain another block.

This is called **nesting**.

You will see this often when learning:

- `if`,
- `while`,
- `for`,
- functions,
- and classes.

---

# Preprocessor Instructions

Some lines begin with:

```text
#
```

These are called **preprocessor instructions**.

Example:

```cpp
#include <iostream>
```

Preprocessor instructions do not end with a semicolon.

The preprocessor handles these instructions before the compiler processes the program.

---

# 2.2.4 Printing Text to the Screen

The program uses:

```cpp
cout
```

to output information.

Example:

```cpp
cout << "Hello";
```

The operator:

```cpp
<<
```

sends data to the output.

You can think of it as “pushing” information toward `cout`.

---

## `#include <iostream>`

To use standard input and output features, the program includes:

```cpp
#include <iostream>
```

Without it, features such as `cout` would not be available in this example.

---

## `using namespace std;`

The program also uses:

```cpp
using namespace std;
```

This allows the book to write:

```cpp
cout
```

instead of:

```cpp
std::cout
```

and:

```cpp
endl
```

instead of:

```cpp
std::endl
```

---

## Printing Text

Text that should appear on the screen is written inside double quotation marks:

```cpp
cout << "Hello";
```

The quotation marks are not printed.

The screen shows:

```text
Hello
```

---

## `endl`

`endl` creates a line break.

Example:

```cpp
cout << "Hello" << endl;
cout << "World" << endl;
```

Output:

```text
Hello
World
```

Without a line break, the next output would continue at the current cursor position.

---

# 2.2.5 Readable Code

The chapter strongly emphasizes readable source code.

This program may work:

```cpp
int main(){cout<<"Hallo Welt"<<endl;return 0;}
```

But it is difficult for humans to read.

A much better version is:

```cpp
int main()
{
    cout << "Hallo Welt" << endl;
    return 0;
}
```

---

## One Statement per Line

A good beginner rule is:

> Write one statement per line.

Instead of:

```cpp
cout << "A"; cout << "B"; return 0;
```

write:

```cpp
cout << "A";
cout << "B";
return 0;
```

This makes the program easier to understand.

---

## Use Consistent Braces

The position of braces can differ between coding styles.

For example:

```cpp
int main()
{
    return 0;
}
```

or:

```cpp
int main() {
    return 0;
}
```

Both can be valid.

The important point is:

> Use one style consistently.

---

## Indentation

Statements inside a block should be indented.

Good:

```cpp
int main()
{
    cout << "Hello" << endl;
    return 0;
}
```

Bad:

```cpp
int main()
{
cout << "Hello" << endl;
return 0;
}
```

Indentation makes the structure easier to see.

---

## Spaces and Blank Lines

Spaces make individual statements easier to read.

Compare:

```cpp
cout<<"Hello"<<endl;
```

with:

```cpp
cout << "Hello" << endl;
```

The second version is easier to understand.

Blank lines can also separate logical parts of a larger program.

---

# Comments

Comments are notes for human readers.

They are ignored when the program runs.

A single-line comment begins with:

```cpp
//
```

Example:

```cpp
// Print a welcome message
cout << "Welcome" << endl;
```

A multi-line comment is written with:

```cpp
/*
...
*/
```

Example:

```cpp
/*
This program
prints a message.
*/
```

The book recommends comments when the code is not self-explanatory.

Comments should not simply repeat obvious code.

Bad comment:

```cpp
// Print Hello
cout << "Hello";
```

This comment does not add useful information.

---

# 2.3 From Source Code to an Executable Program

Writing C++ code is only the first step.

The computer processor cannot directly execute C++ statements.

The source code must first be translated into machine instructions.

---

# 2.3.1 Editors and IDEs

## Text Editors

A text editor can be used to write source files.

The book gives examples such as:

- Visual Studio Code,
- Notepad++.

Useful editor features include:

- tabs for open files,
- line numbers,
- syntax highlighting,
- highlighting of blocks,
- and code folding.

These visual features help programmers work with the code, but they are not stored as part of the actual source file.

---

## IDEs

An **IDE** is an **Integrated Development Environment**.

An IDE contains a source-code editor and additional programming tools.

Important tools may include:

- a compiler,
- build tools,
- error messages,
- debugging tools,
- project management features.

Examples mentioned in the chapter include:

- Microsoft Visual Studio,
- JetBrains CLion,
- Qt Creator,
- Code::Blocks.

The book presents Code::Blocks as a simple option for beginners.

---

# 2.3.2 C++ Is a Compiled Language

C++ source code is translated before the program is executed.

This process is called **compilation**.

After successful compilation, the executable program can normally be started many times without translating the source code again.

This is different from languages where translation happens during every execution.

---

# The Three Main Translation Steps

The chapter describes three important stages:

```text
Source Code
    ↓
Preprocessor
    ↓
Compiler
    ↓
Linker
    ↓
Executable Program
```

These tools together form a compiler system.

Examples of compiler systems include:

- GCC,
- Clang,
- Microsoft Visual C++ Compiler.

---

# 1. The Preprocessor

The preprocessor processes lines beginning with:

```text
#
```

For example:

```cpp
#include <iostream>
```

The preprocessor can:

- insert code,
- replace parts of the source,
- or hide parts of the source before compilation.

With:

```cpp
#include <iostream>
```

the preprocessor makes the contents of the required header available before the compiler works on the program.

---

# 2. The Compiler

The compiler processes the source code after preprocessing.

It has two major jobs:

1. check whether the source follows C++ syntax rules,
2. translate it into object code.

For example, the compiler can find:

- missing semicolons,
- incorrect brackets,
- unknown language elements,
- and other syntax problems.

The compiler produces **object code**, which is not yet the final program.

---

# 3. The Linker

Programs often use libraries.

Libraries contain already prepared functionality that can be reused.

For example, standard output functionality is provided by libraries.

The linker combines:

- your object code,
- required library code,
- and other required program parts.

The result is the final executable program.

On Windows, executable files usually end in:

```text
.exe
```

On Linux, executable files do not normally need the `.exe` extension.

---

# Errors and Warnings

## Compiler Errors

If the compiler finds a serious syntax error, compilation stops.

Example:

```cpp
cout << "Hello"
```

The semicolon is missing.

If compilation fails:

> No executable program is created.

You must fix the error and compile again.

---

## Compiler Warnings

A warning is different.

The program may still be compiled, but the compiler has detected something suspicious.

The book recommends:

> Always take compiler warnings seriously.

Warnings often point to real programming problems.

---

## Linker Errors

The linker can also report errors.

This can happen when the program refers to something that cannot be found or connected.

If linking fails, the final executable program is not created.

---

# What the Compiler Cannot Check

A compiler mainly checks whether the code follows the language rules.

It cannot know whether your solution is logically correct.

For example:

```cpp
double area = width + height;
```

This may be valid C++, but if you wanted to calculate the area of a rectangle, the formula is wrong.

So:

```text
Successful compilation
does NOT mean
the program is correct.
```

Programs must also be tested.

---

# Target Platform

Compiled machine code is created for a specific platform.

A program compiled for one system cannot automatically be used on every other system.

For example, a program compiled for Windows is not automatically a Linux executable.

The source code can often be compiled again for another platform, but the executable itself is platform-specific.

---

# 2.3.3 Compiling from the Command Line

C++ programs can be compiled from a command line.

On Windows, this may be:

- Command Prompt,
- PowerShell.

On Linux and macOS, this is usually called a terminal.

The chapter uses `g++` as an example.

---

## Checking Whether `g++` Is Installed

You can enter:

```bash
g++
```

If the compiler responds, it is available.

On Windows, a compiler often needs to be installed first.

On Linux, GCC is often already available.

---

## Compiling a File

A typical command is:

```bash
g++ hallowelt.cpp -o hallowelt
```

On Windows, the result may be:

```text
hallowelt.exe
```

The option:

```text
-o
```

defines the name of the output program.

When `g++` is used, it automatically runs the necessary compilation steps.

You do not have to manually start the preprocessor, compiler, and linker one by one.

---

## If Compilation Fails

If the compiler finds an error, it normally reports information such as:

- file name,
- line number,
- position,
- error message.

You then:

1. open the source file,
2. find the problem,
3. fix it,
4. compile again.

---

# 2.3.4 Compiling in an IDE

An IDE usually makes the build process easier.

Instead of entering commands manually, you can use buttons such as:

- **Build**
- **Run**
- **Build + Run**

The IDE runs the compiler tools in the background.

Compiler errors are usually displayed inside the IDE.

The error message often includes:

- the file,
- the line number,
- and a description.

You can often click or double-click an error to jump directly to the problem.

---

## Fix Errors from Top to Bottom

The chapter gives a useful rule:

> Fix compiler errors from top to bottom.

Why?

Because one early error can create many later error messages.

After fixing one or a few errors, compile again.

Some later errors may disappear automatically.

---

# 2.4 Main Ideas to Remember

These are the most important ideas from Chapter 2.

## C++ is useful for

- high-performance software,
- hardware-related software,
- embedded systems,
- operating systems,
- device drivers,
- and many technical applications.

It is usually not the first choice for web applications.

---

## Basic C++ Program Structure

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World" << endl;
    return 0;
}
```

You should understand the purpose of:

- `#include <iostream>`
- `using namespace std;`
- `int main()`
- `{ }`
- `cout`
- `<<`
- `"text"`
- `endl`
- `return 0;`
- `;`

---

## C++ Source Files

Typical extension:

```text
.cpp
```

Larger programs may also use:

```text
.h
```

---

## C++ Is Case-Sensitive

These are different:

```cpp
cout
Cout
COUT
```

---

## Readable Code Matters

Use:

- one statement per line,
- consistent indentation,
- consistent braces,
- useful spaces,
- useful blank lines,
- meaningful comments.

---

## The Compilation Process

Remember this order:

```text
Source Code
    ↓
Preprocessor
    ↓
Compiler
    ↓
Linker
    ↓
Executable Program
```

---

## Compiler vs. Linker

**Compiler**

- checks C++ syntax,
- translates source code into object code.

**Linker**

- connects object code,
- adds required libraries,
- produces the executable program.

---

## Errors vs. Warnings

**Error**

- compilation or linking fails,
- no executable program is produced.

**Warning**

- the program may still be produced,
- but something may be wrong,
- warnings should be taken seriously.

---

## Compilation Is Not the Same as Correctness

A program can compile successfully and still be wrong.

Therefore:

> Programs must be tested.

---

# 2.5 Questions and Exercises from the Chapter

The chapter ends with review questions and practical tasks.

## Theory Questions

You should be able to explain:

1. What is C++ mainly used for?
2. When is C++ probably not the best choice?
3. What should you consider when naming C++ source files?
4. What belongs to the basic structure of a C++ program?
5. When do you use a semicolon?
6. Why are comments useful?
7. What is the difference between a text editor and an IDE?
8. How can source code be made easier to read?
9. How is C++ source code translated into an executable program?
10. What are the roles of the preprocessor, compiler, and linker?

---

## Practical Exercises

The chapter suggests exercises such as:

### Exercise 1 — Build Hello World

Install the necessary tools.

Create:

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Hallo Welt" << endl;
    return 0;
}
```

Then compile and run it.

---

### Exercise 2 — Print an Address

Write a program that prints a postal address on several lines.

Example:

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "John Smith" << endl;
    cout << "Example Street 10" << endl;
    cout << "12345 Example City" << endl;

    return 0;
}
```

Try to find more than one way of producing the same output.

---

### Exercise 3 — Create Errors on Purpose

Start with a working Hello World program.

Then deliberately create mistakes.

For example:

```cpp
cout << "Hello World" << endl
```

Remove the semicolon and compile again.

Or change:

```cpp
cout
```

to:

```cpp
Cout
```

Observe the compiler messages.

This helps you learn how compiler errors look.

---

# 2.6 What Comes Next

The chapter points to further reading about programming languages, C++, and the compilation process.

The book then moves on to Chapters 3 and 4, which introduce the actual C++ fundamentals in more detail.

Chapter 3 focuses especially on:

- input and output,
- variables,
- data types,
- calculations,
- conditions,
- loops,
- and functions.

---

# Simple Learning Checklist

Before continuing to Chapter 3, you should be able to answer **yes** to these questions:

- [ ] Do I know what a `.cpp` file is?
- [ ] Do I know where a C++ program starts?
- [ ] Do I understand what `int main()` means?
- [ ] Do I know what `{ }` are used for?
- [ ] Do I know why many statements end with `;`?
- [ ] Can I print text with `cout`?
- [ ] Do I know what `endl` does?
- [ ] Do I know what `return 0;` means?
- [ ] Do I know that C++ is case-sensitive?
- [ ] Do I know the difference between an editor and an IDE?
- [ ] Do I know the order: preprocessor → compiler → linker?
- [ ] Do I understand the difference between an error and a warning?
- [ ] Do I understand that successful compilation does not prove that a program is logically correct?
- [ ] Can I compile and run a simple C++ program?

If you can answer yes to most of these, you are ready for Chapter 3.

---

# Ultra-Short Recap

Chapter 2 teaches you the basic workflow of C++:

```text
Write source code
      ↓
Save it as a .cpp file
      ↓
Compile it
      ↓
Fix errors and warnings
      ↓
Link it
      ↓
Run the executable
      ↓
Test whether the program actually works correctly
```

The most important starter program is:

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World" << endl;
    return 0;
}
```

If you understand what every line in this program does and understand how it becomes an executable program, you have understood the central ideas of Chapter 2.
