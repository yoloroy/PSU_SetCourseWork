#ifndef SETCOURSEWORK_SETUSINGSTDLIST_H
#define SETCOURSEWORK_SETUSINGSTDLIST_H


#include <list>
#include "../Set.h"

namespace yoloroy::set::std_impls {
    class SetUsingStdList : Set<SetUsingStdList> {
    public:
        size_t Count() override;

        void Insert(int item) override;

        void Remove(int item) override;

        void Union(const SetUsingStdList &other, SetUsingStdList &destination) const override;

        void Intersection(const SetUsingStdList &other, SetUsingStdList &destination) const override;

        void Difference(const SetUsingStdList &other, SetUsingStdList &destination) const override;

        void SymmetricDifference(const SetUsingStdList &other, SetUsingStdList &destination) const override;

        [[nodiscard]] bool Contains(int item) const override;

        [[nodiscard]] bool operator>=(const SetUsingStdList &other) const override;

        [[nodiscard]] bool operator==(const SetUsingStdList &other) const override;

        void ForEach(std::function<void (int)> block) const override;

    private:
        std::list<int> list;
    };
}

#endif //SETCOURSEWORK_SETUSINGSTDLIST_H
