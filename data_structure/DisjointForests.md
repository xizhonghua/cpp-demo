## [Disjoint Forests](./DisjointForests.cpp)
### Interface

```C++
template<typename T>
class DisjointForests
{
public:
    DisjointForests();
    ~DisjointForests();

    void makeSet(const T& x);
    void unionSets(const T& a, const T& b);
    bool intersects(const T& a, const T& b);
    void print(ostream& os);
private:
    DisjointSet<T>* findSet(const T& x);
    DisjointSet<T>* findSet(DisjointSet<T>* s);
    unordered_map<T, DisjointSet<T>*> _map;
};
```

### Implmentation
See code [DisjointForests.cpp](./DisjointForests.cpp)

### Test
```C++
int main(int argc, char** argv)
{
    DisjointForests<char> df;    
    df.makeSet('b');
    df.makeSet('h');
    df.makeSet('e');
    df.makeSet('c');

    // duplicated key
    df.makeSet('c');

    df.unionSets('b', 'h');
    df.unionSets('e', 'c');
    df.unionSets('c', 'b');    

    // already in the same set
    df.unionSets('c', 'h');

    df.print(cout);    

    df.makeSet('f');
    df.makeSet('d');
    df.unionSets('d', 'f');
    df.makeSet('g');
    df.unionSets('f', 'g');

    df.print(cout);

    df.unionSets('c', 'f');

    df.print(cout);

    return 0;
}
```

### Output

```
key c alread exists!
c and h are already in the same set!
key = b parent.key = h ancestor.key = h
key = h parent.key = h ancestor.key = h
key = e parent.key = c ancestor.key = h
key = c parent.key = h ancestor.key = h
----------------------------------------
key = b parent.key = h ancestor.key = h
key = h parent.key = h ancestor.key = h
key = e parent.key = c ancestor.key = h
key = c parent.key = h ancestor.key = h
key = f parent.key = f ancestor.key = f
key = d parent.key = f ancestor.key = f
key = g parent.key = f ancestor.key = f
----------------------------------------
key = b parent.key = h ancestor.key = h
key = h parent.key = h ancestor.key = h
key = e parent.key = c ancestor.key = h
key = c parent.key = h ancestor.key = h
key = f parent.key = h ancestor.key = h
key = d parent.key = f ancestor.key = h
key = g parent.key = f ancestor.key = h
----------------------------------------
```
