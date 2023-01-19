#pragma once

#include <string>

#include "Date.h"

class DataValidator
{
public:
    DataValidator();
    ~DataValidator();

public:
    bool is_valid_email(const std::string& email);
    bool is_valid_url(const std::string& url);
    bool is_valid_date(std::string& date, const int format);
    bool is_valid_number(const std::string& number);

private:
    bool is_valid_symbol(const char);
    bool is_valid_recepient(const std::string& recipient);
    bool is_valid_domain(const std::string& Domain);
    bool is_valid_scheme(const std::string& scheme);
    bool is_dot_number(const std::string& dot_num);

private:
    Date* m_date;
    const char numZero;
    const char  numNine;
    const char at;
    const char dot;
    const char hyphen;
    const std::string schemEnd;
};