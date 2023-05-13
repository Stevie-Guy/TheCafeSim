void Marketing(long long &savings, long long &marketing,long long &customers )
{
printf("\n Total money:$%lld (Tip: marketing is more efficient when your business is small) \n $",savings);
std::cin>>marketing;
std::cin.ignore(999999, '\n');
static long long mark = 0;

if (mark > 1000000)
{
    printf("\n More marketing is pointless.");
    _getch();
}
else
{
    mark += marketing;
    if (customers != 0)
    {
        if (marketing > 100000) customers += marketing / 1000;
        else if (marketing > 10000) customers += marketing / 100;
        else
        {
            if (customers < 1500) customers += marketing / 10;
            else customers += marketing / 20;
        }
    }
    else customers += marketing * 20 / 100;

    savings -= marketing;
}
}


int First_rent(long long &savings, long long &rent, char &decision, long long &customers, char (&loc)[6][70], long long (&onrent)[6],long long &locationsOwn)
{
int i;
decision='0';
int k=0;
while(decision=='0')
{
    printf("\n\n Total money: $%lld \n",savings);

    for ( i = 1; i <= 4 ; i++)
    {
        printf("\n %i.%s",i,loc[i-1]);
    }

    if(onrent[0]==1 ||onrent[1]==1 ||onrent[2]==1 ||onrent[3]==1)
    {
        printf("\n %i.%s",i,loc[i-1]);
        printf("\n 6.Go back");
        k=1;
    }
    printf("\n ");
    
    std::cin>>decision;
    std::cin.ignore(99999,'\n');

    if(decision=='6' && k==1)
        return 0;


    switch (decision)
    {
    case '1':
        if(onrent[0]==0)
        {
            locationsOwn++;
            onrent[0]=1;
            customers+=400;
            rent+=2000;
            return 0;
        }else 
        {
            printf("\n You already own this location.");
            _getch();
        }
        break;

    case '2':
        if(onrent[1]==0)
        {
            locationsOwn++;
            onrent[1]=1;
            customers+=250;
            rent+=800;
            return 1;
        }else 
        {
            printf("\n You already own this location.");
            _getch();
        }
        break;

    case '3':
        if(onrent[2]==0)
        {
            locationsOwn++;
            onrent[2]=1;
            customers+=300;
            rent+=1000;
            return 2;
        }else 
        {
            printf("\n You already own this location.");
            _getch();
        }
        break;

    case '4':
        if(onrent[3]==0)
        {
            locationsOwn++;
            onrent[3]=1;
            customers+=200;
            rent+=400;
            return 3;
        }else 
        {
            printf("\n You already own this location.");
            _getch();
        }
        break;

    case '5':
        if (k==1){
            if(onrent[4]==0)
            {
                locationsOwn++;
                onrent[4]=1;
                customers+=350;
                rent+=1600;
            }
            }else 
            {
                printf("\n You already own this location.");
                _getch();
            }
        break;
    default:
        printf("\n I am sorry, but that is not an option.\n\n");
        _getch();
        decision='0';
        break;
    }
}

}