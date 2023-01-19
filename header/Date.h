#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "DateForm.h"

class Date
{
public:
    Date(std::string&, const int);
    ~Date();

public:
    bool get_flag();

private:
    void init_forms();
    bool is_not_nubmer(const char sym);
    void _switch(const int, const std::vector<std::string>&);
    std::vector<std::string> spliter(std::string&);

private:
    enum class DateFormat { Form1 = 1, Form2, Form3, Form4, Form5, Form6 };

    std::map<std::string, DateFormat> forms;

private:
    Day* m_day;
    Month* m_month;
    Year* m_year;
    bool m_flag;
};