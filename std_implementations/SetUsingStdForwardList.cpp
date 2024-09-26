#include "SetUsingStdForwardList.h"

namespace yoloroy::set::std_impls {

    size_t SetUsingStdForwardList::Count() {
        size_t count = 0;
        ForEach([&count](int _) { count++; });
        return count;
    }

    void SetUsingStdForwardList::Insert(int item) {
        if (!Contains(item)) {
            list.push_front(item);
        }
    }

    void SetUsingStdForwardList::Remove(int item) {
        list.remove(item);
    }

    void SetUsingStdForwardList::Union(const SetUsingStdForwardList &other, SetUsingStdForwardList &destination) const {
        destination = {};

        ForEach([&destination](int v) { destination.Insert(v); });
        other.ForEach([&destination](int v) { destination.Insert(v); });
    }

    void SetUsingStdForwardList::Intersection(
        const SetUsingStdForwardList &other, SetUsingStdForwardList &destination
    ) const {
        destination = SetUsingStdForwardList();

        ForEach([&destination, &other](int v) {
            if (other.Contains(v)) {
                destination.Insert(v);
            }
        });
    }

    void SetUsingStdForwardList::Difference(const SetUsingStdForwardList &other, SetUsingStdForwardList &destination) const {
        destination = {};

        ForEach([&destination, &other](int v) {
            if (!other.Contains(v)) {
                destination.Insert(v);
            }
        });
    }

    void SetUsingStdForwardList::SymmetricDifference(
        const SetUsingStdForwardList &other, SetUsingStdForwardList &destination
    ) const {
        destination = SetUsingStdForwardList();

        ForEach([&destination, &other](int v) {
            if (!other.Contains(v)) {
                destination.Insert(v);
            }
        });
        other.ForEach([&destination, this](int v) {
            if (!this->Contains(v)) {
                destination.Insert(v);
            }
        });
    }

    bool SetUsingStdForwardList::Contains(int item) const {
        return std::find(list.begin(), list.end(), item) != list.end();
    }

    bool SetUsingStdForwardList::operator>=(const SetUsingStdForwardList &other) const {
        return std::all_of(
            other.list.begin(),
            other.list.end(),
            [this](const int &item) { return this->Contains(item); }
        );
    }

    bool SetUsingStdForwardList::operator==(const SetUsingStdForwardList &other) const {
        return *this >= other && other >= *this;
    }

    void SetUsingStdForwardList::ForEach(std::function<void(int)> block) const {
        std::for_each(list.begin(), list.end(), block);
    }
}
