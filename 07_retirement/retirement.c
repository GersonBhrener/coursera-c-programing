#include <stdlib.h>
#include <stdio.h>

struct _retire_info{

  unsigned int months;
  double contribuition;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

void print_months_balance (int months, double balance){

  printf("Age %3d month %2d you have $%.2lf\n", months/12, months%12, balance);

}


double total (double balance, retire_info status ){

  balance += balance*status.rate_of_return;
  balance += status.contribuition;

  return balance;
}


void retirement (int startAge, double initial, retire_info working, retire_info retired){

  double balance = initial;

  int months_total = startAge-1;

  for (int i = 0; i < working.months; i++) {

    months_total++;
    print_months_balance(months_total, balance);
    balance = total(balance, working);
  }


  for (int j = 0; j < retired.months; j++) {

    months_total++;
    print_months_balance(months_total, balance);
    balance = total(balance, retired);
  }
}

int main (void){

  int startAge = 327;
  double initial = 21345;
  retire_info working, retired;

  //estrutura trabalho
  working.months = 489;
  working.contribuition = 1000;
  working.rate_of_return = 0.045/12;

  //estrutura aposentadoria
  retired.months = 384;
  retired.contribuition = -4000;
  retired.rate_of_return = 0.01/12;

  retirement (startAge, initial, working, retired);


}
