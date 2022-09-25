#include <iostream>
#include <iomanip>
using namespace std;
double CalcToll(int hour, bool isMorning, bool isWeekend);
// Code function prototype here
int main() {
	cout << CalcToll(8, true, false) << endl;   // 2.95
	cout << CalcToll(1, false, false) << endl;  // 1.9
	cout << CalcToll(3, false, true) << endl;   // 2.15
	cout << CalcToll(5, true, true) << endl;    // 1.05

	return 0;
}

double CalcToll(int hour, bool isMorning, bool isWeekend) {
	switch (isWeekend)
	{
	   case true:
	      if (isMorning)
	      {
	         switch (hour)
	         {
	            case 1:
	            case 2:
	            case 3:
	            case 4:
	            case 5:
	            case 6:
	        return 1.05;
	               break;
	        }
	      }
	      else
	      {
	         if (hour == 12 or (hour >= 1 and hour < 8))
	         {
	            return 2.15;
	            }
	        else
	        {
	           return 1.10;
	           }
	      }
	      break;
	   case false:
	   	if (isMorning)
	      {
	         switch(hour)
	                                                                                                                              
	   case 12:                                                                                                                           {
case 1:
case 2:
                                                                                                      case 3:
case 4:
                                                                                                                              case 5:
case 6:
                     return 1.15;
                  case 7:
                     case 8:
                  case 9:
                          return  2.95;
               case 10:
         case 11:
      return 1.90;
break;                        
}
	      }
	      else
	      {
	         if (hour == 12 or (hour   >= 1 and hour <=    
	         2)) { return 1.90;} else if 
	         (hour >= 3 and hour<=7)
	        {
	           
	                        return  3.95 ;                                                                                                                                                                   }
	                        else
	                                                      if(hour >= 8 and hour < 12)              {
	                                                         
	                                                         return 1.40
	                       ;}
	      }
	      break;
	}
	return -1;
}
