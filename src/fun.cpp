// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char* str) {
    //return 0;
    int countWord = 0;
    int i = 0;
    bool inWord = false;
    bool isDigits = false;
    while (str[i]) {
        if (!isspace(str[i])) {
            inWord = true;
            if (isdigit(str[i])) {
                isDigits = true;
            }
        }
        else {
            if (inWord) {
                if (!isDigits) {
                    countWord++;
                }
                else {
                    isDigits = false;
                }
                inWord = false;
            }
        }
        i++;
    }
    if (inWord) {
        if (!isDigits) {
            countWord++;
        }
    }
    return countWord;
}

unsigned int faStr2(const char* str) {
    //return 0;
    int countWord = 0;
    int i = 0;
    bool inWord = false;
    bool isGood = false;
    while (str[i]) {
        if (!isspace(str[i])) {
            if (!inWord) {
                if (isalpha(str[i]) && isupper(str[i])) {
                    isGood = true;
                }
                inWord = true;
            }
            else {
                if (isGood) {
                    if (!isalpha(str[i])) {
                        isGood = false;
                    }
                }
            }
        }
        else {
            if (inWord) {
                if (isGood) {
                    countWord++;
                }
                inWord = false;
                isGood = false;
            }
        }
        i++;
    }

    if (inWord) {
        if (isGood) {
            countWord++;
        }
    }

    return countWord;
}

unsigned int faStr3(const char* str) {
    //return 0;
    int countWord = 0;
    int countSign = 0;
    int i = 0;
    bool inWord = false;
    while (str[i]) {
        if (!isspace(str[i])) {
            countSign++;
            if (!inWord) {
                inWord = true;
                countWord++;
            }
        }
        else {
            if (inWord) {
                inWord = false;
            }
        }
        i++;
    }
    return round(countSign / countWord);
}

