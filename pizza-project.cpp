#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    float total_cost = 0;
    float ing_cost = 0;
    float special_cost = 3.99;
    float simple_cost = 1.99;

    int nr_simple;
    int nr_special;

    bool is_invalid = true;
    bool valid = false;

    string size;
    string dough;
    string ingredients;
    string drink;

    string ind = "individual";
    string med = "media";
    string fam = "familiar";

    string thin = "fina";
    string normal = "normal";

    string simple = "simples";
    string special = "especiais";

    string water = "agua";
    string soda = "refrigerante";
    string juice = "sumo";

    char a = 160;
    char A = 181;
    char e = 130;
    char til = 198;

    system("color 4E");

    printf("\n\t*************************************************");
    printf("\n\t*\t\t\t\t\t\t*\n\t*\tBem vindo(a) %c Pizzaria Bob's:\t\t*", a);
    printf("\n\t*\t\t\t\t\t\t*");
    printf("\n\t*************************************************\n");

    printf("\tConstrua a sua pizza : \n\n");
    do
    {
        printf("De que tamanho deseja a sua pizza?\n");
        printf("- Individual\n");
        printf("- M%cdia\n", e);
        printf("- Familiar\n");
        printf("----------------------------------------------------------------\n");

        cin >> size;

        transform(size.begin(), size.end(), size.begin(), ::tolower);

        if (size.compare(ind) == 0)
        {
            is_invalid = false;
            total_cost += 5.99;
        }
        else if (size.compare(med) == 0)
        {
            is_invalid = false;
            total_cost += 8.99;
        }
        else if (size.compare(fam) == 0)
        {
            is_invalid = false;
            total_cost += 12.99;
        }
    } while (is_invalid);

    do
    {
        printf("\nAgora , decida o tipo de massa que quer :\n\n - Normal\n - Fina\n");
        printf("----------------------------------------------------------------\n");
        cin >> dough;

        transform(dough.begin(), dough.end(), dough.begin(), ::tolower);

        if (dough.compare(thin) == 0)
        {
            is_invalid = false;
            total_cost += 2.99;
        }
        else if (dough.compare(normal) == 0)
        {
            is_invalid = false;
            total_cost += 4.99;
        }
    } while (is_invalid);

    while (!valid)
    {
        cout << "\nQuantos Ingredientes simples vai desejar?\n";
        cin >> nr_simple;
        if (cin.fail())
        {
            cout << "\nDados Incorrectos" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        else
        {
            valid = true;
        }
    }
    valid = false;

    while (!valid)
    {
        cout << "\nQuantos ingredientes especiais vai desejar?\n";
        cin >> nr_special;
        if (cin.fail())
        {
            cout << "\nDados Incorrectos" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        else
        {
            valid = true;
        }
    }
    is_invalid = true;
    total_cost += (nr_special * special_cost) + (nr_simple * simple_cost);
    do
    {
        printf("\nQue bebida vai desejar?\n");
        printf("- %cgua\n", A);
        printf("- Refrigerante\n");
        printf("- Sumo\n");
        printf("----------------------------------------------------------------\n");
        cin >> drink;

        transform(drink.begin(), drink.end(), drink.begin(), ::tolower);

        if (drink.compare(water) == 0)
        {
            is_invalid = false;
            total_cost += 0.50;
        }
        else if (drink.compare(soda) == 0)
        {
            is_invalid = false;
            total_cost += 1.40;
        }
        else if (drink.compare(juice) == 0)
        {
            is_invalid = false;
            total_cost += 1.00;
        }
    } while (is_invalid);

    printf("----------------------------------------------------------------\n");
    cout << "\nA sua pizza : " << endl
         << endl;
    cout << "\nTamanho : " << size << endl;
    cout << "Massa " << dough << endl;
    cout << "Bebida: " << drink << endl;
    cout << nr_simple << " ingrediente(s) simples" << endl;
    cout << nr_special << " ingrediente(s) especiais." << endl;
    cout << "Custo final : " << total_cost << " euros." << endl;

    return 0;
}
