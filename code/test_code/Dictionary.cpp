#include <string>
#include <iostream>
using namespace std;


class Dictionary
{
public:
    struct page {
        page* pNextPage;
        page* pChildlenPage;
        char* pData;
        bool lastFlag;

        // ページの挿入
        bool InsertPage(string word, int index) {
            if (pData == nullptr) {
                pData = new char;
                *pData = word[index];
                if ((index + 1) == word.size()) {
                    lastFlag = true;
                    return true;
                }
                else {
                    pChildlenPage = new page;
                    return pChildlenPage->InsertPage(word, index + 1);
                }
            }
            else {
                if (*pData == word[index]) {
                    if ((index + 1) == word.size()) {
                        if (lastFlag == true)
                            return false;
                        else {
                            lastFlag = true;
                            return true;
                        }
                    }
                    else {
                        if (pChildlenPage == nullptr) {
                            pChildlenPage = new page;
                        }
                        return pChildlenPage->InsertPage(word, index + 1);
                    }
                }
                else {
                    if (pNextPage == nullptr) {
                        pNextPage = new page;
                    }
                    return pNextPage->InsertPage(word, index);
                }
            }
        }

        // ページの検索
        bool FindPage(string key, int index) {
            if (key[index] == *pData) {
                if ((index + 1) == key.size()) {
                    if (lastFlag == true)
                        return true;
                    else {
                        if (pNextPage != nullptr)
                            return pNextPage->FindPage(key, index);
                        else
                            return false;
                    }
                }
                else {
                    if (pChildlenPage != nullptr)
                        return pChildlenPage->FindPage(key, index + 1);
                    else
                        return false;
                }
            }
            else {
                if (pNextPage != nullptr)
                    return pNextPage->FindPage(key, index);
                else
                    return false;
            }

        }

        // ページの全削除
        void DeletePage() {
            delete pData;
            pData = nullptr;
            if (pNextPage != nullptr) {
                pNextPage->DeletePage();
                pNextPage = nullptr;
            }
            if (pChildlenPage != nullptr) {
                pChildlenPage->DeletePage();
                pChildlenPage = nullptr;
            }
        }

        page() :pNextPage(nullptr), pChildlenPage(nullptr), pData(nullptr), lastFlag(false) {};
        ~page() {};
    };

    Dictionary() :pTopPage(nullptr) {};
    ~Dictionary() { if (pTopPage != nullptr)  pTopPage->DeletePage(); };
    bool InsertPage(string word) {
        if (pTopPage == nullptr)
            pTopPage = new page;
        return pTopPage->InsertPage(word, 0);
    }
    bool FindPage(string key) {
        if (pTopPage == nullptr)
            return false;
        return pTopPage->FindPage(key, 0);
    }
private:
    page* pTopPage;
};
