In C++, writing custom comparators can be done in several ways, depending on the context in which you need them. Below are different methods to write custom comparators:

### 1. Using Function Pointers

You can define a comparator function and pass it as a function pointer to the sorting function (like `std::sort`).

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

bool customComparator(int a, int b) {
    return a > b; // Sort in descending order
}

int main() {
    std::vector<int> vec = {4, 2, 5, 1, 3};
    std::sort(vec.begin(), vec.end(), customComparator);

    for (int x : vec) {
        std::cout << x << " ";
    }
    return 0;
}
```

### 2. Using Functor (Function Object)

Define a struct or class with an `operator()` to act as a functor.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

struct CustomComparator {
    bool operator()(int a, int b) {
        return a > b; // Sort in descending order
    }
};

int main() {
    std::vector<int> vec = {4, 2, 5, 1, 3};
    std::sort(vec.begin(), vec.end(), CustomComparator());

    for (int x : vec) {
        std::cout << x << " ";
    }
    return 0;
}
```

### 3. Using Lambda Expressions

You can use lambda expressions to define comparators inline.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {4, 2, 5, 1, 3};
    std::sort(vec.begin(), vec.end(), [](int a, int b) {
        return a > b; // Sort in descending order
    });

    for (int x : vec) {
        std::cout << x << " ";
    }
    return 0;
}
```

### 4. Using `std::function`

You can use `std::function` to store the comparator, which can be a function pointer, functor, or lambda.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

bool customComparator(int a, int b) {
    return a > b; // Sort in descending order
}

int main() {
    std::vector<int> vec = {4, 2, 5, 1, 3};
    std::function<bool(int, int)> comparator = customComparator;
    std::sort(vec.begin(), vec.end(), comparator);

    for (int x : vec) {
        std::cout << x << " ";
    }
    return 0;
}
```

### 5. Using `std::greater` and `std::less`

The Standard Library provides predefined function objects like `std::greater` and `std::less` which can be used directly or as a base to create custom comparators.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::vector<int> vec = {4, 2, 5, 1, 3};
    std::sort(vec.begin(), vec.end(), std::greater<int>());

    for (int x : vec) {
        std::cout << x << " ";
    }
    return 0;
}
```

### 6. Using Member Function Pointers

If the comparator involves comparing members of a class, you can use member function pointers.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class MyClass {
public:
    int value;
    MyClass(int v) : value(v) {}

    bool operator<(const MyClass& other) const {
        return value < other.value;
    }
};

bool compareMyClass(const MyClass& a, const MyClass& b) {
    return a.value > b.value; // Sort in descending order based on `value`
}

int main() {
    std::vector<MyClass> vec = {MyClass(4), MyClass(2), MyClass(5), MyClass(1), MyClass(3)};
    std::sort(vec.begin(), vec.end(), compareMyClass);

    for (const MyClass& obj : vec) {
        std::cout << obj.value << " ";
    }
    return 0;
}
```

These are some of the ways to create custom comparators in C++. The choice of method depends on the specific use case and personal preference.\*\*\*\*
