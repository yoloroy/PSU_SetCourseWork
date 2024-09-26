#include "SetUsingStdUnorderedMultimap.h"

namespace yoloroy::set::std_impls {

    size_t SetUsingStdUnorderedMultimap::Count() {
        return map.size();
    }

    void SetUsingStdUnorderedMultimap::Insert(int item) {
        if (!Contains(item)) {
            map.insert(IntIntMap::value_type(item, item));
        }
    }

    void SetUsingStdUnorderedMultimap::Remove(int item) {
        map.erase(item);
    }

    void SetUsingStdUnorderedMultimap::Union(
        const SetUsingStdUnorderedMultimap &other, SetUsingStdUnorderedMultimap &destination
    ) const {
        destination = {};

        for (const auto &item: map) {
            destination.Insert(item.first);
        }
        for (const auto &item: other.map) {
            destination.Insert(item.first);
        }
    }

    void SetUsingStdUnorderedMultimap::Intersection(
        const SetUsingStdUnorderedMultimap &other, SetUsingStdUnorderedMultimap &destination
    ) const {
        destination = {};

        for (const auto &item: map) {
            if (other.Contains(item.first)) {
                destination.Insert(item.first);
            }
        }
    }

    void SetUsingStdUnorderedMultimap::Difference(
        const SetUsingStdUnorderedMultimap &other, SetUsingStdUnorderedMultimap &destination
    ) const {
        destination = SetUsingStdUnorderedMultimap();

        for (const auto &item: map) {
            if (!other.Contains(item.first)) {
                destination.Insert(item.first);
            }
        }
    }

    void SetUsingStdUnorderedMultimap::SymmetricDifference(
        const SetUsingStdUnorderedMultimap &other, SetUsingStdUnorderedMultimap &destination
    ) const {
        destination = SetUsingStdUnorderedMultimap();
        for (const auto &item: map) {
            if (!other.Contains(item.first)) {
                destination.Insert(item.first);
            }
        }
        for (const auto &item: other.map) {
            if (!Contains(item.first)) {
                destination.Insert(item.first);
            }
        }
    }

    bool SetUsingStdUnorderedMultimap::Contains(int item) const {
        return map.contains(item);
    }

    bool SetUsingStdUnorderedMultimap::operator>=(const SetUsingStdUnorderedMultimap &other) const {
        return std::all_of(
            other.map.begin(),
            other.map.end(),
            [this](const auto &item) {
                return this->Contains(item.first);
            });
    }

    bool SetUsingStdUnorderedMultimap::operator==(const SetUsingStdUnorderedMultimap &other) const {
        return *this >= other && other >= *this;
    }

    void SetUsingStdUnorderedMultimap::ForEach(std::function<void(int)> block) const {
        std::for_each(map.begin(), map.end(), [&](const std::pair<int, int> &item) { block(item.first); });
    }
}
