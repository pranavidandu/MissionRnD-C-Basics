/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int check_leap_year(int year, char *dob){
	if (year % 400 == 0)
		return 1;
	else if (year % 100 == 0)
	{
		if (dob[0] == '2' && dob[1] == '9' && dob[3] == '0' && dob[4] == '2')
			return 0;
	}
	else if (year % 4 == 0)
		return 1;
	else
		return 0;
}
int check_year(char *dob1, char *dob2){
	int year1 = 0, year2 = 0;
	for (int i = 6; i <= 9; i++)
		year1 = year1 * 10 + dob1[i] - '0';
	for (int i = 6; i <= 9; i++)
		year2 = year2 * 10 + dob2[i] - '0';
	//Function to check leap year
	int leap = check_leap_year(year1, dob1);
	if (leap == 0)
		return -1;
	leap = check_leap_year(year2, dob2);
	if (leap == 0)
		return -1;
	if (year1 < year2)
		return 1;
	else if (year1 > year2)
		return 2;
	else if (year1 == year2)
		return 0;
	return -1;
	
}
int check_month(char *dob1, char *dob2){
	int mon1 = 0, mon2 = 0;
	for (int i = 3; i <= 4; i++)
		mon1 = mon1 * 10 + dob1[i] - '0';
	for (int i = 3; i <= 4; i++)
		mon2 = mon2 * 10 + dob2[i] - '0';
	if (mon1 < 0 || mon1 > 12 || mon2 < 0 || mon2 > 12)
		return -1;
	if (mon1 < mon2)
		return 1;
	else if (mon1 > mon2)
		return 2;
	else if (mon1 == mon2)
		return 0;
	return -1;
}
int check_date(char *dob1, char *dob2){
	int date1 = 0, date2 = 0;
	for (int i = 0; i <= 1; i++)
		date1 = date1 * 10 + dob1[i] - '0';
	for (int i = 0; i <= 1; i++)
		date2 = date2 * 10 + dob2[i] - '0';

	if (date1 < date2)
		return 1;
	else if (date1 > date2)
		return 2;
	else if (date1 == date2)
		return 0;
	return -1;
}
int valid_input(char *dob1, char *dob2){
	int len1 = 0, len2 = 0;
	int i = 0, j = 0;
	while (dob1[i] != '\0'){
		len1++;
		i++;
	}
	while (dob2[j] != '\0'){
		len2++;
		j++;
	}
	if (len1 < 10 || len2 < 10)
		return 0;
	i = 0;
	while (i < len1){
		if (i == 2 || i == 5){
			i++;
			continue;
		}
		else if (dob1[i] < 48 || dob1[i] > 57 || dob2[i] < 48 || dob2[i] > 57){
			return 0;
		}
		i++;
	}
	return 1;
}
int isOlder(char *dob1, char *dob2) {
	// Function to check if the given input is in correct format
	int valid = valid_input(dob1, dob2);
	if (valid == 0)
		return -1;
	else{
		//Function to compare years
		int year = check_year(dob1, dob2);
		if (year == 1)//year1 > year2
			return 1;
		else if (year == 2)//year1 < year2
			return 2;
		else if (year == -1)// wrong input
			return -1;
		else{
			//Function to compare months
			int mon = check_month(dob1, dob2);
			if (mon == 1)// mon1 > mon2
				return 1;
			else if (mon == 2)// mon1 < mon2
				return 2;
			else if (mon == -1)//wrong input
				return -1;
			else{
				//Function to compare dates
				int date = check_date(dob1, dob2);
				if (date == 1)// date1 > date2
					return 1;
				else if (date == 2)// date1 < date2
					return 2;
				else if (date == 0)//Both are of same age
					return 0;
				else
					return -1;
		    }
		}
	}
}

