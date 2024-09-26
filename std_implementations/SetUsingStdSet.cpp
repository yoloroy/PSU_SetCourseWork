#include "SetUsingStdSet.h"

namespace yoloroy::set::std_impls {

    size_t SetUsingStdSet::Count() {
        return set.size();
    }

    void SetUsingStdSet::Insert(int item) {
        set.insert(item);
    }

    void SetUsingStdSet::Remove(int item) {
        set.erase(item);
    }

    void SetUsingStdSet::Union(const SetUsingStdSet &other, SetUsingStdSet &destination) const {
        destination = {};

        for (const auto &item: set) {
            destination.Insert(item);
        }

        for (const auto &item: other.set) {
            destination.Insert(item);
        }
    }

    void SetUsingStdSet::Intersection(const SetUsingStdSet &other, SetUsingStdSet &destination) const {
        destination = {};

        for (const auto &item: set) {
            if (other.Contains(item)) {
                destination.Insert(item);
            }
        }
    }

    void SetUsingStdSet::Difference(const SetUsingStdSet &other, SetUsingStdSet &destination) const {
        destination = {};

        for (const auto &item: set) {
            if (!other.Contains(item)) {
                destination.Insert(item);
            }
        }
    }

    void SetUsingStdSet::SymmetricDifference(const SetUsingStdSet &other, SetUsingStdSet &destination) const {
        destination = {};

        for (const auto &item: set) {
            if (!other.Contains(item)) {
                destination.Insert(item);
            }
        }
        for (const auto &item: other.set) {
            if (!Contains(item)) {
                destination.Insert(item);
            }
        }
    }

    bool SetUsingStdSet::Contains(int item) const {
        return set.contains(item);
    }

    bool SetUsingStdSet::operator>=(const SetUsingStdSet &other) const {
        return std::all_of(other.set.begin(), other.set.end(), [this](const int item) { return this->Contains(item); });
    }

    bool SetUsingStdSet::operator==(const SetUsingStdSet &other) const {
        return *this >= other && other >= *this;
    }

    void SetUsingStdSet::ForEach(std::function<void(int)> block) const {
        std::for_each(set.begin(), set.end(), block);
    }
}
