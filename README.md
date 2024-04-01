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
- Dynamic array
  ```c++
    // 1. initialize
    vector<int> v0;
    vector<int> v1(5, 0); // creates a vector with 5 elements, each initialized to the value 0
    // 2. make a copy
    vector<int> v2(v1.begin(), v1.end());
    vector<int> v3(v2);   
    // 3. cast an array to a vector
    int a[5] = {0, 1, 2, 3, 4};
    vector<int> v4(a, *(&a + 1)); 
    /* This line initializes the vector v4 with the elements of array a. Here's what's happening within the parentheses:
      a: This is the pointer to the first element of the array a.
      *(&a + 1): This expression gets the address of the element immediately after the last element of array a. Since a is an array of size 5, (&a + 1) points to the address immediately after the end of a, and *(&a + 1) dereferences this address, giving a pointer to the element after the end of a.*/

    // 4. get length
    cout << "The size of v4 is: " << v4.size() << endl;

    // 5. iterate
    cout << "[Version 2] The contents of v4 are:";
    for (int& item : v4) {
        cout << " " << item;
    }
    cout << endl;
    cout << "[Version 3] The contents of v4 are:";
    for (auto item = v4.begin(); item != v4.end(); ++item) {
        cout << " " << *item;
    }

    // 8. sort
    sort(v4.begin(), v4.end());
    // 9. add new element at the end of the vector
    v4.push_back(-1);
    // 10. delete the last element
    v4.pop_back();
  ```
