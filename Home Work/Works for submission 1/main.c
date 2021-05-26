/*Submits: Shai Dahan and Sarel Alush
ID: Shai - 209462712
ID: Sarel - 316373851
*/

#include <stdio.h>

double house_cost, down_payment, intitial_savings, saving_annual_rate, morgage_annual_rate, intitial_monthly_salary
,raise_fraction, fraction_house_buying, monthly_rent;



int get_masknta_number(double savings,double house_cost)// return masknta that need to pay to the bank
{
    intitial_savings = 0;
    
    return house_cost-savings;
    
}
double rent_house(int monthEnd)// u know what it s u ask :)
{
	int month_counter_rh = 0;
	double intitial_monthly_salary_rh = intitial_monthly_salary;
	double intitial_savings_rh = intitial_savings;
	
	while(month_counter_rh<monthEnd)
	{
		intitial_savings_rh += intitial_savings_rh * (saving_annual_rate/12);
		intitial_savings_rh += (intitial_monthly_salary_rh*fraction_house_buying)-monthly_rent;
		month_counter_rh++;
		if(month_counter_rh%12==0){
			
			intitial_monthly_salary_rh += (intitial_monthly_salary_rh*raise_fraction);
		}
	}
	return intitial_savings_rh;
	
}
int main()
{
    printf("Enter (House-cost, down-payment, savings, savings-annual-rate, mortgage-annual-rate, salary, fraction-saving, annual-raise, house-rent): ");
    scanf("(%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf)",&house_cost , &down_payment, &intitial_savings, &saving_annual_rate, &morgage_annual_rate, &intitial_monthly_salary,
    &fraction_house_buying, &raise_fraction, &monthly_rent);
    double masknta = 0;
	double total_interest = 0;
	 
	
	double down_payment_copy = down_payment;
    double house_cost_copy = house_cost;
    double intitial_savings_copy = intitial_savings;
    double intitial_monthly_salary_copy = intitial_monthly_salary;
	int month_counter=0, year_count = 0;
	double return_money_per_month=0;
	double return_masknta_per_month = 0;
	double rh = 0;
	if(house_cost>intitial_savings)
	{
		double a = monthly_rent;
		double b = (intitial_monthly_salary*fraction_house_buying);
		if(a>b)
		{
			printf("Error: housing portion of the salary is insufficient to cover rent\n");	
			return 0;
		}
		
	}
	
	
	while((down_payment_copy*house_cost_copy) >= intitial_savings_copy)
	{
		intitial_savings_copy += intitial_savings_copy * (saving_annual_rate/12);
		intitial_savings_copy += (intitial_monthly_salary_copy*fraction_house_buying)-monthly_rent;

		month_counter++;
		if(month_counter%12==0){
			intitial_monthly_salary_copy += (intitial_monthly_salary_copy*raise_fraction);
			year_count++;
		}
	
	}
	printf("After %d years and %d months you will have enough money for the down payment\n",year_count,month_counter%12);
	
	
	masknta = house_cost-intitial_savings_copy;
	
	intitial_savings_copy = 0;
	return_money_per_month= intitial_monthly_salary_copy*fraction_house_buying;
	
	return_masknta_per_month = (masknta*(morgage_annual_rate/12));
	
	//Check if the return money is lower then the money u need turn back each year!
	if(return_money_per_month < return_masknta_per_month){
	    printf("Error the not enough money to return! ");
	    return 0;
	}

	while(masknta > 0)
	{
		month_counter++;
	    if(month_counter%12==0){
	        intitial_monthly_salary_copy += intitial_monthly_salary_copy*raise_fraction;
	    }
		total_interest += ((masknta*morgage_annual_rate)/12);
	    masknta += ((masknta*morgage_annual_rate)/12);
	    masknta -= return_money_per_month;
	
		intitial_savings_copy += (intitial_monthly_salary_copy*fraction_house_buying - return_money_per_month);
	    intitial_savings_copy += (intitial_savings_copy * (saving_annual_rate/12));
        
		

	    if(intitial_savings_copy > masknta){
	        masknta -= intitial_savings_copy;
	    }
		
	}
	rh = rent_house(month_counter);

	printf("After %d years and %d months you will cover the cost of the house\n",month_counter/12,month_counter%12);
	printf("Actual payment for the house: %.1lf\n",total_interest+house_cost);
	printf("House worth is %.1lf\n",house_cost);
	printf("Alternatively, if you rent you will end up with %.1lf\n",rh);
	
	
	
	
	
	
	
	system("pause");
}
