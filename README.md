Created map:

![Image](https://github.com/user-attachments/assets/a7cba2cb-19ed-467a-8e00-d8e3ded51706)

Sensor Reading: 

[robot.csv](https://github.com/user-attachments/files/18854046/robot.csv)

Steps:
1.	Marking every cell of the grid with an unknown status which is 0.5 where the certainty increases toward 1 or decreases toward 0.
2.	Reading the data provided in the “robot.csv”.
3.	Converting real-world positions to corresponding grid cell.
4.	Checking the probability of existence of an obstacle depending on sensors readings.
5.	Assuming the sensors are very accurate if they detect an object, the probability increases by 0.4 and decreases by 0.1 if not. (Pragmatic approach)
6.	Printing the map using “x” as free space and “O” if not. 
