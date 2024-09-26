#ifndef SETCOURSEWORK_SETUSINGSINGLYLINKEDLIST_H
#define SETCOURSEWORK_SETUSINGSINGLYLINKEDLIST_H


#include <utility>

#include "Set.h"

namespace yoloroy::set {

    class SetUsingSinglyLinkedList : public Set<SetUsingSinglyLinkedList> {
    public:
        size_t Count() override;

        void Insert(int item) override;

        void Remove(int item) override;

        void Union(const SetUsingSinglyLinkedList &other, SetUsingSinglyLinkedList &destination) const override;

        void Intersection(const SetUsingSinglyLinkedList &other, SetUsingSinglyLinkedList &destination) const override;

        void Difference(const SetUsingSinglyLinkedList &other, SetUsingSinglyLinkedList &destination) const override;

        void SymmetricDifference(const SetUsingSinglyLinkedList &other, SetUsingSinglyLinkedList &destination) const override;

        [[nodiscard]] bool Contains(int item) const override;

        [[nodiscard]] bool operator>=(const SetUsingSinglyLinkedList &other) const override;

        [[nodiscard]] bool operator==(const SetUsingSinglyLinkedList &other) const override;

        void ForEach(std::function<void (int)> block) const override;

    private:
        struct Node {
        public:
            int value;
            std::shared_ptr<Node> next;

            Node(int value, std::shared_ptr<Node> next) : value(value), next(std::move(next)) {
            }
        };

        std::shared_ptr<Node> root = nullptr;
    };
}

#endif //SETCOURSEWORK_SETUSINGSINGLYLINKEDLIST_H
