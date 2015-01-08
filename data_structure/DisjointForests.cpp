#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

template<typename T>
class DisjointForests;

template<typename T>
class DisjointSet
{
public:
    DisjointSet(const T& element): _element(element), _rank(1) {
        _parent = this;
    }
    DisjointSet<T>* getParent() const { return _parent; }
    const DisjointSet<T>* getAncestor() const {
        return  (_parent == this) ? this : this->_parent->getAncestor();        
    }
    void setParent(DisjointSet<T>* parent) { this->_parent = parent; }
    const int getRank() const { return _rank; }    
    void incRank(int inc) { _rank += inc; }
    const T& getElement() const { return this->_element;  }

    friend class DisjointForests<T>;
private:
    DisjointSet<T> *_parent;
    T _element;
    int _rank;
};

template<typename T>
class DisjointForests
{
public:
    DisjointForests() {}

    ~DisjointForests() {
        for (auto kv : _map)
            delete kv.second; 
        _map.clear();
    }

    void makeSet(const T& x) {
        if (_map.count(x)) { 
            cerr << "key " << x << " alread exists!" << endl; 
            return; 
        }
        _map[x] = new DisjointSet<T>(x);        
    }

    DisjointSet<T>* findSet(const T& x) {
        if (!_map.count(x)) return nullptr;
        DisjointSet<T>* s = _map[x];
        return this->findSet(s);
    }

    void unionSets(const T& a, const T& b) {
        DisjointSet<T>* sa = this->findSet(a);
        DisjointSet<T>* sb = this->findSet(b);

        if (sa->getAncestor() == sb->getAncestor()) {
            cerr << a << " and " << b << " are already in the same set!" << endl;
            return;
        }

        if (sa->getRank() > sb->getRank()) {
            sb->setParent(sa);
            sa->incRank(sb->getRank());
        } else {
            sa->setParent(sb);
            sb->incRank(sa->getRank());
        }
    }

    void print(ostream& os) {
        for (auto kv : _map) 
            os << "key = " << kv.first << " parent.key = " << kv.second->getParent()->getElement() << " ancestor.key = " << kv.second->getAncestor()->getElement() << endl;
        cout << string(40, '-') << endl;
    }
private:
    DisjointSet<T>* findSet(DisjointSet<T>* s) {        
        if (s->getParent() != s)
            s->setParent(this->findSet(s->getParent()));        
        return s->getParent();
    }

    unordered_map<T, DisjointSet<T>*> _map;
};

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
