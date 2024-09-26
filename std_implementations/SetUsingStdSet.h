#ifndef SETCOURSEWORK_SETUSINGSTDSET_H
#define SETCOURSEWORK_SETUSINGSTDSET_H


#include <set>
#include "../Set.h"

namespace yoloroy::set::std_impls {
    class SetUsingStdSet : Set<SetUsingStdSet> {
    public:
        size_t Count() override;

        void Insert(int item) override;

        void Remove(int item) override;

        void Union(const SetUsingStdSet &other, SetUsingStdSet &destination) const override;

        void Intersection(const SetUsingStdSet &other, SetUsingStdSet &destination) const override;

        void Difference(const SetUsingStdSet &other, SetUsingStdSet &destination) const override;

        void SymmetricDifference(const SetUsingStdSet &other, SetUsingStdSet &destination) const override;

        [[nodiscard]] bool Contains(int item) const override;

        [[nodiscard]] bool operator>=(const SetUsingStdSet &other) const override;

        [[nodiscard]] bool operator==(const SetUsingStdSet &other) const override;

        void ForEach(std::function<void (int)> block) const override;

    private:
        std::set<int> set{};
    };
}

#endif //SETCOURSEWORK_SETUSINGSTDSET_H
