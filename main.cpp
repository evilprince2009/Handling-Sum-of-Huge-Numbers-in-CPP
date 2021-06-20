#include <bits/stdc++.h>

using namespace std;
vector<int> Add(vector<int> first_number, vector<int> second_number)
{
    reverse(first_number.begin(), first_number.end());
    reverse(second_number.begin(), second_number.end());

    vector<int> result;

    int min_length = min(first_number.size(), second_number.size());
    int max_length = max(first_number.size(), second_number.size());
    int buffer = 0;

    for (int i = 0; i < min_length; i++)
    {
        int digit_sum = first_number[i] + second_number[i] + buffer;
        buffer = digit_sum / 10;
        result.push_back(digit_sum % 10);
    }

    if (first_number.size() > second_number.size())
    {
        for (int i = min_length; i < first_number.size(); i++)
        {
            int digit_sum = first_number[i] + buffer;
            buffer = digit_sum / 10;
            result.push_back(digit_sum % 10);
        }
    }

    if (first_number.size() < second_number.size())
    {
        for (int i = min_length; i < second_number.size(); i++)
        {
            int digit_sum = second_number[i] + buffer;
            buffer = digit_sum / 10;
            result.push_back(digit_sum % 10);
        }
    }

    while(buffer)
    {
        result.push_back(buffer % 10);
        buffer = buffer / 10;
    }

    reverse(result.begin(), result.end());
    return result;
    
}

int main()
{
    string number_a, number_b;
    std::cout << "Enter first number" << std::endl;
    std::cin >> number_a ;
    std::cout << "Enter second number" << std::endl;
    std::cin >> number_b;

    vector<int> number_a2, number_b2;

    for (int i = 0; i < number_a.size(); i++)
    {
        number_a2.push_back(number_a[i] - '0');
    }

    for (int i = 0; i < number_b.size(); i++)
    {
        number_b2.push_back(number_b[i] - '0');
    }

    vector <int> Sum = Add(number_a2, number_b2);

    std::cout << "Result is" << std::endl;
    for (auto i: Sum)
    {
        cout << i;
    }

    std::cin.get();
}