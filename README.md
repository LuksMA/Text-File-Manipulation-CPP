#Text File Manipulation C++
Read/Write variables in text files with C++

##Documentation
```cpp
int clone_file(const string &path, const string &path_clone)
```
Make a copy of a file, used by writing functions.
<br><br>

```cpp
int write_comment(string path, int n_line, string comment)
```
Add a comment in a file line.
<br><br>

```cpp
int write_variable(string path, string variable_name, string variable_value)
```
Add or replace the value of a variable in the file.
<br><br>

```cpp
string read_variable(string path, string variable_name)
```
Read a variable in the file and return its value.
<br><br>

##Installation
Copy the files "file.h" and "file.cpp" for your project and include the file "file.h".
The file "main.cpp" and "example.txt" is an example of how to use the functions.
