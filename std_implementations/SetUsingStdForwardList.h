#ifndef SETCOURSEWORK_SETUSINGSTDFORWARDLIST_H
#define SETCOURSEWORK_SETUSINGSTDFORWARDLIST_H

#include <forward_list>
#include "../Set.h"

namespace yoloroy::set::std_impls {
    class SetUsingStdForwardList : public Set<SetUsingStdForwardList> {
    public:
        size_t Count() override;

        void Insert(int item) override;

        void Remove(int item) override;

        void Union(const SetUsingStdForwardList &other, SetUsingStdForwardList &destination) const override;

        void Intersection(const SetUsingStdForwardList &other, SetUsingStdForwardList &destination) const override;

        void Difference(const SetUsingStdForwardList &other, SetUsingStdForwardList &destination) const override;

        void SymmetricDifference(const SetUsingStdForwardList &other, SetUsingStdForwardList &destination) const override;

        [[nodiscard]] bool Contains(int item) const override;

        [[nodiscard]] bool operator>=(const SetUsingStdForwardList &other) const override;

        [[nodiscard]] bool operator==(const SetUsingStdForwardList &other) const override;

        void ForEach(std::function<void (int)> block) const override;

    private:
        std::forward_list<int> list{};
    };
}

#endif //SETCOURSEWORK_SETUSINGSTDFORWARDLIST_H
