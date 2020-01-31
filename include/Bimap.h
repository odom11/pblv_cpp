//
// Created by ich on 1/29/20.
//

#ifndef POPULATIONDYNAMICS_BIMAP_H
#define POPULATIONDYNAMICS_BIMAP_H

#include <iostream>
#include <cassert>
#include <memory>
#include <iostream>
#include <map>
#include <iterator>
#include <model/Data.h>
#include <Coordinate.h>


template <typename Key, typename Value>
using Map = std::map<Key, Value>;

template <typename Key, typename Value>
Value& findInMap(const Key& key, Map<Key, Value>& map) {
    auto it = map.find(key);
    assert(it != map.end());
    return it->second;
}

template <typename Key, typename Value>
class Bimap {
private:
    Map<Key*, Value> forward;
    Map<Value, std::unique_ptr<Key>> backward;
    public:

    template<bool isconst>
    class Iterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using size_type = std::size_t;
        using value_type = std::pair<Key, Value>;
        using pointer = typename std::conditional<isconst, const value_type *, value_type *>::type;
        using reference = typename std::conditional<isconst, std::pair<const Key&, const Value&>, std::pair<Key&, Value&> >::type;
        using innerIteratorType =  typename std::conditional<isconst, typename decltype(forward)::const_iterator, typename decltype(forward)::iterator>::type;
        friend class Iterator<!isconst>;
        Iterator(innerIteratorType it ) : iterator(it) {};

        Iterator<isconst>& operator++() {
            ++iterator;
            return *this;
        }

        Iterator<isconst>& operator++(int) {
            Iterator<isconst> tmp = *this;
            ++(*this);
            return tmp;
        }

        Iterator<isconst>& operator--() {
            --iterator;
            return *this;
        }

        Iterator<isconst>&operator--(int) {
            Iterator<isconst> tmp = *this;
            --(*this);
            return tmp;
        }

        bool operator!=(Iterator<isconst>& rhs) {
            return this->iterator != rhs.iterator;
        }

        reference operator*() {
            using f1 = typename std::conditional<isconst, const Key&, Key&>::type;
            using f2 = typename std::conditional<isconst, const Value&, Value&>::type;
            return std::pair<f1, f2>(*iterator->first, iterator->second);
        }

    private:
         innerIteratorType iterator;
    };

    using iterator = Iterator<true>;
    using const_iterator = Iterator<false>;

    Key& get(const Value& value) {
        return *findInMap(value, backward);
    }

    Value& get(Key& key) {
        return findInMap(&key, forward);
    }

    bool contains(Key& key) const {
        return forward.find(&key) != forward.end();
    }

    bool contains(const Value& value) const {
        return backward.find(value) != backward.end();
    }

    void insert(std::unique_ptr<Key> keyRsrcMngr, const Value& value) {
        assert(!contains(*keyRsrcMngr) && !contains(value));
        forward.insert(std::make_pair(keyRsrcMngr.get(), value));
        backward.insert(std::make_pair(value, std::move(keyRsrcMngr)));
    }

    void update(Key& key, const Value& value) {
        assert(contains(key));
        assert(!contains(value));
        const auto& oldValue = forward.find(&key)->second;
        auto it = backward.find(oldValue);
        std::unique_ptr<Key> newResourceManager = std::move(it->second);
        backward.erase(oldValue);
        forward.erase(&key);
        forward.insert(std::make_pair(&key, value));
        backward.insert(std::make_pair(value, std::move(newResourceManager)));
    }

    int size() {
        assert(forward.size() == backward.size());
        return forward.size();
    }

    void remove(Key& key) {
        assert(contains(key));
        auto it = forward.find(&key);
        auto jt = backward.find(it->second);
        forward.erase(it);
        backward.erase(jt);
    }

    void clear() {
        forward.clear();
        backward.clear();
    }

    iterator begin() {
        return iterator(forward.begin());
    }

    const_iterator begin() const {
        return const_iterator(forward.begin());
    }

    iterator end() {
        return iterator(forward.end());
    }

    const_iterator end() const {
        return const_iterator(forward.end());
    }
};

#endif //POPULATIONDYNAMICS_BIMAP_H
