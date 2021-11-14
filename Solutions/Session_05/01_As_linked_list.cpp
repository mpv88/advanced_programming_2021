/* COMPILE WITH: c++ 01_As_linked_list.cpp -o 01_As_linked_list -Wall -Wextra -g -std=c++14
   DEBUG WITH: gdb ./01_As_linked_list core; (gdb) r; (gdb) quit;
   TEST WITH: g++ -g -fsanitize=address 01_As_linked_list.cpp; ./01_As_linked_list.cpp;
   
Implement a linked list with the following design. You are free to add more functions.
#### *Hints*:

- `std::move` is defined in header `utility`
- `std::unique_ptr` is defined in header `memory`
- A `std::unique_ptr<T> p` has the following functions
   - `T* get() const` Returns a pointer to the managed object or `nullptr` if no object is owned.
   - `T* release()` Releases the ownership of the managed object if any. `get()` returns `nullptr` after the call.
   - `void reset(T* ptr=nullptr)` Delete `current_ptr` (if any) and set `current_ptr = ptr`.
   - To check if a `std::unique_ptr<T> p` is different from `nullptr` you can simply use `if(p)` (there is no need to write `if (p.get())`).

-  For a class `Foo`
    ```C++
    class Foo{
      Foo(); // default ctor
      Foo(const Foo& f); // copy ctor
      Foo(Foo&& f); // move ctor
      
      Foo& operator=(const Foo& f); // copy assignment
      Foo& operator=(Foo&& f); // move assignment
    };
    ```
You are required to use blocks of memory (*heap*) locations which are linked together. Each of these blocks contains one component that may refer to another block. If each block (except the final one) contains a pointer to the next block, so that they form a chain, then the entire collection of linked blocks is called a **linked list**. The blocks of memory locations of a linked list are usually called *nodes*.

Each node of a linked list, except the final one, points to its immediate *successor*, and each node except the first one is pointed to by its immediate *predecessor*. The pointer member of the last node has the value `nullptr`.

The private member `head` points to the first element of the list. 
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>

enum class method { push_back, push_front };

template <typename node, typename T>
class _iterator {
  node* current;

 public:
  using value_type = T;
  using reference = value_type&;
  using pointer = value_type*;
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::forward_iterator_tag;

  explicit _iterator(node* x) : current{x} {}
  reference operator*() const { return current->value; }
  _iterator& operator++() {  // pre-increment
    current = current->next.get();
    return *this;
  }
  _iterator operator++(int) {  // post-increment
    auto tmp = *this;
    ++(*this);
    return tmp;
  }
  friend bool operator==(const _iterator& x, const _iterator& y) {
    return x.current == y.current;
  }

  friend bool operator!=(const _iterator& x, const _iterator& y) {
    return !(x == y);
  }
};

template <typename T>
class List {
  struct node {
    T value;
    std::unique_ptr<node> next;
    node(const T& x, node* p)
        : value{x},  // copy ctor
          next{p} {}

    node(T&& x, node* p)
        : value{std::move(x)},  // move ctor
          next{p} {}

    explicit node(const std::unique_ptr<node>& p) : value{p->value} {
      if (p->next)
        next = std::make_unique<node>(p->next);
    }
  };
  std::unique_ptr<node> head;

 public:
  using iterator = _iterator<node, T>;
  using const_iterator = _iterator<node, const T>;

  void insert(const T& x, method m) { _insert(x, m); }
  void insert(T&& x, method m) { _insert(std::move(x), m); }

  List() = default;
  List(List&&) = default;
  List& operator=(List&&) = default;

  List(const List& that) {
    if (that.head)
      head = std::make_unique<node>(that.head);
  }

  List& operator=(const List& x) {
    head.reset();
    auto tmp = x;
    (*this) = std::move(tmp);
    return *this;
  }

  auto begin() { return iterator{head.get()}; }
  auto end() { return iterator{nullptr}; }

  auto begin() const { return const_iterator{head.get()}; }
  auto end() const { return const_iterator{nullptr}; }

  auto cbegin() const { return const_iterator{head.get()}; }
  auto cend() const { return const_iterator{nullptr}; }

  explicit List(std::initializer_list<T> l) {
    for (auto&& x : l)
      insert(std::move(x), method::push_back);
  }

 private:
  template <typename X>
  void _insert(X&& x, method m) {  // forwarding ref.
    if (!head) {                   // head == nullptr
      head = std::make_unique<node>(std::forward<X>(x), nullptr);
      return;
    }
    switch (m) {
      case method::push_back:
        push_back(std::forward<X>(x));
        break;
      case method::push_front:
        push_front(std::forward<X>(x));
        break;
      default:
        std::cerr << "unknown insertion method" << std::endl;
        break;
    };
  }

  node* last_node() {
    auto tmp = head.get();
    while (tmp->next)  // tmp->next != nullptr
      tmp = tmp->next.get();
    return tmp;
  }

  void push_back(const T& x) {
    auto tmp = last_node();
    tmp->next = std::make_unique<node>(x, nullptr);
  }
  void push_back(T&& x) {
    last_node()->next = std::make_unique<node>(std::move(x), nullptr);
  }

  void push_front(const T& x) {
    // auto tmp = new node{x,head.release()};
    // head.reset(tmp);

    // head.reset(new node{x,head.release()});

    head = std::make_unique<node>(x, head.release());

    // auto tmp = std::make_unique<node>(x,head.release());
    // head.swap(std::make_unique<node>(x,head.release()));
  }
  void push_front(T&& x) {
    // head = std::make_unique<node>(x,head.release()); // l-val
    head = std::make_unique<node>(std::move(x), head.release());  // r-val
  }
};

template <typename T>
void foo(const List<T>& x) {
  auto it = x.begin();
  // *it = 77;
}

int main() {
  List<int> l{4, 5, 6, 7, 7};

  std::vector<double> v{5, 0.0};

  // l.insert(3,method::push_front);
  // l.insert(4,method::push_front);
  // l.insert(5,method::push_back);

  // foo(l);
  auto it = std::find(l.cbegin(), l.cend(), 43);
  if (it != l.cend()) {
    // found!!
  }
  for (auto x : l)
    std::cout << x << std::endl;
}

template <typename I>
void foo(I first, I last, std::forward_iterator_tag) {}

template <typename I>
void foo(I first, I last, std::random_access_iterator_tag) {}

template <typename I>
void foo(I first, I last) {
  foo(first, last, typename I::iterator_category{});
}
