#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<random>
#include<cstring>

#include"coffeeshop.hpp"
#include"start.hpp"
#include"menu.hpp"
#include"EmployeeAndEvents.hpp"

int main()
{
    srand((unsigned)time(NULL));
    std::mt19937 gen(rand());

    char brandName[60], decision = '2', drinks[10][30] = { "Black coffee","Latte(Hot)","Cappuccino","Espresso","Macchiato(Hot)","Irish(Hot)","Frappucino(Cold)","Flat white(Hot)","Iced coffee","Americano", }, anotherdecision, onetime, items[10][50] = { "Watch($5000)","Lamborghini($300000)","Tesla($90000)","New house($500000)","Super PC($20000)","Christian Clive No.1 Imperial Majesty($45000)" };

    char month[12][20] = { "January","February","March","April","May","June","July","August","September","October","November","December" }, locations[6][70] = { "Bucharest(Center) Price:$2000/m", "Ploiesti Price:$800/m","Bucharest(Outskirts) Price:$1000/m", "Urziceni Price:$400/m","Constanta(seaside) Price:$1600/m" };

    char partnerships[5][36] = { "Simigeria Luca(pastry)","Top Of The Morning(coffee beans)","Lactialis(milk)","Severin(technology)","Jacobs(coffee beans)" }, names[10][10] = { "Farcasi","Nedelcu","Ilie","Filimon","Smith","Brown","Wills","Roll","Millan","Lee" }, forenames[10][10] = { "Octavian","Mario","Christian","Stephen","Emma","Duncan","Juan","Alexa","Carla","Connor" };

    long long age = 22, inflation = 15, prices[10] = { 0 }, production_costs[10] = { 2,4,5,1,3,6,6,3,5,2 }, happiness = 0, margin[10] = { 0 }, bought[10] = { 0 }, hype = 1, tips, trust = 0, locationsOwned = 0;

    long long quantity[10] = { 0 }, total_prod_costs, mthnumber = 0, employees = 0, demand[10] = { 0 }, lastDemand[10] ={ 0 }, owned[6] = {0}, rented[6] = {0}, firstStore, reputation = 0, interest = 0, intRate = 0;

    bool job = true, sold[5][10] = { 0 }, concert = 0, event = 0;

    long long salary = 4000, taxes, time = 4, expenses = 1800, rent = 0, gross_income, savings = 10000, marketing, customers = 0, profit, sellStore = 0;

    int noDemand[10] = { 0 };

    character employee[5]{};


    printf("\n Dev Note:Hello there, I am Filimon Stefan, the developer of this little simulator called \"The Cafe Sim\", thank you for trying it out. The decisions you make will determine whether you will achieve your goal or not, so choose wisely, \n because this is, Your, Cafe Simulator.(The majority of prices in the game are made up by me!)");
    printf("\n\n !WARNING: This game is not going to take your hand and guide you, there are a few tips here and there, but if you want to succeed(please don't think that you can start a business if you finish the game), you will need to think like an entrepreneur(you need to know a few basic terms of finance)!\n\n Here are a few tips to help you understand how the game works:");
    printf("\n -Net income = Gross income-Production costs-Salaries-Taxes-Personal Expenses-Rent \n\n -Employee insight = how well the employee manages coffee quantities\n\n -Customers get bored and stop coming if you don't bring imporvements\n\n - !The more you grow your business, the more your customers will trust you and buy products at HIGHER PRICES (!PLAY AROUND WITH PRICES AND TEST THE MARKET, DON'T WAIT FOR THE GAME TO TELL YOU WHEN YOU SHOULD CHANGE PRICES CAUSE IT WON'T) \n\n -Time of the year matters \n\n -Extra demand means how many more drinks people would have bought, if you had the quantity");
    printf("\n\n Continue when you are ready...");
    _getch();
    
    printf("\n\n So this is your story: you are a college graduate, you don't know anything about business but you heard that entrepreneur's make a lot of money. You are now 22 years old, working a full-time job every week day and you have a salary of   $4000, but one day, you get out of bed and say <I want to get rich>, and this is where your journey begins. You take your $10000 savings and you decide to start a coffee shop. Your goal is to make at least 1 million dollars. \n\n Press anything to continue...\n\n");
    _getch();
    taxes = 45 * salary / 100;
    while (decision == '2' && age <= 23)
    {
        //Stats
        printf(" %s paycheck: $%lld           Expenses and taxes: $%lld \n", month[mthnumber], salary, expenses + taxes);
        printf(" Savings: $%lld                   Yearly inflation rate: %lld%% \n", savings, inflation);

        printf("\n Do you open the coffee shop now or do you wait another paycheck?\n");
        printf(" 1.Start now           2.Wait for paycheck\n ");
        std::cin >> decision;

        if (decision == '1')
        {
            //Let's gooo
            printf("\n Great, let's get down to business.");
            break;
        }

        if (decision == '2')
        {
            //The player is afraid and decides to wait more
            savings = savings + salary - expenses - taxes;
            mthnumber++;
        }
        else
        {
            decision = '2';
            printf(" I am sorry, but that is not an option.\n");
            _getch();
        }

        if (mthnumber == 11)
        {
            //The player gets older
            age++;
            mthnumber = 0;
            printf("\n\n It's your birthday, you are now %lld!\"confetti falling\"", age);
            printf("\n Due to the yearly inflation, your savings are worth %lld%% less \n Press anything to continue...\n\n", inflation);
            _getch();
            savings = savings - 15 * savings / 100;
        }
        std::cin.ignore(99999, '\n');

    }

    if (age == 24)
    {
        //The player was too afraid to take action
        printf(" You postponed it for too long and lost motivation, the excitement starting your own business is now gone.\n");
        _getch();
        return 0;
    }
    printf("\n\n It's generally not a good idea to go head first when you are entering a new territory, so you decide to do some research before starting. You follow some barista, business and marketing courses which cost you around $1500 in total.");
    savings -= 1500;
    printf("\n Money left: $%lld", savings);
    std::cin.ignore(999999, '\n');
    _getch();
    printf("\n Now you have to choose a name for your brand: ");
    std::cin.getline(brandName, 60, '\n');

    printf("\n After registering your new business into the system, it's time to get started.");
    printf("\n Press anything if you are ready...");
    _getch();
    printf("\n\n First of all, good marketing is one of the most important things when starting a business, it helps people find out about your business. \n How much money would you like to spend on marketing? (Tip: you should not spend all of your money on this.)");
    Marketing(savings, marketing, customers);
    if (savings <= 0)
    {
        printf(" Unfortunately, marketing is not everything when it comes to a business, you spent all of your money so you can't open the coffee shop anymore, but don't let mistakes bring you, learn and grow.");
        _getch();
        return 0;
    }

    printf("\n\n Great, now you have to rent a property where you want your coffee shop to be. (Tip: pricier rent means there is more population in that area)");
    firstStore = First_rent(savings, rent, decision, customers, locations, rented, locationsOwned);
    if (savings < 1500)
    {
        printf(" You can't start a business just with marketing and an empty location, you don't have money to buy equipment anymore, but don't let mistakes bring you, learn and grow.");
        _getch();
        return 0;
    }

    printf("\n Now that you have decided on the location, it's time to buy the equipment for the shop (Tip: equipment improves atmosphere and atracts new customers):");
    decision = '0';
    savings -= 500; //there is no coffee shop without a coffee machine
    customers += 50;
    while (decision != '7')
    {
        if (decision == '1' && sold[firstStore][1] == 0 && savings >= 1000) 
        {
            sold[firstStore][1] = 1;
            savings -= 1000;
            happiness += 6;
            customers += 45;
            printf("\n 1.Buy tables and couches?($1000) (sold out)");
        }
        else if (sold[firstStore][1] == 0)
        {
            printf("\n 1.Buy tables and couches?($1000)");
        }
        else
        {
            printf("\n 1.Buy tables and couches?($1000) (sold out)");
        }
        printf("\n 2.Buy coffee machine?($500) (sold out)(bought automatically)");
        if (decision == '3' && sold[firstStore][3] == 0 && savings >= 800) 
        {
            sold[firstStore][3] = 1;
            savings -= 800;
            happiness += 8;
            customers += 90;
            printf("\n 3.Buy music player?($800) (sold out)");
        }
        else if (sold[firstStore][3] == 0)
        {
            printf("\n 3.Buy music player?($800)");
        }
        else
        {
            printf("\n 3.Buy music player?($800) (sold out)");
        }
        if (decision == '4' && sold[firstStore][4] == 0 && savings >= 300) 
        {
            sold[firstStore][4] = 1;
            savings -= 300;
            happiness += 4;
            customers += 30;
            printf("\n 4.Buy decorations?($300) (sold out)");
        }
        else if (sold[firstStore][4] == 0)
        {
            printf("\n 4.Buy decorations?($300)");
        }
        else
        {
            printf("\n 4.Buy decorations?($300) (sold out)");
        }
        if (decision == '5' && sold[firstStore][5] == 0 && savings >= 100) 
        {
            sold[firstStore][5] = 1;
            savings -= 100;
            happiness += 2;
            customers += 20;
            printf("\n 5.Buy POS?($100) (sold out)");
        }
        else if (sold[firstStore][5] == 0)
        {
            printf("\n 5.Buy POS?($100)");
        }
        else
        {
            printf("\n 5.Buy POS?($100) (sold out)");
        }
        if (decision == '6' && sold[firstStore][6] == 0 && savings >= 50) 
        {
            sold[firstStore][6] = 1;
            savings -= 50;
            printf("\n 6.Buy tips jar?($50) (sold out)");
        }
        else if (sold[firstStore][6] == 0)
        {
            printf("\n 6.Buy tips jar?($50)");
        }
        else
        {
            printf("\n 6.Buy tips jar?($50) (sold out)");
        }
        printf("\n 7.I am done.");
        printf("\n Money left: $%lld(!RENT IS UNPAID)\n ", savings);
        std::cin>>decision;
        std::cin.ignore(99999, '\n');
    }

    printf("\n\n Now it's time set prices for your drinks. \n");
    Menu(drinks, prices, production_costs);
    //player sets price for each drink

    //player quits job or not
    decision = '0';
    while (decision == '0')
    {
        printf("\n Every piece of the puzzle is in place, but their is still one more thing. You see, you don't have enough time to work at the coffee shop during the week due to the full-time job you have, and you don't have enough money to pay an employee, so it's time to make the most difficult decision of them all:\n 1.I quit my job and go full time working at the coffee shop and developing it.\n 2.I keep my job and work at the coffee shop only on weekend. (Tip: decreases number of customers significantly but you keep your $4000 salary)\n ");

        std::cin>>decision;
        if (decision == '1')
        {
            job = false;
            time += 8;
            salary = 0;
            taxes = 0;

        }
        else if (decision == '2')
        {
            job = true;
            customers = customers / 4;

        }
        else
        {
            decision = '0';
            printf(" I am sorry, but that is not an option.\n");
            printf("\n\n Press anything to continue...\n\n");
            _getch();
        }
        std::cin.ignore(99999, '\n');

    }

    //Opening promotion
    printf("\n Do you want to make a promotion for the great opening of %s? \n 1.First coffee free for everyone($%lld) \n 2.Not really\n ", brandName, customers + 50);
    std::cin>>decision;
    std::cin.ignore(99999, '\n');
    switch (decision)
    {
    case '1':
        customers += 50;
        savings -= customers;
        happiness += 6;
        hype = 2;
        break;

    default:
        customers -= 30;
        happiness -= 10;
        break;
    }

    expenses = 1500;
    bool availPart = 1, nr1 = true, rich = 0, onemil = 0,trusted=0; //nr1 verifies if this is the first month of the coffee shop

    while (age <= 69 && savings + salary >= 0 && sellStore == 0 && customers > 0 && rich==0)
    {
        if (age % 5 == 0)
        {
            printf("\n\n The coffee machine broke down, you will have to buy a new one fore $900.\n Okay...");
            savings -= 900;
            _getch();
        }

        profit = 0;

        long long shown_prod_costs;
        //Player selects quantity for each drink
        if (employees <= 1)
        {
            if (nr1 == true)
            {
                printf("\n Select the quantity of ingredients you want to buy for each drink(this month).(Tip: as it's your first month, I would recommend between 300-500, depending on your previous choices.)");
                total_prod_costs = Quantity(savings, quantity, drinks, production_costs, bought, demand, prices);
            }

            if (nr1 == false)
            {
                printf("\n Select the quantity of ingredients you want to buy for each drink(this month).");
                printf("\n 1.Change quantities \n 2.Same as last month\n ");
                std::cin>>anotherdecision;
                std::cin.ignore(99999, '\n');
                if (anotherdecision == '1')total_prod_costs = Quantity(savings, quantity, drinks, production_costs, bought, demand, prices);
                if (anotherdecision == '2')total_prod_costs = SameQuantity(savings, quantity, drinks, production_costs, bought, demand, prices);
            }
            savings += total_prod_costs;
            total_prod_costs *= hype;
            total_prod_costs=(total_prod_costs*3)/2;

        }
        else
        {   
            total_prod_costs = 0;
            if (employee[0].insight <= 90)
            {
                for (int i = 0; i <= 9; i++)
                {
                    if (mthnumber >= 5 && mthnumber <= 7)
                    {
                        if (i == 8 || i == 6)
                            demand[i] += customers / 3;

                        if (i == 1 || i == 4 || i == 5 || i == 7)
                            demand[i] -= customers / 6;
                    }

                    else if (mthnumber == 11 || mthnumber <= 1)
                    {
                        if (i == 1 || i == 4 || i == 5 || i == 7)
                            demand[i] += customers / 6;

                        if (i == 8 || i == 6)
                            demand[i] -= customers / 3;
                    }

                    std::uniform_int_distribution<> distrib2(0, 125 - employee[0].insight);
                    quantity[i] = bought[i] + demand[i] + distrib2(gen);
                    total_prod_costs += quantity[i] * production_costs[i];
                }
                total_prod_costs *= hype;
                total_prod_costs=(total_prod_costs*3)/2;
            }
            printf("\n Your employees are managing quantities now.");
            _getch();
        }

        if (nr1 == 1 && hype == 2)total_prod_costs += customers;
        gross_income = 0;
        reputation = customers / 10 + happiness * time / 2;
        tips = 0;

        //Determines number of coffees bought based on customers and coffee price
        for (int i = 0; i <= 9; i++)
        {
            lastDemand[i] = demand[i];
            demand[i] = 0;
            noDemand[i] = 0;

            if (mthnumber >= 5 && mthnumber <= 7)
            {
                if (i == 8 || i == 6)
                    lastDemand[i] += customers / 3;

                if (i == 1 || i == 4 || i == 5 || i == 7)
                    noDemand[i] -= customers / 6;
            }

            else if (mthnumber == 11 || mthnumber <= 1)
            {
                if (i == 1 || i == 4 || i == 5 || i == 7)
                    lastDemand[i] += customers / 6;

                if (i == 8 || i == 6)
                    noDemand[i] -= customers / 3;
            }

            bought[i] = 0;
            margin[i] = prices[i] - production_costs[i];
            if (prices[i] >= 3 * production_costs[i])customers -= margin[i]+trust;
            if (employees > 1 && employee[0].insight > 90)quantity[i] = customers + lastDemand[i];

            for (int j = 1; j <= customers+noDemand[i]; j++)
            {
                std::uniform_int_distribution<> distrib(0, margin[i]);
                if (distrib(gen) <= trust)
                {
                    if (quantity[i] > bought[i])bought[i]++;
                    else demand[i]++;
                }
            }

            for (int j = 1; j <= lastDemand[i]; j++)
            {
                std::uniform_int_distribution<> distrib(0, margin[i]);
                if (distrib(gen) <= trust)
                {
                    if (quantity[i] > bought[i])bought[i]++;
                }
            }

            gross_income = gross_income + (prices[i] * bought[i] * hype*3)/2;
            if (employees > 1 && employee[0].insight > 90)
            {
                quantity[i] = bought[i];
                total_prod_costs = total_prod_costs + production_costs[i] * quantity[i] * hype;
                total_prod_costs=(total_prod_costs*3)/2;
            }
        }

        if (employees > 0) 
        {
            int review = 0;
            int badVibe = 0;
            for (int i = 0; i < employees; i++)
            {
                review += employee[i].charisma + employee[i].politeness - employee[i].aggressiveness - employee[i].laziness;
                badVibe += employee[i].aggressiveness + employee[i].laziness;
            }
            std::uniform_int_distribution<> distrib(review, customers - badVibe);
            tips = distrib(gen);
            if (tips < 0)tips = 0;
            if (employee[0].insight < 100)employee[0].insight++;
        }

        //Calculating profit and taxes 
        profit = gross_income - total_prod_costs;
        profit -= rent;
        if (profit > 600) taxes = profit * 9 / 100 + profit * 16 / 100;
        profit -= expenses;
        profit -= taxes;
        if (intRate > 0)
        {
            profit -= interest;
            intRate--;
        }
        else interest = 0;

        shown_prod_costs = total_prod_costs;
        total_prod_costs /= hype;
        hype = 1;

        savings = savings + salary + profit - salary * 45 / 100;

        printf("\n\n Amount of drinks sold this month:");
        for (int i = 0; i < 10; i++)
        {
            printf("\n\n %s (SOLD %lld", drinks[i], bought[i]);
            printf(" OUT OF %lld) ", quantity[i]);
            printf("(PROFIT MARGIN: $%lld)", margin[i]);

            if (employees <= 1)
            {
                if(demand[i]<25)printf("    EXTRA DEMAND THIS MONTH: LOW");
                else if (demand[i] <= 75)printf("    EXTRA DEMAND THIS MONTH: MEDIUM");
                    else if (demand[i] <= 125)printf("    EXTRA DEMAND THIS MONTH: HIGH");
                        else if (demand[i] < 500)printf("    EXTRA DEMAND THIS MONTH: VERY HIGH");
                            else if (demand[i] >= 500)printf("    EXTRA DEMAND THIS MONTH: EXTREMELY HIGH");
            }
        }

        std::uniform_int_distribution<> distrib9(hype*customers - 100,hype*customers+100);
        printf("\n\n MONTHLY SUMMARY:\n");
        printf(" %s gross income: $%lld                         Monthly production cost:$%lld \n", month[mthnumber], salary + gross_income, shown_prod_costs);
        printf(" %s net income:$%lld                              Expenses(salaries+rent+personal+taxes):$%lld\n", month[mthnumber], salary + profit - (salary * 45 / 100),expenses+rent+taxes+interest);
        printf(" Customers this month:%i (!THIS IS AN APPROXIMATION) \n", distrib9(gen));
        printf(" Next month: %s                                 Tips:$%lld \n",month[(mthnumber+1)%12],tips);
        printf(" Total money: $%lld                                 Yearly inflation rate: %lld%% \n", savings, inflation);

        printf("\n Press anything to continue...\n\n ");
        _getch();
        savings += tips;

        decision = '?';
        while (decision != '8' && (decision != '0' || sellStore == 0))
        {
            if(2000*locationsOwned<customers)printf(" !YOUR LOCATIONS ARE GETTING OVERWHELMED, IT'S GETTING TOO BUSY");
            if(2200*locationsOwned<customers)customers=2200*locationsOwned;
            printf(" Would you like to make some changes to your brand?");
            printf(" \n Total money: $%lld", savings);

            printf("\n\n 0.Sell %s", brandName);
            printf("\n 1.Change coffee prices");
            printf("\n 2.Manage employees");
            printf("\n 3.Make a partnership or event");
            printf("\n 4.Do marketing");
            printf("\n 5.Expand %s(Open new locations)", brandName);
            printf("\n 6.Buy something for the store");
            printf("\n 7.Buy something for myself");
            printf("\n 8.No");
            if (job == true) printf("\n 9.Quit my job");
            printf("\n ");
            std::cin>>decision;
            std::cin.ignore(99999, '\n');

            switch (decision)
            {
            case '0':
                sellStore = (reputation * customers) / 10;
                printf("\n Your store is worth $%lld, are you willing to sell it?\n 1.I am not \n 2.Sell it\n", sellStore);
                if (onemil == 1) printf("\n 3.End without selling \n ");
                std::cin>>onetime;
                std::cin.ignore(99999, '\n');
                if (onetime == '2')savings += sellStore;
                if (onetime == '1')sellStore = 0;
                if (onetime == '3' && onemil == 1 && savings>=1000000) rich = 1;
                break;
            case '1':
                ChangeMenu(drinks, prices, production_costs,quantity,bought);
                break;
            case '2':
                if (age < 23)
                {
                    printf(" Can't do that yet.");
                    printf(" Press anything to continue...\n");
                    _getch();
                    break;
                }
                printf("\n 1.Hire someone (Tip: employees make your job easier)\n 2.Raise Salaries (Tip: you should make your employees feel good)\n 3.Fire someone \n 4.Go back\n ");
                std::cin.clear();
                std::cin>>anotherdecision;
                std::cin.ignore(99999, '\n');
                switch (anotherdecision)
                {
                case '1':
                    if (employees == 5)
                    {
                        printf("\n You have reached maximum capacity.");
                        printf("Press anything to continue...\n\n");
                        _getch();
                        break;
                    }
                    if (Hire(employee, names, forenames, employees) == 1)
                    {
                        expenses += employee[employees-1].salary;
                    }
                    break;
                case '2':
                {
                    if (employees < 1) 
                    {
                        printf("You don't have any employees.");
                        _getch();
                        break;
                    }
                    int raise;
                    for (int i = 0; i < employees; i++)
                    {
                        printf("\n Name:%s %s   Happniness:%i  Salary:$%i", employee[i].name, employee[i].forename, employee[i].mood, employee[i].salary);
                    }
                    printf("\n\n Do you want to raise all salaries?\n 1.Yes\n 2.No\n ");
                    std::cin>>onetime;
                    std::cin.ignore(99999, '\n');
                    if (onetime == '1')
                    {
                        printf("\n By how much? (Tip:sum*number of employees)\n ");
                        std::cin>>raise;
                        std::cin.ignore(99999, '\n');
                        for (int i = 0; i < employees; i++)
                        {
                            employee[i].salary += raise;
                            expenses += raise;
                            employee[i].mood += raise;
                            if (employee[i].mood > 100)employee[i].mood = 100;
                        }
                    }
                    break;
                }
                case '3':
                    if (employees > 0)
                    {
                        int i;
                        for (i = 0; i < employees; i++)
                        {
                            printf("\n\n %i.Fire %s %s\n Personality:\n -Charisma:%i \n -Politeness:%i \n -Insight(Perspicacity):%i \n -Aggressiveness:%i \n -Laziness:%i\n Salary:$%i/month", i, employee[i].forename, employee[i].name, employee[i].charisma, employee[i].politeness, employee[i].insight, employee[i].aggressiveness, employee[i].laziness, employee[i].salary);
                        }
                        printf("\n %i.Go back\n ", i);
                        std::cin>>i;
                        if (i < employees)
                        {
                            employees--;
                            expenses -= employee[i].salary;
                            for (int j = i; j < employees; j++)
                            {
                                employee[j] = employee[j + 1];
                            }
                        }
                        std::cin.ignore(99999, '\n');
                    }
                    else
                    {
                        printf("\n There are no employees, who do you want to fire?");
                        _getch();
                    }
                    break;
                default:
                    break;
                }
                break;
            case '3':
                printf("\n 1.Make a partnership\n 2.Create an event\n 3.Go back\n ");
                std::cin>>anotherdecision;
                std::cin.ignore(99999, '\n');
                switch (anotherdecision)
                {
                case '1':
                {
                    static int partners[5] = { 0 };
                    if (availPart == false)
                    {
                        printf("\n You can only do 1 partnership per year.\n Okay...");
                        _getch();
                        break;
                    }
                    if (reputation <= 450)
                    {
                        printf("\n You don't have enough reputation yet, keep growing your business. ");
                        _getch();
                        break;
                    }
                    printf("\n\n Available partenerships:");
                    if (reputation > 450)
                    {
                        printf("\n 1.%s, contract cost:$20000", partnerships[0]);
                    }
                    if (reputation > 700)
                    {
                        printf("\n 2.%s, contract cost:$30000", partnerships[1]);
                    }
                    if (reputation > 800)
                    {
                        printf("\n 3.%s, contract cost:$40000", partnerships[2]);
                    }
                    if (reputation > 1000)
                    {
                        printf("\n 4.%s, contract cost:$60000", partnerships[3]);
                    }
                    if (reputation > 1300)
                    {
                        printf("\n 5.%s, contract cost:$90000", partnerships[4]);
                    }
                    printf("\n 6.Go back");
                    printf("\n Total money:$%lld (You need 2x contract cost in order to make any partnership)", savings);
                    printf("\n ");
                    std::cin>>onetime;
                    std::cin.ignore(99999, '\n');
                    if (onetime == '6')break;

                    switch (onetime)
                    {
                    case '1':
                        if (partners[0] == 1) {
                            printf("\n You already have a partnership with %s", partnerships[0]);
                            _getch();
                            break;
                        }
                        if (savings < 40000) {
                            printf("\n You don't have enough money for this partnership.");
                            _getch();
                            break;
                        }
                        trust++;
                        availPart = 0;
                        partners[0] = 1;
                        savings -= 20000;
                        customers += 600;
                        printf(" Congrats on your partnership with %s.", partnerships[0]);
                        _getch();
                        break;
                    case '2':
                        if (partners[1] == 1) {
                            printf("\n You already have a partnership with %s", partnerships[1]);
                            _getch();
                            break;
                        }
                        if (savings < 60000) {
                            printf("\n You don't have enough money for this partnership.");
                            _getch();
                            break;
                        }
                        if (reputation <= 700) {
                            printf("\n This is not an option.");
                            _getch();
                            break;
                        }
                        trust++;
                        availPart = 0;
                        partners[1] = 1;
                        savings -= 30000;
                        customers += 800;
                        printf(" Congrats on your partnership with %s.", partnerships[1]);
                        break;
                    case '3':
                        if (partners[2] == 1) {
                            printf("\n You already have a partnership with %s", partnerships[2]);
                            _getch();
                            break;
                        }
                        if (savings < 80000) {
                            printf("\n You don't have enough money for this partnership.");
                            _getch();
                            break;
                        }
                        if (reputation <= 800) {
                            printf("\n This is not an option.");
                            _getch();
                            break;
                        }
                        trust++;
                        availPart = 0;
                        partners[2] = 1;
                        savings -= 80000;
                        customers += 900;
                        printf(" Congrats on your partnership with %s.", partnerships[2]);
                        break;
                    case '4':
                        if (partners[3] == 1) {
                            printf("\n You already have a partnership with %s", partnerships[3]);
                            _getch();
                            break;
                        }
                        if (savings < 120000) {
                            printf("\n You don't have enough money for this partnership.");
                            _getch();
                            break;
                        }
                        if (reputation <= 1000) {
                            printf("\n This is not an option. Press anything to continue...\n\n");
                            _getch();
                            break;
                        }
                        trust++;
                        availPart = 0;
                        partners[3] = 1;
                        savings -= 60000;
                        customers += 1100;
                        printf(" Congrats on your partnership with %s.", partnerships[3]);
                        break;
                    case '5':
                        if (partners[4] == 1) {
                            printf("\n You already have a partnership with %s", partnerships[4]);
                            _getch();
                            break;
                        }
                        if (savings < 180000) {
                            printf("\n You don't have enough money for this partnership.");
                            _getch();
                            break;
                        }
                        if (reputation <= 1300) {
                            printf("\n This is not an option.");
                            _getch();
                            break;
                        }
                        trust++;
                        availPart = 0;
                        partners[4] = 1;
                        savings -= 90000;
                        customers += 1300;
                        printf(" Congrats on your partnership with %s.", partnerships[4]);
                        break;
                    default:
                        break;
                    }
                    
                break;
                }
                case '2':
                {
                    int type;
                    printf("\n\n 1.Organize a concert(stage and tables required) (Tip: concerts modify production costs and and sells for a short period of time)\n 2.Change logo($500) (Tip: customers may or may not like it)\n 3.Go back\n ");
                    std::cin>>onetime;
                    std::cin.ignore(99999, '\n');
                    switch (onetime)
                    {
                    case '1':
                        if (concert == 1)
                        {
                            printf(" There is already a concert scheduled for this month.");
                            _getch();
                            break;
                        }
                        if (sold[firstStore][8] == 0)
                        {
                            printf(" You don't have a stage.");
                            _getch();
                            break;
                        }
                        if (sold[firstStore][1] == 0)
                        {
                            printf(" People don't have where to sit.");
                            _getch();
                            break;
                        }
                        printf("\n\n Which band/singer would you like to bring?\n 1.Bazooka($8000)\n 2.Connect-R($12000) \n 3.Smiley($15000)\n 4.Arctic Monkeys($75000)\n 5.Dua Lipa($250000)\n 6.Pitbull($125000)\n 7.ACDC($50000)\n 8.Ed Sheeran($500000)\n 9.Justin Bieber($500000)\n 10.Go back\n ");
                        std::cin>>type;
                        std::cin.ignore(99999, '\n');
                        switch (type)
                        {
                        case 1:
                            if (savings > 8000) 
                            {
                                hype = 2;
                                savings -= 8000;
                                happiness += 5;
                                printf(" Bazooka will come to your coffee shop this month.");
                                concert = 1;
                                _getch();
                            }
                            else {
                                printf("\n You don't have enough money.");
                                _getch();
                            }
                            break;
                        case 2:
                            if (savings > 12000) 
                            {
                                hype = 3;
                                savings -= 12000;
                                happiness += 10;
                                printf(" Connect-R will come to your coffee shop this month.");
                                concert = 1;
                                _getch();
                            }
                            else {
                                printf("\n You don't have enough money.");
                                _getch();
                            }
                            break;
                        case 3:
                            if (savings > 15000) 
                            {
                                hype = 4;
                                savings -= 15000;
                                happiness += 15;
                                printf(" Smiley will come to your coffee shop this month.");
                                concert = 1;
                                _getch();
                            }
                            else {
                                printf("\n You don't have enough money.");
                                _getch();
                            }
                            break;
                        case 4:
                            if (savings > 75000) 
                            {
                                hype = 6;
                                savings -= 75000;
                                happiness += 25;
                                printf(" Arctic Monkeys will come to your coffee shop this month.");
                                concert = 1;
                                _getch();
                            }
                            else {
                                printf("\n You don't have enough money.");
                                _getch();
                            }
                            break;
                        case 5:
                            if (savings > 250000) 
                            {
                                hype = 8;
                                savings -= 250000;
                                happiness += 40;
                                printf(" Dua Lipa will come to your coffee shop this month.");
                                concert = 1;
                                _getch();
                            }
                            else {
                                printf("\n You don't have enough money.");
                                _getch();
                            }
                            break;
                        case 6:
                            if (savings > 125000) 
                            {
                                hype = 7;
                                savings -= 125000;
                                happiness += 30;
                                printf(" Pitbull will come to your coffee shop this month.");
                                concert = 1;
                                _getch();
                            }
                            else {
                                printf("\n You don't have enough money.");
                                _getch();
                            }
                            break;
                        case 7:
                            if (savings > 50000) 
                            {
                                hype = 5;
                                savings -= 50000;
                                happiness += 20;
                                printf(" ACDC will come to your coffee shop this month.");
                                concert = 1;
                                _getch();
                            }
                            else {
                                printf("\n You don't have enough money.");
                                _getch();
                            }
                            break;
                        case 8:
                            if (savings > 500000) 
                            {
                                hype = 10;
                                savings -= 500000;
                                happiness += 50;
                                printf(" Ed Sheeran will come to your coffee shop this month.");
                                concert = 1;
                                _getch();
                            }
                            else {
                                printf("\n You don't have enough money.");
                                _getch();
                            }
                            break;
                        case 9:
                            if (savings > 500000)
                            {
                                hype = 10;
                                savings -= 500000;
                                happiness += 50;
                                printf(" Justin Bieber will come to your coffee shop this month.");
                                concert = 1;
                                _getch();
                            }
                            else {
                                printf("\n You don't have enough money.");
                                _getch();
                            }
                            break;

                        default:
                            break;
                        }
                        break;

                    case '2':
                    {
                        savings -= 500;
                        std::uniform_int_distribution<> distrib2(0, 1);
                        if (distrib2(gen) == 0)
                        {
                            printf("\n Customers didn't like your new logo.");
                            happiness -= 10;
                            _getch();
                            break;

                        }
                        printf("\n Customers liked your new logo.");
                        happiness += 10;
                        _getch();
                        break;
                    }
                    default:
                        break;
                    }

                    break;
                }
                default:
                    break;

                }

                break;
            case '4':
                printf("\n How much money would you like to spend on marketing?");
                Marketing(savings, marketing, customers);
                break;
            case '5':
            {
                printf("\n 1.Buy current property");
                printf("\n 2.Open new location\n ");
                std::cin>>anotherdecision;
                std::cin.ignore(99999, '\n');

                if (anotherdecision == '1') {
                    printf("\n Would you like to buy the property for the current store for $%lld?\n Total money:$%lld\n 1.Mine now \n 2.Not yet\n ", 100 * rent, savings);
                    std::cin>>onetime;
                    std::cin.ignore(99999, '\n');
                    if (onetime == '1')
                    {
                        if (savings + 5000 <= 100 * rent)
                        {
                            printf("\n You don't have enough money.\n");
                            _getch();
                        }
                        else
                        {
                            for (int i = 0; i < 5; i++)
                            {
                                if (owned[i] != rented[i])
                                {
                                    owned[i] = 1;
                                    strcat(locations[i], " (owned)");
                                }
                            }
                            savings -= 100 * rent;
                            rent = 0;

                            printf(" You own the location now, congrats!");
                            _getch();
                        }
                    }
                    else break;
                }
                int ok = 1;
                if (anotherdecision == '2')
                {
                    for (int i = 0; i < 5; i++)
                    {
                        if (owned[i] != rented[i])
                        {
                            ok = 0;
                        }
                    }

                    if (ok == 0)
                    {
                        printf(" You must own the current property first.\n");
                        _getch();
                    }
                    if (employees < locationsOwned)
                    {
                        printf(" You need to hire more employees first.\n");
                        _getch();
                        break;
                    }
                    if (ok == 1)
                    {
                        First_rent(savings, rent, decision, customers, locations, rented, locationsOwned);
                    }
                }

                break;
            }
            case '6':
            {
                int i;
                printf("\n For which location would you like to buy? (Tip: improving the main location gives you bonuses)");
                for (i = 0; i <= 4; i++)
                {
                    if (rented[i] == 1)printf("\n %i.%s", i + 1, locations[i]);
                    if (i == firstStore)printf("(main location)");
                }

                printf("\n 6.Go back\n ");
                std::cin>>i;
                std::cin.ignore(99999, '\n');
                if (i == 6) break;
                i--;
                Shopping(sold, customers, savings, happiness, i, expenses,firstStore);
                break;
            }
            case '7':
            {
                int i = 0;
                printf("\n Total money: $%lld \n ", savings);
                printf("\n What would you like to buy?");
                while (i != 6)
                {
                    for (i = 0; i < 6; i++)
                    {
                        printf("\n %i.%s", i, items[i]);
                    }
                    printf("\n 6.Go back\n ");
                    std::cin>> i;
                    std::cin.ignore(99999, '\n');
                    i;


                    switch (i)
                    {
                    case 0:
                        if (savings > 5000)
                        {
                            savings -= 5000;
                            printf(" You got yourself a brand new %s.", items[0]);
                        }
                        else 
                        {
                            printf("\n You don't have enough money.");
                            _getch();
                        }
                        break;

                    case 1:
                        if (savings > 300000)
                        {
                            printf("\n Choose payment method: \n 1.Cash down \n 2.One year installment(Monthly with 12%% interest)\n 3.Go back\n ");
                            std::cin>> onetime;
                            std::cin.ignore(99999, '\n');
                            switch (onetime)
                            {
                            case '1':
                                savings -= 300000;
                                printf(" You got yourself a brand new %s.", items[1]);
                                break;

                            case '2':
                                intRate = 12;
                                interest = 300000 / 12 + 300000 / 100;
                                printf(" You got yourself a brand new %s.", items[1]);
                                break;

                            default:
                                break;
                            }
                        }
                        else 
                        {
                            printf(" We both know you can't afford this.");
                            _getch();
                        }
                        break;

                    case 2:
                        if (savings > 90000)
                        {
                            printf("\n Choose payment method: \n 1.Cash down \n 2.One year installment(Monthly with 12%% interest)\n 3.Go back\n ");
                            std::cin>>onetime;
                            std::cin.ignore(99999, '\n');
                            switch (onetime)
                            {
                            case '1':
                                savings -= 90000;
                                printf(" You got yourself a brand new %s.", items[2]);
                                break;

                            case '2':
                                intRate = 12;
                                interest = 90000 / 12 + 90000 / 100;
                                printf(" You got yourself a brand new %s.", items[2]);
                                break;

                            default:
                                break;
                            }
                        }
                        else 
                        {
                            printf(" We both know you can't afford this.");
                            _getch();
                        }
                        break;

                    case 3:
                        if (savings > 500000)
                        {
                            printf("\n Choose payment method: \n 1.Cash down \n 2.One year installment(Monthly with 12%% interest)\n 3.Go back\n ");
                            std::cin>>onetime;
                            std::cin.ignore(99999, '\n');
                            switch (onetime)
                            {
                            case '1':
                                savings -= 500000;
                                printf(" You got yourself a brand new %s.", items[3]);
                                break;

                            case '2':
                                intRate = 12;
                                interest = 500000 / 12 + 500000 / 100;
                                printf(" You got yourself a brand new %s.", items[3]);
                                break;

                            default:
                                break;
                            }
                        }
                        else 
                        {
                            printf(" We both know you can't afford this.");
                            _getch();
                        }
                        break;

                    case 4:
                        if (savings > 20000)
                        {
                            savings -= 20000;
                            printf(" You got yourself a brand new %s.", items[4]);
                        }
                        else 
                        {
                            printf(" We both know you can't afford this.");
                            _getch();
                        }
                        break;

                    case 5:
                        if (savings > 45000)
                        {
                            savings -= 45000;
                            printf(" You got yourself the brand new %s.", items[5]);
                        }
                        else 
                        {
                            printf(" We both know you can't afford this.");
                            _getch();
                        }
                        break;

                    default:
                        break;

                    }
                    break;
                }
            }
            case '8':

                break;
            case '9':
                if (job == false)
                {
                    decision = '?';
                    printf(" I am sorry, but that is not an option.\n");
                    _getch();
                    break;
                }
                printf("\n Are you sure? You wouldn't get the job salary anymore but you would have more time to work develop your business.\n 0.I'm out of there \n 1.Not yet\n ");
                std::cin >> job;
                std::cin.ignore(99999, '\n');
                if (job == false)
                {
                    time += 8;
                    salary = 0;
                    customers = customers * 4;
                }
                break;

            default:
                decision = '?';
                printf(" I am sorry, but that is not an option.\n");
                _getch();
                break;
            }

        }


        if (mthnumber == 11)
        {
            //The player gets older
            age++;
            mthnumber = 0;
            printf("\n It's your birthday, you are now %lld!\"confetti falling\"", age);
            printf("\n Due to the yearly inflation, your cash is worth %lld%% less \n", inflation);
            _getch();
            savings = savings - 15 * savings / 100;
            availPart = true;
        }

        if (savings >= 1000000 && onemil==0)
        {
            onemil = 1;
            printf("\n So, your business was a success, congratulations for making great decisions(Or maybe you cheated, it's none of my business)! You can end the game if you want to, or you can keep playing to see how much you can grow your business. (You will now see this ending available in the Sell section as long as you have over 1 million dollars)\n\n Do you want to keep playing?\n 0.Yes \n 1.No");
            std::cin >> rich;
            std::cin.ignore(99999, '\n');
        }

        if (reputation < 500)
        {
            std::uniform_int_distribution<> distrib6(10, 40);
            customers -= distrib6(gen);
        }
        
        for (int i = 0; i < employees; i++)
        {
            if (employee[i].salary >= 10000)employee[i].mood=100;
            employee[i].mood -= 5;
            if (employee[i].mood <= 0)
            {
                printf("\n %s %s didn't feel their efforts were appreciated and quit.\n", employee[i].forename, employee[i].name);
                _getch();
                happiness -= 5;
                expenses -= employee[i].salary;
                for (int j = i; j < employees; j++)employee[j] = employee[j + 1];
                employees--;
            }
        }

        concert = 0;
        mthnumber++;
        nr1 = false;
    }

    if (age == 70)
    {
        printf("\n\n Hey, you are 70 years old, you don't need to work anymore. Just sit back and rest, you have done a great job, you created a successful business which will be passed down to your children, good for you.(Good ending)\n");
        printf("        Oh, and Thank You for Playing \"The Cafe Sim\" by Filimon Stefan Mihai");
        _getch();
        return 0;
    }

    if (savings + salary <= 0 || customers <= 0)
    {
        printf("\n\n Unfortunately the coffee shop didn't work out, but don't get discouraged, you can always try again, and this time you have the experience gathered along the way by your side. As long as you don't give up, everything will work out fine.");
        _getch();
        return 0;
    }

    if (sellStore > 0)
    {
        if (age < 50)printf("\n\n Well, you sold the brand but now you have got to go back to work, the money you have won't last forever.(Bad ending)");
        else printf("\n\n Now that you sold the brand and you are a little too old to get a new job, you will have to manage with the money from the coffee shop and hope that your kids will help you when you need them.(Bad ending)");
        _getch();
        return 0;
    }
    if (rich == 1)
    {
        printf("\n\n Now that you have created very successful business which is constantly growing and reached more than 1 million dollars in cash, you should make some time for yourself, take a vacation, explore this beautiful world and always keep growing, personally and profesionally.(Good ending)\n");
        printf("          Oh, and Thank You for Playing \"The Cafe Sim\" by Filimon Stefan Mihai");
        _getch();
        return 0;
    }
    return 0;
}