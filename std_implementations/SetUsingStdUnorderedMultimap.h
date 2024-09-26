#ifndef SETCOURSEWORK_SETUSINGSTDUNORDEREDMULTIMAP_H
#define SETCOURSEWORK_SETUSINGSTDUNORDEREDMULTIMAP_H


#include <unordered_map>
#include "../Set.h"

namespace yoloroy::set::std_impls {
    class SetUsingStdUnorderedMultimap : public Set<SetUsingStdUnorderedMultimap> {
    public:
        size_t Count() override;

        void Insert(int item) override;

        void Remove(int item) override;

        void Union(const SetUsingStdUnorderedMultimap &other, SetUsingStdUnorderedMultimap &destination) const override;

        void Intersection(const SetUsingStdUnorderedMultimap &other, SetUsingStdUnorderedMultimap &destination) const override;

        void Difference(const SetUsingStdUnorderedMultimap &other, SetUsingStdUnorderedMultimap &destination) const override;

        void SymmetricDifference(const SetUsingStdUnorderedMultimap &other, SetUsingStdUnorderedMultimap &destination) const override;

        [[nodiscard]] bool Contains(int item) const override;

        [[nodiscard]] bool operator>=(const SetUsingStdUnorderedMultimap &other) const override;

        [[nodiscard]] bool operator==(const SetUsingStdUnorderedMultimap &other) const override;

        void ForEach(std::function<void (int)> block) const override;

    private:
        typedef std::unordered_multimap<int, int> IntIntMap;
        IntIntMap map{};
    };
}

#endif //SETCOURSEWORK_SETUSINGSTDUNORDEREDMULTIMAP_H
