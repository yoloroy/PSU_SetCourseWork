#include "SetUsingStdList.h"

namespace yoloroy::set::std_impls {

    size_t SetUsingStdList::Count() {
        return list.size();
    }

    void SetUsingStdList::Insert(int item) {
        if (!Contains(item)) {
            list.push_back(item);
        }
    }

    void SetUsingStdList::Remove(int item) {
        list.remove(item);
    }

    void SetUsingStdList::Union(const SetUsingStdList &other, SetUsingStdList &destination) const {
        destination = {};

        for (const int &item: list) {
            if (other.Contains(item)) {
                destination.Insert(item);
            }
        }
    }

    void SetUsingStdList::Intersection(const SetUsingStdList &other, SetUsingStdList &destination) const {
        destination = {};

        for (const auto &item: list) {
            destination.Insert(item);
        }
        for (const auto &item: other.list) {
            if (!destination.Contains(item)) {
                destination.Insert(item);
            }
        }
    }

    void SetUsingStdList::Difference(const SetUsingStdList &other, SetUsingStdList &destination) const {
        destination = {};

        for (const auto &item: list) {
            if (!other.Contains(item)) {
                destination.Insert(item);
            }
        }
    }

    void SetUsingStdList::SymmetricDifference(const SetUsingStdList &other, SetUsingStdList &destination) const {
        destination = {};

        for (const auto &item: list) {
            if (!other.Contains(item)) {
                destination.Insert(item);
            }
        }
        for (const auto &item: other.list) {
            if (!Contains(item)) {
                destination.Insert(item);
            }
        }
    }

    bool SetUsingStdList::Contains(int item) const {
        return std::find(list.begin(), list.end(), item) != list.end();
    }

    bool SetUsingStdList::operator>=(const SetUsingStdList &other) const {
        return std::all_of(
            other.list.begin(),
            other.list.end(),
            [this](const int &item) { return this->Contains(item); }
        );
    }

    bool SetUsingStdList::operator==(const SetUsingStdList &other) const {
        return *this >= other && other >= *this;
    }

    void SetUsingStdList::ForEach(std::function<void(int)> block) const {
        std::for_each(list.begin(), list.end(), block);
    }
}
