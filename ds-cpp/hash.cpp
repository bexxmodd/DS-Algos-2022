#include <iostream>
#include <functional>
#include <list>
#include <vector>

template <typename K, typename V, typename H>
class HashMap {
public:
    typedef std::pair<const K, V> Entry;
    class Iterator;

    HashMap(int capacity = 101);
    int size() const;
    bool empty() const;
    Iterator find(const K& key);
    Iterator insert(const K& key, const V& value);
    void erase(const K& key);
    void erase(const V& value);
    Iterator begin();
    Iterator end();

protected:
    typedef std::list<Entry> Bucket;
    typedef std::vector<Bucket> BucketArray;

private:
    int n;
    H hashCode;
    BucketArray B;
};


int main() {
    return 0;
}
