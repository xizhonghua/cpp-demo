### [Disjoint Forests](./DisjointForests.cpp)

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
