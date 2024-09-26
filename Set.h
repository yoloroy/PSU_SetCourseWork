#ifndef SETCOURSEWORK_SET_H
#define SETCOURSEWORK_SET_H

#include <memory>
#include <functional>

namespace yoloroy::set {
    template<class OtherSet>
    class Set {
    public:
        virtual size_t Count() = 0;

        virtual void Insert(int item) = 0;

        virtual void Remove(int item) = 0;

        virtual void Union(const OtherSet &other, OtherSet &destination) const = 0;

        virtual void Intersection(const OtherSet &other, OtherSet &destination) const = 0;

        virtual void Difference(const OtherSet &other, OtherSet &destination) const = 0;

        virtual void SymmetricDifference(const OtherSet &other, OtherSet &destination) const = 0;

        virtual bool Contains(int item) const = 0; // NOLINT(*-use-nodiscard)

        virtual bool operator>=(const OtherSet &other) const = 0;

        virtual bool operator==(const OtherSet &other) const = 0;

        virtual void ForEach(std::function<void (int)> block) const = 0;
    };
}

#endif //SETCOURSEWORK_SET_H
