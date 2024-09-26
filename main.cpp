#include "MeasureTime.h"
#include "std_implementations/SetUsingStdForwardList.h"
#include "std_implementations/SetUsingStdUnorderedMultimap.h"
#include "std_implementations/SetUsingStdList.h"
#include "std_implementations/SetUsingStdSet.h"
#include "util/centered.h"
#include "SetUsingSinglyLinkedList.h"
#include "TestSet.h"
#include <iostream>
#include <iomanip>

void HumanTests();

void Measures();

int main() {
    using namespace yoloroy::set;
    using namespace std_impls;

    srand(time(nullptr)); // NOLINT(*-msc51-cpp)

#ifdef _DEBUG
    HumanTests();
#endif
    Measures();

    return 0;
}

template<class SetT>
void TestCase() {
    SetT a{};
    SetT b{};
    SetT trash{};
    TestSet<SetT>(a, b, trash, [&trash]() { trash = {}; });
}

void HumanTests() {
    using namespace yoloroy::set;
    using namespace std_impls;

    std::cout << std::setw(40) << std::setfill('=') << lily_ballard::centered("TESTS") << "\n\n";

    std::cout << std::setw(40) << std::setfill('.') << lily_ballard::centered("SetUsingStdForwardList") << "\n\n";
    TestCase<SetUsingStdForwardList>();
    std::cout << std::endl;

    std::cout << std::setw(40) << std::setfill('.') << lily_ballard::centered("SetUsingStdUnorderedMultimap") << "\n\n";
    TestCase<SetUsingStdUnorderedMultimap>();
    std::cout << std::endl;

    std::cout << std::setw(40) << std::setfill('.') << lily_ballard::centered("SetUsingStdList") << "\n\n";
    TestCase<SetUsingStdList>();
    std::cout << std::endl;

    std::cout << std::setw(40) << std::setfill('.') << lily_ballard::centered("SetUsingStdSet") << "\n\n";
    TestCase<SetUsingStdSet>();
    std::cout << std::endl;

    std::cout << std::setw(40) << std::setfill('.') << lily_ballard::centered("SetUsingSinglyLinkedList") << "\n\n";
    TestCase<SetUsingSinglyLinkedList>();
    std::cout << std::endl;
}

template<class SetT>
void MeasureCase() {
    SetT a{};
    SetT b{};
    SetT trash{};
    MeasureTime<SetT>(a, b, trash, 400000, 400000, [&trash]() { trash = {}; });
}

void Measures() {
    using namespace yoloroy::set;
    using namespace std_impls;

    std::cout << std::setw(40) << std::setfill('=') << lily_ballard::centered("MEASURES") << "\n\n";

    std::cout << std::setw(40) << std::setfill('.') << lily_ballard::centered("SetUsingStdForwardList") << "\n\n";
    MeasureCase<SetUsingStdForwardList>();
    std::cout << std::endl;

    std::cout << std::setw(40) << std::setfill('.') << lily_ballard::centered("SetUsingStdUnorderedMultimap") << "\n\n";
    MeasureCase<SetUsingStdUnorderedMultimap>();
    std::cout << std::endl;

    std::cout << std::setw(40) << std::setfill('.') << lily_ballard::centered("SetUsingStdList") << "\n\n";
    MeasureCase<SetUsingStdList>();
    std::cout << std::endl;

    std::cout << std::setw(40) << std::setfill('.') << lily_ballard::centered("SetUsingStdSet") << "\n\n";
    MeasureCase<SetUsingStdSet>();
    std::cout << std::endl;

    std::cout << std::setw(40) << std::setfill('.') << lily_ballard::centered("SetUsingSinglyLinkedList") << "\n\n";
    MeasureCase<SetUsingSinglyLinkedList>();
    std::cout << std::endl;
}
