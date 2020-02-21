Тема:        Основные отличия C++ от С.

1.	  В С++ определять переменные можно в любом месте программы. 
    (В С все локальные переменные должны определяться до первого исполняемого оператора. )
2.	. В С++ обязательны прототипы функций.
3.	Передача данных в функцию по умолчанию


/*Пример 1.   Написать программу с использованием функции для начисления зарплаты за месяц в зависимости от количества отработанных дней 
и расценки за один день.
////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

void    zarplata(const char *s, int days = 24, float rascenka = 30.5);

int     main()
{
    zarplata("man");
    zarplata("brother", 26);
    zarplata("sister", 24, 41);
    return 0;
}

void    zarplata(const char *s, int days, float rascenka)
{
    cout << s << " earned " << days * rascenka << " dollars\n";
}

// Output:
/*
    man earned 732 dollars
    brother earned 793 dollars
    sister earned 984 dollars
*/
////////////////////////////////////////////////////////////

/*Пример 2.  Написать программу с использованием функции для начисления зарплаты для преподавателей, 
имеющих ученую степень и преподавателей, не имеющих таковой. 
В зависимости от ученого звания заработная плата рассчитывается по-разному
//////////////////////////////////////////////////////////*/
#include <iostream>

const int SD_YES = 2;
const int SD_NO = 1;

using namespace std;

void    salary(const char *name, int deg, int days = 25, float rate = 30.6)
{
    cout << name << " earned " << rate * deg * days << " dollars\n";
}

int     main()
{
    salary("Newton", SD_YES);
    salary("Raskolnikov", SD_NO);
    salary("Einstein", SD_YES);
    return 0;
}

// Output:
/*
    Newton earned 1530 dollars
    Raskolnikov earned 765 dollars
    Einstein earned 1530 dollars
*/
////////////////////////////////////////////////////////////

/*Пример 3.  Самостоятельно сформулировать постановку задачи, в которой целесообразна передача данных в функцию по умолчанию. 
//////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

void    scholarship(const char *name, int low_mark = 4, int grant = 1000)
{
    if (low_mark > 3 && low_mark < 6)
        cout << name << " earned " << low_mark * grant << " rubbles, having " << low_mark << " low mark\n";
    else
        cout << name << " has no scholarship\n";
}

int     main()
{
    scholarship("Petrov");
    scholarship("Ivanov", 3);
    scholarship("Sidorov", 5);
    return 0;
}

// Output:
/*
    Petrov earned 4000 rubbles, having 4 low mark
    Ivanov has no scholarship
    Sidorov earned 5000 rubbles, having 5 low mark
*/
/////////////////////////////////////////////////////////
