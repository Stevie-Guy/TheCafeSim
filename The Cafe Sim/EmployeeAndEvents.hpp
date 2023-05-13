struct character
{
    char name[10],forename[10];
    int charisma,politeness,insight,laziness,aggressiveness,mood;
    int salary;
};


int Hire(character emp[5],char names[10][10],char forenames[10][10], long long &nrofemp){
    srand((unsigned)time(NULL));
    std::mt19937 gen(rand()); 
    int choice=2;

    while (choice==2)
    {
        std::uniform_int_distribution<> distrib3(25, 100);
        //players shouldn't spend too much time searching for a good employee
        std::uniform_int_distribution<> distrib4(50, 100);
        strcpy(emp[nrofemp].name,names[distrib3(gen)%10]);
        strcpy(emp[nrofemp].forename,forenames[distrib3(gen)%10]);
        emp[nrofemp].charisma=distrib4(gen);
        emp[nrofemp].politeness=distrib4(gen);
        emp[nrofemp].insight=distrib3(gen);
        emp[nrofemp].laziness=distrib3(gen);
        emp[nrofemp].aggressiveness=distrib3(gen);
        emp[nrofemp].mood=100;
        if(((emp[nrofemp].charisma*emp[nrofemp].politeness)/2+emp[nrofemp].insight*10-(emp[nrofemp].aggressiveness*emp[nrofemp].laziness)/2)<1000)emp[nrofemp].salary=1000;
        else emp[nrofemp].salary=(emp[nrofemp].charisma*emp[nrofemp].politeness)/2+emp[nrofemp].insight*10-(emp[nrofemp].aggressiveness*emp[nrofemp].laziness)/2;
        printf(" \n\n Name:%s %s\n Personality:\n -Charisma:%i(25-100) \n -Politeness:%i(25-100) \n -Insight(Perspicacity):%i(25-100) \n -Aggressiveness:%i(25-100) \n -Laziness:%i(25-100)\n Salary:$%i/month",emp[nrofemp].forename,emp[nrofemp].name,emp[nrofemp].charisma,emp[nrofemp].politeness,emp[nrofemp].insight,emp[nrofemp].aggressiveness,emp[nrofemp].laziness,emp[nrofemp].salary);
        printf("\n\n 1.Employ     2.Next     3.I don't want to employ\n ");
        std::cin>>choice;
        std::cin.ignore(99999, '\n');
    }
    
    
    if(choice==1)
    {
        printf(" \n %s %s is now your employee.\n ", emp[nrofemp].forename, emp[nrofemp].name);
        _getch();
        nrofemp++;
        return 1;
    }
    else return 0;
}
