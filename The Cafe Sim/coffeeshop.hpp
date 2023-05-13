long long Quantity(long long  &saves,long long (&quan)[10],char (&menu)[10][30], long long (&costs)[10], long long (&lastbought)[10], long long (&dem)[10], long long (&price)[10]){
long long total_costs=0;
printf("\n\n Total money: $%lld (Tip:you can be up to $10000 in debt)", saves);

for (int i = 0; i < 10; i++)
{
    if (saves < -10000)
    {
        for (int j = i; j < 10; j++)quan[j] = 0;
        printf("\n You ran out of money.");
        _getch();
        return total_costs;
    }

    std::cout<<"\n "<<menu[i]<<", production cost:$"<<costs[i]<<" per cup,price:$"<<price[i]<<" (SOLD LAST MONTH : "<<lastbought[i]<<" OUT OF "<<quan[i]<<")";

    if (dem[i] < 25)printf(" EXTRA DEMAND LAST MONTH: LOW");
        else if (dem[i] <= 75)printf(" EXTRA DEMAND LAST MONTH: MEDIUM");
            else if (dem[i] <= 125)printf(" EXTRA DEMAND LAST MONTH: HIGH");
                else if (dem[i] < 500)printf(" EXTRA DEMAND LAST MONTH: VERY HIGH");
                    else if (dem[i] >= 500)printf(" EXTRA DEMAND LAST MONTH: EXTREMELY HIGH");

    printf("\n Quantity(This determines how many drinks of this type you can sell this month.):");
    std::cin>>quan[i];
    total_costs+=quan[i]*costs[i];
    std::cin.ignore(99999,'\n');
    saves -= quan[i] * costs[i];
    printf("\n\n Total money: $%lld ", saves);
}

return total_costs;
}


long long SameQuantity(long long& saves, long long(&quan)[10], char(&menu)[10][30], long long(&costs)[10], long long(&lastbought)[10], long long(&dem)[10], long long(&price)[10]) {
    long long total_costs = 0;

    for (int i = 0; i < 10; i++)
    {
        if (saves < -10000)
        {
            for (int j = i; j < 10; j++) quan[j] = 0;
            printf("\n You ran out of money.");
            _getch();
            return total_costs;
        }

        total_costs += quan[i] * costs[i];
        saves -= quan[i] * costs[i];
    }

    return total_costs;
}


void Shopping(bool (&sold)[5][10],long long &cust,long long &saves, long long &happy, int &storeLoc,long long &expens, long long first){
printf("\n\n What would you like to buy for your store?");
char choice='a';
while (choice!='9')
{
    if(choice=='1' && sold[storeLoc][1]==0 && saves>=1000){
        sold[storeLoc][1]=1;
        saves-=1000;
        happy+=6;
        cust+=45;
        printf("\n 1.Buy tables and couches?($1000) (sold out)");
    }else if (sold[storeLoc][1]==0)
    {
        printf("\n 1.Buy tables and couches?($1000)");
    }else
    {  
        printf("\n 1.Buy tables and couches?($1000) (sold out)");
    }
    if(choice=='2' && sold[storeLoc][2]==0 && saves>=1000){
        sold[storeLoc][2]=1;
        saves-=900;
        happy+=10;
        cust+=90;
        printf("\n 2.Buy better coffee machine?($900) (sold out)");
    }else if (sold[storeLoc][2]==0)
    {
        printf("\n 2.Buy better coffee machine?($900)");
    }else
    {  
        printf("\n 2.Buy better coffee machine?($900) (sold out)");
    }
    if(choice=='3' && sold[storeLoc][3]==0 && saves>=800)
    {
        sold[storeLoc][3]=1;
        saves-=800;
        happy+=8;
        cust+=90;
        printf("\n 3.Buy music player?($800) (sold out)");
    }else if (sold[storeLoc][3]==0)
    {
        printf("\n 3.Buy music player?($800)");
    }else
    {  
        printf("\n 3.Buy music player?($800) (sold out)");
    }
    if(choice=='4' && sold[storeLoc][4]==0 && saves>=300)
    {
        sold[storeLoc][4]=1;
        saves-=300;
        happy+=6;
        cust+=30;
        printf("\n 4.Buy decorations?($300) (sold out)");
    }else if (sold[storeLoc][4]==0)
    {
        printf("\n 4.Buy decorations?($300)");
    }else
    {  
        printf("\n 4.Buy decorations?($300) (sold out)");
    }
    if(choice=='5' && sold[storeLoc][5]==0 && saves>=100)
    {
        sold[storeLoc][5]=1;
        saves-=100;
        happy+=4;
        cust+=20;
        printf("\n 5.Buy POS?($100) (sold out)");
    }else if (sold[storeLoc][5]==0)
    {
        printf("\n 5.Buy POS?($100)");
    }else
    {  
        printf("\n 5.Buy POS?($100) (sold out)");
    }
    if(choice=='6' && sold[storeLoc][6]==0 && saves>=50)
    {
        sold[storeLoc][6]=1;
        saves-=50;
        printf("\n 6.Buy tips jar?($50) (sold out)");
    }else if (sold[storeLoc][6]==0)
    {
        printf("\n 6.Buy tips jar?($50)");
    }else
    {  
        printf("\n 6.Buy tips jar?($50) (sold out)");
    }
    if(choice=='7' && sold[storeLoc][7]==0 && saves>=300)
    {
        sold[storeLoc][7]=1;
        expens+=300;
        happy+=8;
        cust+=40;
        printf("\n 7.Buy cookies and sweets?($300 every month) (sold out)");
    }else if (sold[storeLoc][7]==0)
    {
        printf("\n 7.Buy cookies and sweets?($300 every month)");
    }else
    {  
        printf("\n 7.Buy cookies and sweets?($300 every month) (sold out)");
    }
    if(choice=='8' && sold[storeLoc][8]==0 && saves>=5000)
    {
        sold[storeLoc][8]=1;
        saves-=5000;
        happy+=30;
        cust+=200;
        printf("\n 8.Buy stage and karaoke set?($5000) (sold out)");
    }else if (sold[storeLoc][8]==0)
    {
        printf("\n 8.Buy stage and karaoke set?($5000)");
    }else
    {  
        printf("\n 8.Buy stage and karaoke set?($5000) (sold out)");
    }
    printf("\n 9.I don't want anything.");
    printf("\n Total money: $%lld\n ",saves);
    std::cin>>choice;
    std::cin.ignore(99999,'\n');
}

}