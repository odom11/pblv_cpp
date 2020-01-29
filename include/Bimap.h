//
// Created by ich on 1/29/20.
//

#ifndef POPULATIONDYNAMICS_BIMAP_H
#define POPULATIONDYNAMICS_BIMAP_H


#include <map>
template <typename Key, typename Value>
using Map = std::map<Key, Value>;

template <typename Key, typename Value>
Value& findInMap(const Key& key, Map<Key, Value>& map) {
    auto it = map.find(key);
    if (it == map.end()) {
        throw std::runtime_error("did not find key in map");
    }
    return it->second;
}

template <typename Key, typename Value>
class Bimap {
private:
    Map<Key*, Value> forward;
    Map<Value, Key*> backward;
public:
    //Key& get(Value& value) {
    //    auto it = backward.find(value);
    //    if (it == backward.end()) {
    //        throw std::runtime_error("");
    //    }
    //    //return *findInMap(value, backward);
    //}
//
    Value& get(Key& key) {
        return findInMap(&key, forward);
        auto it = forward.find(&key);
    }
//
//    bool contains(Key& key) {
//        return containsKey(forward, key);
//    }
//
//    bool contains(Value& value) {
//        return containsKey(backward, value);
//    }
//
//    bool update(Key& key, Value& value) {
//        assert(contains(key) && contains(value));
//        forward[key] = &value;
//        backward[value] = &key;
//    }
};

#endif //POPULATIONDYNAMICS_BIMAP_H
