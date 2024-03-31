## C++ notes

- String comparison using "=="
  ```c++
  string a="abc";
  string b="abc";
  cout<<(a==b); // Output is 1
  ```
- String functions
  ```c++
    string s1 = "Hello World";
   // find
    cout << "The position of first 'o' is: " << s1.find('o') << endl; // 4
    cout << "The position of last 'o' is: " << s1.rfind('o') << endl; // 7
    // get substr
    cout << s1.substr(6, 5) << endl; // world
  ```
