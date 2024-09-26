#ifndef SETCOURSEWORK_MEASURETIME_H
#define SETCOURSEWORK_MEASURETIME_H

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma ide diagnostic ignored "Simplify"


#include "MeasureTime.h"
#include "Set.h"
#include <chrono>
#include <iostream>

namespace yoloroy::set {

    std::chrono::microseconds since(std::chrono::steady_clock::time_point const &start) {
        using namespace std::chrono;
        return std::chrono::duration_cast<microseconds>(steady_clock::now() - start);
    }

    const char TIME_TITLE[] = "Время";
    const char TIME_TITLE_DIVIDER[] = ":------";
    const char CASE_NAME_TITLE[] = "         Тест          ";
    const char CASE_NAME_TITLE_DIVIDER[] = ":----------------------:";
    const char CASE_NAME_INSERTION_A[] = " Заполнение множества А";
    const char CASE_NAME_INSERTION_B[] = " Заполнение множества B";
    const char CASE_NAME_COUNT_A[] = "  Мощность множества A ";
    const char CASE_NAME_COUNT_B[] = "  Мощность множества B ";
    const char CASE_NAME_A_INCLUDES_A[] = "     A включает A?     ";
    const char CASE_NAME_A_INCLUDES_B[] = "     A включает B?     ";
    const char CASE_NAME_B_INCLUDES_A[] = "     B включает A?     ";
    const char CASE_NAME_A_EQUALS_A[] = "        A == A?        ";
    const char CASE_NAME_B_EQUALS_A[] = "        B == A?        ";
    const char CASE_NAME_A_UNION_B[] = "         A ∪ B         ";
    const char CASE_NAME_A_INTERSECTION_B[] = "         A ∩ B         ";
    const char CASE_NAME_A_DIFF_B[] = "         A - B         ";
    const char CASE_NAME_B_DIFF_A[] = "         B - A         ";
    const char CASE_NAME_A_SYMMETRIC_DIFF_B[] = "         A Δ B         ";

    inline std::string FormatDuration(long long micros) {
        std::string result{};
        if (micros < 1'000) {
            return std::to_string(micros) + " (μs)";
        }
        else if (micros < 1'000'000) {
            return std::to_string(micros / 1000) + " (ms)";
        }
        else {
            return std::to_string(micros / 1'000'000) + " (s)";
        }
    }

    inline void PrintTiming(const char caseName[], const std::chrono::steady_clock::time_point &timePoint) {
        std::cout << caseName << " | " << FormatDuration(since(timePoint).count()) << std::endl;
    }

    template<class TSet, class Set_t = Set<TSet>>
    void MeasureTime(
        Set_t &a,
        Set_t &b,
        Set_t &trash,
        unsigned int setSize1,
        unsigned int setSize2,
        const std::function<void()> &emptyTrash
    ) {
        std::chrono::steady_clock::time_point start;

        std::cout << CASE_NAME_TITLE << " | " << TIME_TITLE << std::endl;
        std::cout << CASE_NAME_TITLE_DIVIDER << "|" << TIME_TITLE_DIVIDER << std::endl;

        start = std::chrono::steady_clock::now();
        for (int i = 0; i < setSize1; ++i) {
            a.Insert(std::rand() % 5000);
        }
        PrintTiming(CASE_NAME_INSERTION_A, start);

        start = std::chrono::steady_clock::now();
        for (int i = 0; i < setSize2; ++i) {
            b.Insert(std::rand() % 5000);
        }
        PrintTiming(CASE_NAME_INSERTION_B, start);

        start = std::chrono::steady_clock::now();
        a.Count();
        PrintTiming(CASE_NAME_COUNT_A, start);

        start = std::chrono::steady_clock::now();
        b.Count();
        PrintTiming(CASE_NAME_COUNT_B, start);

        start = std::chrono::steady_clock::now();
        a >= a;
        PrintTiming(CASE_NAME_A_INCLUDES_A, start);

        start = std::chrono::steady_clock::now();
        a >= b;
        PrintTiming(CASE_NAME_A_INCLUDES_B, start);

        start = std::chrono::steady_clock::now();
        b >= a;
        PrintTiming(CASE_NAME_B_INCLUDES_A, start);

        start = std::chrono::steady_clock::now();
        a == a;
        PrintTiming(CASE_NAME_A_EQUALS_A, start);

        start = std::chrono::steady_clock::now();
        b == a;
        PrintTiming(CASE_NAME_B_EQUALS_A, start);

        emptyTrash();
        start = std::chrono::steady_clock::now();
        a.Union(b, trash);
        PrintTiming(CASE_NAME_A_UNION_B, start);

        emptyTrash();
        start = std::chrono::steady_clock::now();
        a.Intersection(b, trash);
        PrintTiming(CASE_NAME_A_INTERSECTION_B, start);

        emptyTrash();
        start = std::chrono::steady_clock::now();
        a.Difference(b, trash);
        PrintTiming(CASE_NAME_A_DIFF_B, start);

        emptyTrash();
        start = std::chrono::steady_clock::now();
        b.Difference(a, trash);
        PrintTiming(CASE_NAME_B_DIFF_A, start);

        emptyTrash();
        start = std::chrono::steady_clock::now();
        a.SymmetricDifference(b, trash);
        PrintTiming(CASE_NAME_A_SYMMETRIC_DIFF_B, start);
    }
}

#pragma clang diagnostic pop

#endif //SETCOURSEWORK_MEASURETIME_H