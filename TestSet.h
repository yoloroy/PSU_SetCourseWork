#ifndef SETCOURSEWORK_TESTSET_H
#define SETCOURSEWORK_TESTSET_H

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma ide diagnostic ignored "Simplify"

#include <iostream>
#include "Set.h"

namespace yoloroy::set {
    template<class TSet, class Set_t = Set<TSet>>
    inline void PrintSet(Set_t &set) {
        std::cout << "{ ";
        set.ForEach([](int v) { std::cout << v << " "; });
        std::cout << "}\n";
    }

    template<class TSet, class Set_t = Set<TSet>>
    void TestSet(
        Set_t &a,
        Set_t &b,
        Set_t &trash,
        const std::function<void()> &emptyTrash
    ) {
        std::cout << "  Тесты  " << " | Результаты\n";
        std::cout << ":--------" << ":|:-------------\n";

        for (int i = 0; i < 20; ++i) {
            a.Insert(std::rand() % 10);
        }
        std::cout << std::setw(10) << std::setfill(' ') << lily_ballard::centered("{A}") << "| ";
        PrintSet<TSet>(a);

        for (int i = 0; i < 20; ++i) {
            b.Insert(std::rand() % 8);
        }
        std::cout << std::setw(10) << std::setfill(' ') << lily_ballard::centered("{B}") << "| ";
        PrintSet<TSet>(b);

        std::cout << std::setw(10) << std::setfill(' ') << lily_ballard::centered("|A|") << "| " << a.Count() << "\n";
        std::cout << std::setw(10) << std::setfill(' ') << lily_ballard::centered("|B|") << "| " << b.Count() << "\n";

        std::cout << std::setw(10) << std::setfill(' ') << lily_ballard::centered("A >= A?") << "| " << ((a >= a) ? "+" : "-") << "\n";
        std::cout << std::setw(10) << std::setfill(' ') << lily_ballard::centered("A >= B?") << "| " << ((a >= b) ? "+" : "-") << "\n";
        std::cout << std::setw(10) << std::setfill(' ') << lily_ballard::centered("B >= A?") << "| " << ((b >= a) ? "+" : "-") << "\n";
        std::cout << std::setw(10) << std::setfill(' ') << lily_ballard::centered("A <=> A?") << "| " << ((a == a) ? "+" : "-") << "\n";
        std::cout << std::setw(10) << std::setfill(' ') << lily_ballard::centered("B <=> A?") << "| " << ((b == a) ? "+" : "-") << "\n";

        emptyTrash();
        a.Union(b, trash);
        std::cout << std::setw(10 + 2) << std::setfill(' ') << lily_ballard::centered("A ∪ B") << "| ";
        PrintSet<TSet>(trash);

        emptyTrash();
        a.Intersection(b, trash);
        std::cout << std::setw(10 + 2) << std::setfill(' ') << lily_ballard::centered("A ∩ B") << "| ";
        PrintSet<TSet>(trash);

        emptyTrash();
        a.Difference(b, trash);
        std::cout << std::setw(10) << std::setfill(' ') << lily_ballard::centered("A - B") << "| ";
        PrintSet<TSet>(trash);

        emptyTrash();
        b.Difference(a, trash);
        std::cout << std::setw(10) << std::setfill(' ') << lily_ballard::centered("B - A") << "| ";
        PrintSet<TSet>(trash);

        emptyTrash();
        a.SymmetricDifference(b, trash);
        std::cout << std::setw(10 + 1) << std::setfill(' ') << lily_ballard::centered("A Δ B") << "| ";
        PrintSet<TSet>(trash);
    }
}

#pragma clang diagnostic pop

#endif //SETCOURSEWORK_TESTSET_H
