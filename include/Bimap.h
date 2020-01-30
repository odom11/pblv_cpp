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
#include <model/Data.h>
#include <Coordinate.h>

std::ostream& operator<<(std::ostream& os, const Coordinate& coordinate);

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

    Value& get(Key& key) {
        return findInMap(&key, forward);
        auto it = forward.find(&key);
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
};

#endif //POPULATIONDYNAMICS_BIMAP_H
