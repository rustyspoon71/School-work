lowest_life_country = ""
lowest_life_expectancy =float(999) 
lowest_life_year = int(1)
count = 0 
user_compare_low = float(9999)
user_compare_high = float(-1)
total_sum = float(0)
highest_life_year = int(1)
highest_life_country = ""
highest_life_expectancy = float(-1)
user_choice = int(input("What year would you like to learn more about? "))
with open("life-expectancy.csv") as data_set:
    for line in data_set:
        lines = line.split(",")
        country = lines[0].strip() 
        year = int(lines[2])
        life_expectancy = float(lines[3])
        if user_choice == year:
            count = count + 1
            total_sum += life_expectancy
            if life_expectancy < user_compare_low:
                    user_lowest_country = country
                    user_compare_low = life_expectancy 
            elif life_expectancy > user_compare_high:
                    user_highest_country = country   
                    user_compare_high = life_expectancy    
        if life_expectancy < lowest_life_expectancy:
            lowest_life_year = year
            lowest_life_country = country
            lowest_life_expectancy = life_expectancy                   
        elif life_expectancy > highest_life_expectancy:
            highest_life_year = year 
            highest_life_country = country 
            highest_life_expectancy = life_expectancy
average = total_sum / count 
if user_highest_country == highest_life_country:
    print(f'What a great year for Monaco again! The country Monaco was the highest in the {user_choice} and overall in the data set.')
print (f'The average of the year {user_choice} was {average} the highest life expectancy country was {user_highest_country} and the lowest country was {user_lowest_country}. ')
print (f'The year and the country that has the lowest life expectancy is the following {lowest_life_year} {lowest_life_country} with a life expectancy of: {lowest_life_expectancy}')
print (f'The year and the country that has the highest life expectancy is the following {highest_life_year} {highest_life_country} with a life expectancy of: {highest_life_expectancy}')
