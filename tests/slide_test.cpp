#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include "../src/slide.hpp"
#include <vector>
#include<iostream>

using Catch::Matchers::Equals;


static std::vector<int> toVec(const int* arr, int size) {
    return std::vector<int>(arr, arr + size);
}


TEST_CASE("arrayShift – single shifts of 1", "[arrayShift]") {
    int arr[] = {1, 2, 3, 4, 5};

    arrayShift(arr, 5, 1);
    REQUIRE_THAT(toVec(arr, 5), Equals(std::vector<int>{2, 3, 4, 5, 1}));

    arrayShift(arr, 5, 1);
    REQUIRE_THAT(toVec(arr, 5), Equals(std::vector<int>{3, 4, 5, 1, 2}));

    arrayShift(arr, 5, 1);
    REQUIRE_THAT(toVec(arr, 5), Equals(std::vector<int>{4, 5, 1, 2, 3}));
}

TEST_CASE("arrayShift – shifts of 3", "[arrayShift]") {
    int arr[] = {1, 2, 3, 4, 5};

    arrayShift(arr, 5, 3);
    REQUIRE_THAT(toVec(arr, 5), Equals(std::vector<int>{4, 5, 1, 2, 3}));

    arrayShift(arr, 5, 3);
    REQUIRE_THAT(toVec(arr, 5), Equals(std::vector<int>{2, 3, 4, 5, 1}));

    arrayShift(arr, 5, 3);
    REQUIRE_THAT(toVec(arr, 5), Equals(std::vector<int>{5, 1, 2, 3, 4}));
}

TEST_CASE("arrayShift – shifts equal to array size is a no-op", "[arrayShift][edge]") {
    int arr[] = {1, 2, 3};
    arrayShift(arr, 3, 3);
    REQUIRE_THAT(toVec(arr, 3), Equals(std::vector<int>{1, 2, 3}));
}

TEST_CASE("arrayShift – shifts larger than size uses modulo", "[arrayShift][edge]") {
    int arr[] = {1, 2, 3};
    arrayShift(arr, 3, 4);          // 4 % 3 = 1
    REQUIRE_THAT(toVec(arr, 3), Equals(std::vector<int>{2, 3, 1}));
}

TEST_CASE("arrayShift – zero shifts leaves array unchanged", "[arrayShift][edge]") {
    int arr[] = {1, 2, 3, 4};
    arrayShift(arr, 4, 0);
    REQUIRE_THAT(toVec(arr, 4), Equals(std::vector<int>{1, 2, 3, 4}));
}

TEST_CASE("arrayShift – single-element array is always unchanged", "[arrayShift][edge]") {
    int arr[] = {42};
    arrayShift(arr, 1, 7);
    REQUIRE(arr[0] == 42);
}

TEST_CASE("arrayShift – full cycle returns to original", "[arrayShift]") {
    int arr[]      = {1, 2, 3, 4, 5};
    int original[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
        arrayShift(arr, 5, 1);

    REQUIRE_THAT(toVec(arr, 5), Equals(toVec(original, 5)));
}


TEST_CASE("arrayShiftLeft – behaves identically to arrayShift", "[shiftLeft]") {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3, 4, 5};

    arrayShift    (a, 5, 2);
    arrayShiftLeft(b, 5, 2);

    REQUIRE_THAT(toVec(a, 5), Equals(toVec(b, 5)));
}

TEST_CASE("arrayShiftLeft – shift 2 on size-5", "[shiftLeft]") {
    int arr[] = {1, 2, 3, 4, 5};
    arrayShiftLeft(arr, 5, 2);
    REQUIRE_THAT(toVec(arr, 5), Equals(std::vector<int>{3, 4, 5, 1, 2}));
}

TEST_CASE("arrayShiftRight – single shift of 1", "[shiftRight]") {
    int arr[] = {1, 2, 3, 4, 5};
    arrayShiftRight(arr, 5, 1);
    REQUIRE_THAT(toVec(arr, 5), Equals(std::vector<int>{5, 1, 2, 3, 4}));
}

TEST_CASE("arrayShiftRight – shift of 3", "[shiftRight]") {
    int arr[] = {1, 2, 3, 4, 5};
    arrayShiftRight(arr, 5, 3);
    REQUIRE_THAT(toVec(arr, 5), Equals(std::vector<int>{3, 4, 5, 1, 2}));
}

TEST_CASE("arrayShiftRight – shifts equal to size is a no-op", "[shiftRight][edge]") {
    int arr[] = {1, 2, 3};
    arrayShiftRight(arr, 3, 3);
    REQUIRE_THAT(toVec(arr, 3), Equals(std::vector<int>{1, 2, 3}));
}

TEST_CASE("arrayShiftRight – shifts larger than size uses modulo", "[shiftRight][edge]") {
    int arr[] = {1, 2, 3};
    arrayShiftRight(arr, 3, 4);     // 4 % 3 = 1
    REQUIRE_THAT(toVec(arr, 3), Equals(std::vector<int>{3, 1, 2}));
}

TEST_CASE("arrayShiftLeft then arrayShiftRight restores original", "[shiftLeft][shiftRight]") {
    int arr[]      = {1, 2, 3, 4, 5};
    int original[] = {1, 2, 3, 4, 5};

    arrayShiftLeft (arr, 5, 3);
    arrayShiftRight(arr, 5, 3);

    REQUIRE_THAT(toVec(arr, 5), Equals(toVec(original, 5)));
}

TEST_CASE("arrayShiftRight full cycle returns to original", "[shiftRight]") {
    int arr[]      = {1, 2, 3, 4, 5};
    int original[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
        arrayShiftRight(arr, 5, 1);

    REQUIRE_THAT(toVec(arr, 5), Equals(toVec(original, 5)));
}

TEST_CASE("vectorShift – shift of 1", "[vector]") {
    std::vector<int> v = {1, 2, 3, 4, 5};
    vectorShift(v, 1);
    REQUIRE_THAT(v, Equals(std::vector<int>{2, 3, 4, 5, 1}));
}

TEST_CASE("vectorShift – shift of 3", "[vector]") {
    std::vector<int> v = {1, 2, 3, 4, 5};
    vectorShift(v, 3);
    REQUIRE_THAT(v, Equals(std::vector<int>{4, 5, 1, 2, 3}));
}

TEST_CASE("vectorShift – shift equal to size is a no-op", "[vector][edge]") {
    std::vector<int> v = {1, 2, 3, 4, 5};
    vectorShift(v, 5);
    REQUIRE_THAT(v, Equals(std::vector<int>{1, 2, 3, 4, 5}));
}

TEST_CASE("vectorShift – shift larger than size uses modulo", "[vector][edge]") {
    std::vector<int> v = {1, 2, 3};
    vectorShift(v, 4);              // 4 % 3 = 1
    REQUIRE_THAT(v, Equals(std::vector<int>{2, 3, 1}));
}

TEST_CASE("vectorShift – zero shift leaves vector unchanged", "[vector][edge]") {
    std::vector<int> v = {1, 2, 3, 4};
    vectorShift(v, 0);
    REQUIRE_THAT(v, Equals(std::vector<int>{1, 2, 3, 4}));
}

TEST_CASE("vectorShift – single-element vector is unchanged", "[vector][edge]") {
    std::vector<int> v = {99};
    vectorShift(v, 7);
    REQUIRE(v[0] == 99);
}

TEST_CASE("vectorShift – full cycle returns to original", "[vector]") {
    std::vector<int> v        = {1, 2, 3, 4, 5};
    std::vector<int> original = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
        vectorShift(v, 1);

    REQUIRE_THAT(v, Equals(original));
}

TEST_CASE("vectorShift – results match arrayShift for same inputs", "[vector]") {
    int arr[] = {10, 20, 30, 40, 50};
    std::vector<int> v = {10, 20, 30, 40, 50};

    arrayShift(arr, 5, 2);
    vectorShift(v, 2);

    REQUIRE_THAT(v, Equals(toVec(arr, 5)));
}
