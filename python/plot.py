import matplotlib.pyplot as plt
import csv
  
x1 = []
y1 = []
x2 = []
y2 = []
x3 = []
y3 = []
  
with open("/home/k/oar-apps1/java/playGround/src/testStuff/stringFiles/FirstDsResults",'r') as csvfile:
    plots = csv.reader(csvfile, delimiter = ',')
      
    for row in plots:
        x1.append(int(row[0]))
        y1.append(int(row[1]))
  
with open("/home/k/oar-apps1/java/playGround/src/testStuff/stringFiles/SecondDsResults",'r') as csvfile2:
    plots2 = csv.reader(csvfile2, delimiter = ',')
      
    for row in plots2:
        x2.append(int(row[0]))
        y2.append(int(row[1]))
  
  
with open("/home/k/oar-apps1/java/playGround/src/testStuff/stringFiles/FirstDsResults2",'r') as csvfile3:
    plots3 = csv.reader(csvfile3, delimiter = ',')
      
    for row in plots3:
        x3.append(int(row[0]))
        y3.append(int(row[1]))
  
plt.plot(x1, y1)
plt.plot(x2, y2)
plt.plot(x3, y3)
plt.xlabel('nelems')
plt.ylabel('timeus')
plt.title('Time complexity')
plt.legend()
plt.show()
