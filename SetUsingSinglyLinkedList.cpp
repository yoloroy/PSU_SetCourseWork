#include "SetUsingSinglyLinkedList.h"

namespace yoloroy::set {

    size_t SetUsingSinglyLinkedList::Count() {
        size_t count = 0;
        ForEach([&count](int _) { count++; });
        return count;
    }

    void SetUsingSinglyLinkedList::Insert(int item) {
        if (root == nullptr) {
            root = std::make_shared<Node>(item, nullptr);
            return;
        }

        std::shared_ptr<Node> *current = &root;
        while (*current != nullptr && (*current)->value < item) {
            current = &(*current)->next;
        }

        bool foundPlaceToInsert = *current == nullptr || (*current)->value != item;
        if (foundPlaceToInsert) {
            *current = std::make_shared<Node>(item, *current);
        }
    }

    void SetUsingSinglyLinkedList::Remove(int item) {
        if (root == nullptr || root->value > item) {
            return;
        }
        if (root->value == item) {
            root = root->next;
            return;
        }

        std::shared_ptr<Node> cursor = root;
        while (cursor->next != nullptr && cursor->next->value < item) {
            cursor = cursor->next;
        }

        if (cursor->next == nullptr) {
            return;
        }
        if (cursor->next->value == item) {
            cursor->next = cursor->next->next;
        }
    }

    void SetUsingSinglyLinkedList::Union(
        const SetUsingSinglyLinkedList &other,
        SetUsingSinglyLinkedList &destination
    ) const {
        destination = {};

        std::shared_ptr<Node> destP;
        std::shared_ptr<Node> thisP = root;
        std::shared_ptr<Node> otherP = other.root;

        if (thisP->value < otherP->value) {
            destination.root = std::make_shared<Node>(thisP->value, nullptr);
            thisP = thisP->next;
        } else if (thisP->value > otherP->value) {
            destination.root = std::make_shared<Node>(otherP->value, nullptr);
            otherP = otherP->next;
        } else {
            destination.root = std::make_shared<Node>(thisP->value, nullptr);
            thisP = thisP->next;
            otherP = otherP->next;
        }

        destP = destination.root;

        while (thisP != nullptr && otherP != nullptr) {
            if (thisP->value < otherP->value) {
                destP->next = std::make_shared<Node>(thisP->value, nullptr);
                thisP = thisP->next;
            } else if (thisP->value > otherP->value) {
                destP->next = std::make_shared<Node>(otherP->value, nullptr);
                otherP = otherP->next;
            } else {
                destP->next = std::make_shared<Node>(thisP->value, nullptr);
                thisP = thisP->next;
                otherP = otherP->next;
            }
            destP = destP->next;
        }

        while (thisP != nullptr) {
            destP->next = std::make_shared<Node>(thisP->value, nullptr);
            thisP = thisP->next;
            destP = destP->next;
        }
        while (otherP != nullptr) {
            destP->next = std::make_shared<Node>(otherP->value, nullptr);
            otherP = otherP->next;
            destP = destP->next;
        }
    }

    void SetUsingSinglyLinkedList::Intersection(
        const SetUsingSinglyLinkedList &other,
        SetUsingSinglyLinkedList &destination
    ) const {
        destination = {};

        if (root == nullptr || other.root == nullptr) {
            return;
        }

        std::shared_ptr<Node> *destP = &destination.root;
        std::shared_ptr<Node> greater = (this->root->value > other.root->value) ? this->root : other.root;
        std::shared_ptr<Node> lesser = (this->root == greater) ? other.root : this->root;

        while (greater != nullptr && lesser != nullptr) {
            if (greater->value < lesser->value) {
                std::swap(greater, lesser);
            }

            while (greater != nullptr && greater->value > lesser->value) {
                lesser = lesser->next;
            }

            if (lesser == nullptr) {
                break;
            }

            if (greater->value == lesser->value) {
                *destP = std::make_shared<Node>(greater->value, nullptr);
                destP = &(*destP)->next;
                greater = greater->next;
                lesser = lesser->next;
            }
        }
    }

    void SetUsingSinglyLinkedList::Difference(
        const SetUsingSinglyLinkedList &other,
        SetUsingSinglyLinkedList &destination
    ) const {
        destination = {};

        if (this->root == nullptr) {
            return;
        }

        std::shared_ptr<Node> *pDestNode = &destination.root;
        std::shared_ptr<Node> thisNode = this->root;
        std::shared_ptr<Node> otherNode = other.root;
        while (otherNode != nullptr && thisNode != nullptr) {
            if (thisNode->value == otherNode->value) {
                thisNode = thisNode->next;
                otherNode = otherNode->next;
            }
            else if (thisNode->value < otherNode->value) {
                *pDestNode = std::make_shared<Node>(thisNode->value, nullptr);
                pDestNode = &(*pDestNode)->next;
                thisNode = thisNode->next;
            }
            else if (thisNode->value > otherNode->value) {
                otherNode = otherNode->next;
            }
        }

        while (thisNode != nullptr) {
            *pDestNode = std::make_shared<Node>(thisNode->value, nullptr);
            pDestNode = &(*pDestNode)->next;
            thisNode = thisNode->next;
        }
    }

    void SetUsingSinglyLinkedList::SymmetricDifference(
        const SetUsingSinglyLinkedList &other,
        SetUsingSinglyLinkedList &destination
    ) const {
        destination = {};

        if (this->root == nullptr) {
            return;
        }

        std::shared_ptr<Node> *pDestNode = &destination.root;
        std::shared_ptr<Node> thisNode = this->root;
        std::shared_ptr<Node> otherNode = other.root;
        while (otherNode != nullptr && thisNode != nullptr) {
            if (thisNode->value == otherNode->value) {
                thisNode = thisNode->next;
                otherNode = otherNode->next;
            }
            else if (thisNode->value < otherNode->value) {
                *pDestNode = std::make_shared<Node>(thisNode->value, nullptr);
                pDestNode = &(*pDestNode)->next;
                thisNode = thisNode->next;
            }
            else if (thisNode->value > otherNode->value) {
                *pDestNode = std::make_shared<Node>(otherNode->value, nullptr);
                pDestNode = &(*pDestNode)->next;
                otherNode = otherNode->next;
            }
        }

        while (thisNode != nullptr) {
            *pDestNode = std::make_shared<Node>(thisNode->value, nullptr);
            pDestNode = &(*pDestNode)->next;
            thisNode = thisNode->next;
        }
    }

    bool SetUsingSinglyLinkedList::Contains(int item) const {
        auto thisNode = this->root;

        while (thisNode != nullptr && item < thisNode->value) {
            thisNode = thisNode->next;
        }

        if (thisNode == nullptr) {
            return false;
        }
        if (thisNode->value > item) {
            return false;
        }

        return true;
    }

    bool SetUsingSinglyLinkedList::operator>=(const SetUsingSinglyLinkedList &other) const {
        if (other.root == nullptr) {
            return true;
        }

        auto thisNode = this->root;
        for (auto otherNode = other.root; otherNode->next != nullptr; otherNode = otherNode->next) {
            while (thisNode != nullptr && thisNode->value > otherNode->value) {
                thisNode = thisNode->next;
            }

            if (thisNode == nullptr) {
                return false;
            }
            if (thisNode->value > otherNode->value) {
                return false;
            }
        }

        return true;
    }

    bool SetUsingSinglyLinkedList::operator==(const SetUsingSinglyLinkedList &other) const {
        auto p1 = root;
        auto p2 = other.root;

        while (p1 != nullptr && p2 != nullptr && p1->value == p2->value) {
            p1 = p1->next;
            p2 = p2->next;
        }

        auto bothFinishedWithoutMismatches = p1 == nullptr && p2 == nullptr;
        return bothFinishedWithoutMismatches;
    }

    void SetUsingSinglyLinkedList::ForEach(std::function<void(int)> block) const {
        for (auto pCurrent = root; pCurrent != nullptr; pCurrent = pCurrent->next) {
            block(pCurrent->value);
        }
    }
}
