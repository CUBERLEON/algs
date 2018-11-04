#include <catch.hpp>

#include <string>
using namespace std;

namespace
{
    #include <data_structures/Trie.hpp>

    TEST_CASE("Trie")
    {
        Trie trie;

        trie.insert("abcdefghabc");
        trie.insert("qwertyuio");
        trie.insert("asdfghjkl");
        trie.insert("zxcvbn");
        trie.insert("atest");
        trie.insert("btest");
        trie.insert("ctest");

        SECTION("Search word")
        {
            REQUIRE(trie.search("btest") == true);
            REQUIRE(trie.search("asdfghjkl") == true);
            REQUIRE(trie.search("abcdefgh") == false);
            
            REQUIRE(trie.search("test") == false);
            trie.insert("test");
            REQUIRE(trie.search("test") == true);
            
            REQUIRE(trie.search("") == false);
            trie.insert("");
            REQUIRE(trie.search("") == true);
        }

        SECTION("Search prefix")
        {
            REQUIRE(trie.search_prefix("abc") == true);
            REQUIRE(trie.search_prefix("atest") == true);
            REQUIRE(trie.search_prefix("") == true);
            
            REQUIRE(trie.search_prefix("d") == false);
            trie.insert("dtest");
            REQUIRE(trie.search_prefix("d") == true);
        }
    }
}