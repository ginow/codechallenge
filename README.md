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
- Array address and pointer
  ```c++
  int a[5] = {20, 1, 2, 3, 4};
    cout<<"a:       "<<a<<endl;
    cout<<"a+1:     "<<(a+1)<<endl;
    cout<<"*a:      "<<*a<<endl;
    cout<<"&a:      "<<&a<<endl;
    cout<<"a[0]:    "<<a[0]<<endl;
    cout<<"&a[0]:   "<<&a[0]<<endl;
    cout<<"*(&a[0]):"<<*(&a[0])<<endl;
    cout<<"(&a+1):  "<<(&a+1)<<endl; // This calculates the address of the element after the end of the array a. Since a is an array of integers, adding 1 to its address advances the pointer by the size of the entire array (sizeof(int) * number_of_elements_in_a). Therefore, (&a+1) points to the memory location just beyond the end of the array a.
    cout<<"*(&a+1): "<<*(&a+1)<<endl; // This dereferences the address calculated by (&a+1), effectively giving you the value stored at that memory location. However, this memory location is just beyond the end of the array a. Dereferencing it leads to undefined behavior because it's accessing memory that isn't part of the array. In practice, this often results in printing the value stored at that memory location, which could be anything, but it's not reliable or meaningful.
    cout<<"*(a+1):  "<<*(a+1)<<endl;
    
    /*
    a:       0x7f7570c000a0
    a+1:     0x7f7570c000a4
    *a:      20
    &a:      0x7f7570c000a0
    a[0]:    20
    &a[0]:   0x7f7570c000a0
    *(&a[0]):20
    (&a+1):  0x7f7570c000b4
    *(&a+1): 0x7f7570c000b4
    *(a+1):  1
    */
  ``` 
 - 2D Array
   ```c++
   #include <iostream>
    template <size_t n, size_t m>        // copies the function definition during compilation
    void printArray(int (&a)[n][m]) {    // passes a by reference
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    int main() {
        cout << "Example I:" << endl;
        int a[2][5];
        printArray(a);
        cout << "Example II:" << endl;
        int b[2][5] = {{1, 2, 3}};
        printArray(b);
        cout << "Example III:"<< endl;
        int c[][5] = {1, 2, 3, 4, 5, 6, 7};
        printArray(c);
        cout << "Example IV:" << endl;
        int d[][5] = {{1, 2, 3, 4}, {5, 6}, {7}};
        printArray(d);
        }
    /*
    Example I:
    0 0 0 0 0 
    0 0 0 0 0 
    Example II:
    1 2 3 0 0 
    0 0 0 0 0 
    Example III:
    1 2 3 4 5 
    6 7 0 0 0 
    Example IV:
    1 2 3 4 0 
    5 6 0 0 0 
    7 0 0 0 0 
    */
   ```
- Two Pointer technique
  ```c++
  #include <iostream>
  void reverse(int *v, int N) {
      int i = 0;
      int j = N - 1;
      while (i < j) {
          swap(v[i], v[j]);
          i++;
          j--;
      }
  }
  int main() {   
      int c[7] = {1, 2, 3, 4, 5, 6, 7};
      reverse(c,7);
      for(int i=0;i<7;++i){
          cout<<c[i]<<" ";
      }   
  }
  /*
  Output: 7 6 5 4 3 2 1
  */
  ```
- Two Pointer technique for space limitation
  ``` c++
  // Remove element without creating another array
  #include <iostream>
  int removeElement(vector<int>& nums, int val) { // nums is a reference to a vector of integers.
      int k = 0;
      for (int i = 0; i < nums.size(); ++i) {
          if (nums[i] != val) {
              nums[k] = nums[i];
              ++k;
          }
      }
      return k;
  }
  int main() {   
      vector<int> c = {1, 2, 3, 4, 5, 6, 7};
      int k = removeElement(c,2);
      for(int i=0;i<k;++i){
          cout<<c[i]<<" ";
      }   
  }
  /*
  Output: 1 3 4 5 6 7
  */
  ```
- Hash Table
  - Hash set is one of the implementations of a set data structure to store no repeated values
  - Hash map is one of the implementations of a map data structure to store (key, value) pairs.
 
- Hash Set example
  ```c++
    #include <unordered_set>                // 0. include the library
    
    int main() {
        // 1. initialize a hash set
        unordered_set<int> hashset;   
        // 2. insert a new key
        hashset.insert(3);
        hashset.insert(2);
        hashset.insert(1);
        // 3. delete a key
        hashset.erase(2);
        // 4. check if the key is in the hash set
        if (hashset.count(2) <= 0) {
            cout << "Key 2 is not in the hash set." << endl;
        }
        // 5. get the size of the hash set
        cout << "The size of hash set is: " << hashset.size() << endl; 
        // 6. iterate the hash set
        for (auto it = hashset.begin(); it != hashset.end(); ++it) {
            cout << (*it) << " ";
        }
        cout << "are in the hash set." << endl;
        // 7. clear the hash set
        hashset.clear();
        // 8. check if the hash set is empty
        if (hashset.empty()) {
            cout << "hash set is empty now!" << endl;
        }
    }
    /*
    Key 2 is not in the hash set.
    The size of has set is: 2
    1 3 are in the hash set.
    hash set is empty now!
    */
  ```
  - Find duplicates with Hashset
    ```c++
    #include <unordered_set>                // 0. include the library

    bool findDuplicates(vector<int>& keys) {
        unordered_set<int> hashset;
        for (int key : keys) {
            if (hashset.count(key) > 0) {
                return true;
            }
            hashset.insert(key);
        }
        return false;
    }
    int main(){
        vector<int> mykeys={1,9,2,2,3};
        cout<<findDuplicates(mykeys); // Output: 1
    }
    ```
  - Hash map
    ```c++
    #include <bits/stdc++.h>
    #include <unordered_map>
    
    using namespace std;
    
    int main() {
      // 1. initialize a hash map
      unordered_map<int, int> hashmap;
      // 2. insert a new (key, value) pair
      hashmap.insert(make_pair(0, 5));
      hashmap.insert(make_pair(2, 3));
      cout << "The value of key 0 is: " << hashmap[0] << endl;
      cout << "The value of key 1 is: " << hashmap[1]
           << endl; // There is no key 1, so 0 will be output
      cout << "The value of key 2 is: " << hashmap[2] << endl;
      cout << "The value of key 3 is: " << hashmap[3]
           << endl; // There is no key 3, so 0 will be output and 3 will get
                    // inserted in the hashmap
      //  3. insert a new (key, value) pair or update the value of existed key
      hashmap[1] = 8;
      cout << "The value of key 1 is: " << hashmap[1] << endl;
      hashmap[1] = 9;
      cout << "The value of key 1 is: " << hashmap[1] << endl;
    
      // 5. delete a key
      hashmap.erase(2);
      // 6. check if a key is in the hash map
      if (hashmap.count(2) <= 0) {
        cout << "Key 2 is not in the hash map." << endl;
      }
      // 7. get the size of the hash map
      cout << "the size of hash map is: " << hashmap.size() << endl;
      // 8. iterate the hash map
      for (auto it = hashmap.begin(); it != hashmap.end(); ++it) {
        cout << "(" << it->first << "," << it->second << ") ";
      }
      cout << "are in the hash map." << endl;
      // 9. clear the hash map
      hashmap.clear();
      // 10. check if the hash map is empty
      if (hashmap.empty()) {
        cout << "hash map is empty now!" << endl;
      }
    }
    /*
    The value of key 1 is: 0
    The value of key 2 is: 3
    The value of key 3 is: 0
    The value of key 1 is: 8
    The value of key 1 is: 9
    Key 2 is not in the hash map.
    the size of hash map is: 3
    (3,0) (1,9) (0,5) are in the hash map.
    hash map is empty now!
    */
    ```
