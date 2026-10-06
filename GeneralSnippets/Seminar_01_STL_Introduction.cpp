// =====================================================================================
// STL Introduction
// =====================================================================================


#include <vector>
#include <list>
#include <deque>
#include <print>
#include <algorithm>

//using namespace std;

void test_stl_01()
{
    std::vector<int> zahlen;
    zahlen.reserve(4 * 20);

    for (std::size_t i = 0; i != 100; ++i) {
        zahlen.push_back((int)(2 * i));

        std::println("{}: Size={} Capacity={}", i, zahlen.size(), zahlen.capacity());
    }

    int* first = zahlen.data();

    zahlen.shrink_to_fit();
    std::println("     Size={} Capacity={}", zahlen.size(), zahlen.capacity());

    first = zahlen.data();
}

void test_stl_02()
{
    std::vector<int> zahlen{ 10, 11, 12 };
    //std::list<int> zahlen{ 10, 11, 12 };

    for (std::size_t i = 0; i != zahlen.size(); ++i) {

        std::println("Index: {}: Wert: {}", i, zahlen[i]);
    }
}

void test_stl_03()
{
    //std::vector<int> zahlen{ 10, 11, 12 };
    // std::list<int> zahlen{ 10, 11, 12 };
    std::deque<int> zahlen{ 10, 11, 12 };

    //std::vector<int>::iterator pos = zahlen.begin();
    auto pos = zahlen.begin();

    int value = *pos;
    std::println("Wert: {}", value);

    ++pos;
    value = *pos;
    std::println("Wert: {}", value);

    ++pos;
    value = *pos;
    std::println("Wert: {}", value);

    //++pos;
    //value = *pos;
    //std::println("Wert: {}", value);

    //for (std::size_t i = 0; i != zahlen.size(); ++i) {

    //	std::println("Index: {}: Wert: {}", i, zahlen[i]);
    //}
}

void test_stl_04()
{
    //std::vector<int> zahlen{ 10, 11, 12 };
    // std::list<int> zahlen{ 10, 11, 12 };
    std::deque<int> zahlen{ 10, 11, 12 };

    //std::vector<int>::iterator pos = zahlen.begin();
    auto pos = zahlen.begin();
    auto ende = zahlen.end();

    if (pos == ende) {
        std::println("Done.");
        return;
    }
    int value = *pos;
    std::println("Wert: {}", value);

    ++pos;

    if (pos == ende) {
        std::println("Done.");
        return;
    }
    value = *pos;
    std::println("Wert: {}", value);

    ++pos;
    if (pos == ende) {
        std::println("Done.");
        return;
    }
    value = *pos;
    std::println("Wert: {}", value);

    ++pos;
    if (pos == ende) {
        std::println("Done.");
        return;
    }
    value = *pos;
    std::println("Wert: {}", value);

    //for (std::size_t i = 0; i != zahlen.size(); ++i) {

    //	std::println("Index: {}: Wert: {}", i, zahlen[i]);
    //}
}

void test_stl_05()
{
    std::vector<int> zahlen{ 10, 11, 12 };
    // std::list<int> zahlen{ 10, 11, 12 };
    //std::deque<int> zahlen{ 10, 11, 12 };

    auto pos = zahlen.begin();
    auto ende = zahlen.end();

    while (pos != ende) {
        std::println("Wert: {}", *pos);
        ++pos;
    }
}

void ausgabe(int wert)
{
    int n = wert;

    std::println(">>> Wert: {}", wert);
}

class Ausgabe
{
private:
    std::string m_header;

public:
    Ausgabe() { m_header = ">>> "; }
    Ausgabe(const std::string& header)
        : m_header{ header }
    {}

    void operator() (int wert) {
        std::println("{} Wert: {}", m_header, wert);
    }
};

void test_stl_07()
{
    Ausgabe obj{ "-->" };

    obj(123);
}

void test_stl_06()
{
    std::vector<int> zahlen{ 10, 11, 12 };
    // std::list<int> zahlen{ 10, 11, 12 };
    //std::deque<int> zahlen{ 10, 11, 12 };

    std::for_each(
        zahlen.begin(),
        zahlen.end(),
        ausgabe
    );
}

void test_stl_08()
{
    class Ausgabe
    {
    private:
        std::string m_header;

    public:
        Ausgabe() { m_header = ">>> "; }
        Ausgabe(const std::string& header)
            : m_header{ header }
        {}

        void operator() (int wert) {
            std::println("{} Wert: {}", m_header, wert);
        }
    };

    std::vector<int> zahlen{ 10, 11, 12 };
    // std::list<int> zahlen{ 10, 11, 12 };
    //std::deque<int> zahlen{ 10, 11, 12 };

    Ausgabe obj{ "-->" };

    std::for_each(
        zahlen.begin(),
        zahlen.end(),
        obj
    );
}

void test_stl_09()
{
    std::vector<int> zahlen{ 10, 11, 12 };
    // std::list<int> zahlen{ 10, 11, 12 };
    //std::deque<int> zahlen{ 10, 11, 12 };

    //auto myLambda = [](int wert) {
    //	std::println("Lambda Wert: {}", wert);
    //	};

    std::string header{ ">>> " };

    std::for_each(
        zahlen.begin(),
        zahlen.end(),
        [&](int wert) {
            std::println("{} Wert: {}", header, wert);
        }
    );
}

void seminar_stl_introduction()
{
    //test_stl_01();
    //test_stl_02();
    //test_stl_03();
    //test_stl_04();
    //test_stl_05();
    //test_stl_06();
    //test_stl_07();
    //test_stl_08();
    test_stl_09();
}


// =====================================================================================
// End-of-File
// =====================================================================================
