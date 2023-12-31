//https://moodle.chnu.edu.ua/mod/assign/view.php?id=134014
#include"task1.hpp"
#include"task2.hpp"
#include"task3.hpp"
#include"task4.hpp"
#include<Windows.h>
#include<locale>

int main()
{
    char active_locale[]="uk_UA.UTF-8";
    ios_base::sync_with_stdio(false);
    wcin.imbue(locale(active_locale));
    wcout.imbue(locale(active_locale));
    setlocale(LC_ALL,active_locale);
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int task=0;

    switch(task)
    {
        case 1:
            t1();
            break;
        case 2:
            t2();
            break;
        case 3:
            t3();
            break;
        case 4:
            t4();
            break;
        default:
            break;
    }
}