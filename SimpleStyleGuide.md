# Simple Style Guide

**Comprehensive**: https://google.github.io/styleguide/cppguide.html#Naming

https://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/ //zh-cn

#### _In order to make our code human-readable, please follow this guide when you are coding._

## Comments

Comments are absolutely vital to keeping our code readable.
The following rules describe what you should comment and where.
But remember: while comments are very important, the best code is self-documenting.
Giving sensible names to types and variables is much better than using obscure names that
you must then explain through comments.

When writing your comments, write for your audience: the next contributor who will need to
understand your code. Be generous — the next one may be you!

## Naming

### Type Names

Type names start with a capital letter and have a capital letter for each new word, with no underscores:
`MyExcitingClass`, `MyExcitingEnum`.

### Variable Names

The names of variables (including function parameters) and data members are all lowercase, 
with underscores between words. 
Data members of classes (but not structs) additionally have trailing underscores. 
For instance: 
`a_local_variable`,
`a_struct_data_member`, `a_class_data_member_`.

#### Common Variable names

`std::string table_name; // OK - lowercase with underscore.`

`std::string tableName; // Bad - mixed case.`

#### Class Data Members

Data members of classes, both static and non-static, are named like ordinary nonmember variables, 
but with a trailing underscore.

`class TableInfo { 
    ... 
    private:
        std::string table_name_; // OK - underscore at end. 
        static Pool<TableInfo>* pool_; // OK. 
};`

#### Struct Data Members

Data members of structs, both static and non-static, are named like ordinary nonmember variables. 
They do not have the trailing underscores that data members in classes have.

`struct UrlTableProperties {
    std::string name;
    int num_entries;
    static Pool<UrlTableProperties>* pool;
};`

### Constant Names

Variables declared constexpr or const, and whose value is fixed for the duration of the program, 
are named with a leading "k" followed by mixed case. 
Underscores can be used as separators in the rare cases where capitalization cannot be used for 
separation. 
For example:

`const int kDaysInAWeek = 7;
const int kAndroid8_0_0 = 24;  // Android 8.0.0`

### Function Names

Regular functions have mixed case; accessors and mutators may be named like variables.
Ordinarily, functions should start with a capital letter and have a capital letter for each new word.

`AddTableEntry()
DeleteUrl()
OpenFileOrDie()`

