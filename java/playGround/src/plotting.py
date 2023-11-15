import matplotlib.pyplot as plt 
import csv 
  
x = [] 
y = [] 
  
x1 = [] 
y1 = [] 

with open('FirstDsResults','r') as csvfile: 
    plots = csv.reader(csvfile, delimiter = ',') 
      
    for row in plots: 
        x.append(int(row[0])) 
        y.append(int(row[1]))
  
plt.plot(y, x, color = 'g', linestyle = 'dashed', 
         marker = 'o',label = "Insertions First") 
  
plt.xticks(rotation = 25) 
plt.xlabel('The number') 
plt.ylabel('The time') 
plt.title('Insertions', fontsize = 20) 
plt.grid() 
plt.legend() 

with open('TreeDsResults','r') as csvfile: 
    plots2 = csv.reader(csvfile, delimiter = ',') 
      
    for row in plots2: 
        x1.append(int(row[0])) 
        y1.append(int(row[1]))
  
plt.plot(y1, x1, color = 'r', linestyle = 'dashed', 
         marker = 'o',label = "Insertions Tree") 
  
plt.xticks(rotation = 25) 
plt.xlabel('The number') 
plt.ylabel('The time') 
plt.title('Insertions', fontsize = 20) 
plt.grid() 
plt.legend() 
plt.show() 
