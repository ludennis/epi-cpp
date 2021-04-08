/*
 *  13.3 Implement an ISBN cache
 *  Create a cache for looking up prices of books identified by their ISBN. You implement
 *    lookup, insert, and remove methods. Use the Least Recently Used (LRU) policy for
 *    cache eviction. If an ISBN is already present, insert should not change the price,
 *    but it should update that entry to be the most recently used entry. Lookup should
 *    also update that entry to be the most recently used entry.
 */

#include <queue>
#include <string>
#include <unordered_map>

#include <gtest/gtest.h>

class ISBNCache
{
public:
  ISBNCache(int size)
  : mCacheMaxSize(size)
  {}

  void Insert(const std::string &isbn, const int price)
  {
    if (mCache.size() == mCacheMaxSize)
    {
      // delete the LRU item
      auto LruEntryPtr = SeekLruEntry();
      if (auto LruEntryPtr = SeekLruEntry())
      {
        mCache.erase((*LruEntryPtr)->first);
        while (mLruEntries.begin() <= LruEntryPtr)
          mLruEntries.pop_front();
      }
    }

    mCache[isbn] = std::make_pair(price, 0);
    mLruEntries.emplace_back(std::make_pair(isbn, 0));
  }

  std::optional<int> Lookup(const std::string &isbn)
  {
    if (mCache.find(isbn) != mCache.end())
    {
      mCache[isbn].second++;
      mLruEntries.emplace_back(std::make_pair(isbn, mCache[isbn].second));
      return std::make_optional<int>(mCache[isbn].first);
    }
    else
      return {};
  }

  void Delete(const std::string &isbn)
  {
    if (mCache.find(isbn) != mCache.end())
      mCache.erase(isbn);
  }

  int Size()
  {
    return mCache.size();
  }

private:
  int mCacheMaxSize;
  std::unordered_map<std::string, std::pair<int, int>> mCache;
  std::deque<std::pair<std::string, int>> mLruEntries;

  std::optional<std::deque<std::pair<std::string, int>>::const_iterator> SeekLruEntry()
  {
    for (auto itr{mLruEntries.begin()}; itr != mLruEntries.end(); ++itr)
    {
      if (mCache[itr->first].second == itr->second)
        return itr;
    }
    return {};
  }
};

TEST(ISBNCacheTest, UnitTest)
{
  ISBNCache cache(3);

  // say there's 10 books each has isbn from 1-10, with price $10 * isbn #

  cache.Insert("1", 10);
  EXPECT_EQ(1, cache.Size());

  cache.Insert("2", 20);
  EXPECT_EQ(2, cache.Size());

  cache.Insert("3", 30);
  EXPECT_EQ(3, cache.Size());

  cache.Insert("4", 40);
  EXPECT_EQ(3, cache.Size());

  cache.Insert("5", 50);
  EXPECT_EQ(3, cache.Size());

  EXPECT_EQ(false, cache.Lookup("1").has_value());
  EXPECT_EQ(false, cache.Lookup("2").has_value());
  EXPECT_EQ(30, cache.Lookup("3").value());
  EXPECT_EQ(40, cache.Lookup("4").value());
  EXPECT_EQ(50, cache.Lookup("5").value());

  cache.Lookup("3");
  cache.Insert("6", 60); // this should delete "4"
  EXPECT_EQ(false, cache.Lookup("4").has_value());

  cache.Delete("5"); // now LRU entry should be 3
  cache.Lookup("3"); // now LRU entry should be 6
  cache.Insert("7", 70);
  cache.Insert("8", 80); // should be 3 7 8
  EXPECT_EQ(30, cache.Lookup("3").value());
  EXPECT_EQ(70, cache.Lookup("7").value());
  EXPECT_EQ(80, cache.Lookup("8").value());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
