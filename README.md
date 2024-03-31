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
- Array
  ```c++
  int a1[5] = {1, 2, 3};  // other element will be set as the default value
  // Get Length
  int size = sizeof(a1) / sizeof(*a1); // sizeof(*a1) returns the size of the first element of the array, which in this case is the size of an integer
  ```
- Another way to iterate Array
  ```c++
  for (int& item: a1) {
        cout << " " << item;
  }
  ```
- Array sort
  ```c++
  sort(a1, a1 + size);
  ```
