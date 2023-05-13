void Menu(char (&menu)[10][30], long long (&prices)[10], long long (&costs)[10])
{
for(int i=0;i<10;i++)
{
    std::cout<<' '<<menu[i]<<", production cost:$"<<costs[i]<<"\n Price: $";
    std::cin>>prices[i];
    std::cin.ignore(99999, '\n');
}
}

void ChangeMenu(char (&menu)[10][30], long long (&prices)[10], long long (&costs)[10], long long (&quan)[10], long long (&sell)[10])
{
int j;
do
{
    for(int i=0;i<10;i++)
    {
        std::cout<<"\n "<<i<<'.'<<menu[i]<<", production cost:$"<<costs[i]<<"\n Actual price: $"<<prices[i]<<"  (SOLD "<<sell[i]<<" OUT OF "<<quan[i]<<" THIS MONTH)";
    }
    printf("\n 10.Go back\n ");
    std::cin>>j;
    std::cin.ignore(99999, '\n');
    if(j==10)break;
    std::cout<<' '<<menu[j]<<", production cost:$"<<costs[j]<<"\n Actual price: $"<<prices[j];
    printf("\n New price:$");
    std::cin>>prices[j];
    std::cin.ignore(99999, '\n');
}while(j!=10);

}